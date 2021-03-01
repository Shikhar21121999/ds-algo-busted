// program to find the shortest route in a path filled with landmines
// link:https://www.geeksforgeeks.org/find-shortest-safe-route-in-a-path-with-landmines/

#include <bits/stdc++.h>
using namespace std;
# define vi vector <int>
# define vvi vector <vi>
# define pii pair<int,int>
# define vb vector<bool>
# define vvb vector <vb>

bool is_inside(int row,int col,int r,int c){
	// to check if the coordinate lies inside row and column
	return (row>=0 && col>=0 && row<r && col<c);
}

bool is_safe(pii point,const vvi &path,int r,int c,vvb vis){
	// to check if its is safe to go in this cell
	// that is the cell is both inside the grid and is visitable
	if(is_inside(point.first,point.second,r,c) && 
		path[point.first][point.second]==1 && 
		!vis[point.first][point.second])return true;
	return false;
}

bool backtrack(int row,int col,const vvi &path,int path_len,int* short_path,int r,int c,vvb &vis){
	// base case
	if(col==c-1 && path_len<*short_path){
		*short_path=path_len;
		return true;
	}
	
	// recurse case
	// there are four possible directions
	pii top=make_pair(row-1,col);
	pii bottom=make_pair(row+1,col);
	pii left=make_pair(row,col-1);
	pii right=make_pair(row,col+1);
	
	if(is_safe(top,path,r,c,vis)){
		vis[top.first][top.second]=true;
		backtrack(top.first,top.second,path,path_len+1,short_path,r,c,vis);
		vis[top.first][top.second]=false;
	}
	if(is_safe(bottom,path,r,c,vis)){
		vis[bottom.first][bottom.second]=true;
		backtrack(bottom.first,bottom.second,path,path_len+1,short_path,r,c,vis);
		vis[bottom.first][bottom.second]=false;
	}
	if(is_safe(left,path,r,c,vis)){
		vis[left.first][left.second]=true;
		backtrack(left.first,left.second,path,path_len+1,short_path,r,c,vis);
		vis[left.first][left.second]=false;
	}
	if(is_safe(right,path,r,c,vis)){
		vis[right.first][right.second]=true;
		backtrack(right.first,right.second,path,path_len+1,short_path,r,c,vis);
		vis[right.first][right.second]=false;
	}
}

int main(){
	int r,c;
	cin>>r>>c;
	
	// input the path
	vvi path(r,vi(c,0)),mod_path(r,vi(c,0));
	vvb vis(r,vb(c,false));
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>path[i][j];
			mod_path[i][j]=path[i][j];
		}
	}
	
	// modify the path to represent all the unsafe positions with 0
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(path[i][j]==0){
				// make top,bottom,left and right as 0
				// top
				if(is_inside(i-1,j,r,c)){
					mod_path[i-1][j]=0;
				}
				// bottom
				if(is_inside(i+1,j,r,c)){
					mod_path[i+1][j]=0;
				}
				// left
				if(is_inside(i,j-1,r,c)){
					mod_path[i][j-1]=0;
				}
				// right
				if(is_inside(i,j+1,r,c)){
					mod_path[i][j+1]=0;
				}
			}
		}
	}
	// print the modified path
	
	int short_path=INT_MAX;
	// call the function on all the coords of first row
	bool ans=false;
	for(int i=0;i<r;i++){
	 	if(mod_path[i][0]==1){
			vis[i][0]=true;
	 		ans=backtrack(i,0,mod_path,0,&short_path,r,c,vis)||ans;
	 		vis[i][0]=false;
	 	}
	}
	// vis[2][2]=true;
	// ans=backtrack(2,0,mod_path,0,&short_path,r,c,vis);
	cout<<short_path<<endl;
}
	
	
				
