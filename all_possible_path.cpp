// program to print all possible path from ,
// to m-,n-1
// link:https://www.geeksforgeeks.org/print-all-possible-paths-from-top-left-to-bottom-right-of-a-mxn-matrix/
#include <bits/stdc++.h>
using namespace std;
# define vi vector<int>
# define vvi vector<vi>

void backtrack(int row,int col,int m,int n,vvi &grid,vi &path){
	// base case
	// we reach m-1,n-1 cords
	if(row==m-1 && col==n-1){
		// print the path
		for(auto x:path){
			cout<<x<<" ";
		}
		cout<<endl;
		return;
	}
	
	// recursive case
	// bottom cell
	if(row+1<m){
		path.push_back(grid[row+1][col]);
		backtrack(row+1,col,m,n,grid,path);
		path.pop_back();
	}
	if(col+1<n){
		path.push_back(grid[row][col+1]);
		backtrack(row,col+1,m,n,grid,path);
		path.pop_back();
	}
	return;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int m,n;
		cin>>m>>n;
		vvi grid(m,vi(n));
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>grid[i][j];
			}
		}
		vi path;
		path.push_back(grid[0][0]);
		backtrack(0,0,m,n,grid,path);
	}
}
