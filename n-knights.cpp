// program to solve n-knights problem using backtracking
// we are given an integer n
// and we have to print all the possibilites in which n knights 
// can be kept on a nXn board 
// and ensure that all are alive

#include <bits/stdc++.h>
using namespace std;

vector <pair <int,int> > knights_coords;

bool is_knightsafe(int i,int j){
	// a knight has 8 hit boxes
	// let knight be kept at coor p,q then its hitboxes are
	// p+2,q-1	p+2,q+1
	// p-2,q-1  p-2,q+1
	// p+1,q-2	p+1,q+2
	// p-1,q-2 	p-1,q+2
	for(auto a:knights_coords){
		int x=a.first;
		int y=a.second;
		bool c1=(i==x+2) and (j==y-1);
		bool c2=(i==x+2) and (j==y+1);
		bool c3=(i==x-2) and (j==y-1);
		bool c4=(i==x-2) and (j==y+1);
		bool c5=(i==x+1) and (j==y-2);
		bool c6=(i==x+1) and (j==y+2);
		bool c7=(i==x-1) and (j==y-2);
		bool c8=(i==x-1) and (j==y+2);
		bool c9=(i==x) and (j==y);
		if(c1 || c2 || c3 || c4 || c5 || c6 || c7 || c8 || c9){
			return false;
		}
	}
	return true;
}

void backtrack(int chosn,int n,int row,int col){
	
	// base case
	// n nights have been kept sucessfully
	if(chosn==n){
		// cout<<knights_coords.size()<<endl;
		vector <vector <int> > grid(n,vector <int> (n,0));
		for(auto x:knights_coords){
			grid[x.first][x.second]=1;
		}
		
		// print the grid
		cout<<"One possible arrangement is\n";
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<grid[i][j]<<" ";
			}
			cout<<"\n";
		}
		return;
	}
	
	// recursive case
	// try to keep another knight in rest of the array
	for(int i=row;i<n;i++){
		for(int j=col;j<n;j++){
			if(is_knightsafe(i,j)){
				// add the coords of this knight to the vector
				// do
				knights_coords.push_back(make_pair(i,j));
				// recur
				backtrack(chosn+1,n,i,j);
				// redo or restore
				knights_coords.pop_back();
			}
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		backtrack(0,n,0,0);
	}
}
