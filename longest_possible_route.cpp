// program to find longest possible route in a matrix with hurdles
// link:https://www.geeksforgeeks.org/longest-possible-route-in-a-matrix-with-hurdles/

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vi vector <int>
#define vvi vector <vi>
int m,n;

bool is_safe(pii cord,vvi &grid,vvi &vis){
	return (cord.first>=0 && cord.first<m && cord.second>=0 && cord.second<n&&
			!vis[cord.first][cord.second] && grid[cord.first][cord.second]==1);
}

void backtrack(int row,int col,int path_len,vvi &grid,vvi &vis,int *max_len,int dest_row,int dest_col){
	
	if(row==dest_row && col==dest_col){
		*max_len=max(*max_len,path_len);
		return;
	}
	// 4 possible cords
	// cout<<row<<" "<<col<<" "<<path_len<<endl;
	pii top=make_pair(row-1,col);
	pii bottom=make_pair(row+1,col);
	pii left=make_pair(row,col-1);
	pii right=make_pair(row,col+1);
	
	if(is_safe(top,grid,vis)){
		// do
		vis[top.first][top.second]=1;
		path_len+=1;
		// recur
		backtrack(top.first,top.second,path_len,grid,vis,max_len,dest_row,dest_col);
		// redo
		vis[top.first][top.second]=0;
		path_len-=1;
	}
	if(is_safe(bottom,grid,vis)){
		// do
		vis[bottom.first][bottom.second]=1;
		path_len+=1;
		// *max_len=max(*max_len,path_len);
		// recur
		backtrack(bottom.first,bottom.second,path_len,grid,vis,max_len,dest_row,dest_col);
		// redo
		vis[bottom.first][bottom.second]=0;
		path_len-=1;
	}
	if(is_safe(left,grid,vis)){
		// do
		vis[left.first][left.second]=1;
		path_len+=1;
		// *max_len=max(*max_len,path_len);
		// recur
		backtrack(left.first,left.second,path_len,grid,vis,max_len,dest_row,dest_col);
		// redo
		vis[left.first][left.second]=0;
		path_len-=1;
	}
	if(is_safe(right,grid,vis)){
		// do
		vis[right.first][right.second]=1;
		path_len+=1;
		// *max_len=max(*max_len,path_len);
		// recur
		backtrack(right.first,right.second,path_len,grid,vis,max_len,dest_row,dest_col);
		// redo
		vis[right.first][right.second]=0;
		path_len-=1;
	}
}

int main(){
	cin>>m>>n;
	
	vvi matr(m,vi(n));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>matr[i][j];
		}
	}
	
	vvi vis(m,vi(n,0));
	int source_row,source_col,dest_row,dest_col;
	cin>>source_row>>source_col>>dest_row>>dest_col;
	vis[source_row][source_col]=1;
	int max_len=0;
	backtrack(0,0,0,matr,vis,&max_len,dest_row,dest_col);
	cout<<max_len<<endl;
}
