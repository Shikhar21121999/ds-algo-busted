// program to solve maximum sum rectange in a 2d matrix

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>

int maxSum(vvi grid,int row,int col){

	// check for base case and construct a suffix sum grid
	// for the grid elements
	vvi suffSum(row,vi(col,0));

	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			suffSum[i][j]=(j==0)?grid[i][j]:suffSum[i][j-1]+grid[i][j];
		}
	}

	int gridMax=0;
	for(int left=0;left<col;left++){
		for(int right=col-1;right>=left;right--){
			// now we have vertically divided the grid by left and right
			// column indices
			// making an array that represent the sum of elements in the given
			// vertical division of each row
			vi temp(row,0);
			for(int i=0;i<row;i++){
				temp[i]=(left==0)?suffSum[i][right]:suffSum[i][right]-suffSum[i][left-1];
			}
			// if(left==5 and right==5){
			// 	for (int i = 0; i < row; ++i)
			// 	{
			// 		cout<<suffSum[i][right]<<" "<<suffSum[i][left-1]<<" "<<temp[i]<<" "<<endl;
			// 	}
			// }

			// // apply kadane's algo to find the max sum int the temp row
			int endSofar=0;
			int maxOverall=INT_MIN;
			for(int i=0;i<row;i++){
				endSofar=endSofar+temp[i];
				if(endSofar>maxOverall){
					maxOverall=endSofar;
				}
				if(endSofar<0){
					endSofar=0;
				}
			}
			if(maxOverall>gridMax){
				gridMax=maxOverall;
			}
		}
	}
	return gridMax;
}

int main(){
	int row,col;
	cin>>row>>col;
	vvi grid(row,vi(col,0));
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cin>>grid[i][j];
		}
	}
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<maxSum(grid,row,col)<<endl;
}