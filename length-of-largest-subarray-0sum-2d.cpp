// program to get Largest area rectangular sub-matrix with equal number of 1’s and 0’s

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>

int main(){
	int row,col;
	cin>>row>>col;
	vvi grid(row,vi(col,0));

	int p;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cin>>p;
			grid[i][j]=(p==0)?-1:1;
		}
	}

	vvi suffSum(row,vi(col,0));
	// compute the suffix sum array for the converted grid
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			suffSum[i][j]=(j>0)?suffSum[i][j-1]+grid[i][j]:grid[i][j];
		}
	}

	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<suffSum[i][j]<<" ";
		}
		cout<<endl;
	}


	// select the two boundaries for left and right
	// to select a vertical cross section of a grid

	vi temp(row,0);
	int gleft,gright,gtop,gbottom,garea;
	gleft=gright=gbottom=gtop=-1;
	garea=0;
	for(int left=0;left<col;left++){
		for(int right=col-1;right>=left;right--){

			// calculate and store the value of sum of elements
			// in the given cross-section row-wise

			for(int i=0;i<row;i++){
				temp[i]=(i>0)?suffSum[i][right]-suffSum[i][left-1]:suffSum[i][right];
			}

			// now we need to find the range for which sum becomes zero
			// this in turn is found be looking for a repeated value in the suffix sum
			// and getting the indices of repeated value
			unordered_map<int,int> recd;
			int maxLength,lbottom,ltop;
			maxLength=0;
			lbottom=ltop=0;
			int sumtillNow=0;
			for(int i=0;i<row;i++){
				sumtillNow+=temp[i];
				if(temp[i]==0 and maxLength==0){
					maxLength=1;
					ltop=i;
					lbottom=i;
				}
				if(sumtillNow==0){
					maxLength=i+1;
					ltop=0;
					lbottom=i;
				}
				if(recd.find(sumtillNow)!=recd.end()){
					if(maxLength<i-recd[sumtillNow]){
						maxLength=i-recd[sumtillNow];
						ltop=recd[sumtillNow]+1;
						lbottom=i;
					}
				}
				else{
					recd[sumtillNow]=i;
				}
			}
			int larea=(right-left+1)*maxLength;
			if(larea>garea){
				garea=larea;
				gleft=left;
				gright=right;
				gbottom=lbottom;
				gtop=ltop;
			}

		}
	}
	cout<<"(Top,Bottom) "<<gtop<<" , "<<gbottom<<endl;
	cout<<"(left,right) "<<gleft<<" , "<<gright<<endl;
}