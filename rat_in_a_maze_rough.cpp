// program to solve rat in a maze problem
// we take a grid as an input and we have to print all the possible paths
// that can be taken to reach n-1*n-1 coord if mouse is standing at 0,0
// Link:https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1


#include <bits/stdc++.h>
using namespace std;
# define vvi vector < vector < int > >
# define vs vector <string>
# define pii pair<int,int>

bool is_allowed(int i,int j,vvi &vis,vvi &m,int n){
	if(i>=n || j>=n || i<0 || j<0)return false;
	// check if this coordinate is visitable
	if(vis[i][j]==0 and m[i][j]!=0){
		return true;
	}
	return false;
}


void backtrack(int i,int j,string prev_path,vs &ans,vvi &vis,vvi &m,int n){
	
	
	// base case
	if(i==n-1 and j==n-1){
		// we have reached the end of the graph
		ans.push_back(prev_path);
		return;
	}
	
	// recursive case
	// we need to test for all the 4 directions
	
	pii left=make_pair(i,j-1);
	pii right=make_pair(i,j+1);
	pii top=make_pair(i-1,j);
	pii bottom=make_pair(i+1,j);
	// cout<<i<<" "<<j<<endl;
	// cout<<"top:"<<top.first<<" "<<top.second<<endl;
	// cout<<"bottom:"<<bottom.first<<" "<<bottom.second<<endl;
	// cout<<"left:"<<left.first<<" "<<left.second<<endl;
	// cout<<"right:"<<right.first<<" "<<right.second<<endl;
	
	char dir;
	// check each coords to be visitable
	if(is_allowed(top.first,top.second,vis,m,n)){
		// we can go to the above coord
		
		// do
		dir='T';
		prev_path+=dir;
		vis[top.first][top.second]=1;
		// recur
		backtrack(top.first,top.second,prev_path,ans,vis,m,n);
		// undo
		prev_path.erase(prev_path.length()-1);
		vis[top.first][top.second]=0;
	}
	if(is_allowed(bottom.first,bottom.second,vis,m,n)){
		// we can go to the bottom coord
		
		// do 
		dir='D';
		prev_path+=dir;
		vis[bottom.first][bottom.second]=1;
		// recur
		backtrack(bottom.first,bottom.second,prev_path,ans,vis,m,n);
		// undo
		prev_path.erase(prev_path.length()-1);
		vis[bottom.first][bottom.second]=0;
	}
	if(is_allowed(left.first,left.second,vis,m,n)){
		// we can go to the left coord
		
		// do 
		dir='L';
		prev_path+=dir;
		vis[left.first][left.second]=1;
		// recur
		backtrack(left.first,left.second,prev_path,ans,vis,m,n);
		// undo
		prev_path.erase(prev_path.length()-1);
		vis[left.first][left.second]=0;
	}
	if(is_allowed(right.first,right.second,vis,m,n)){
		// we can go to the right coord
		
		// do 
		dir='R';
		prev_path+=dir;
		vis[right.first][right.second]=1;
		// recur
		backtrack(right.first,right.second,prev_path,ans,vis,m,n);
		// undo
		prev_path.erase(prev_path.length()-1);
		vis[right.first][right.second]=0;
	}
}

vs findPath(vvi &m,int n){
	// create ans string
	vs ans;
	vvi vis(n,vector <int>(n,0));
	string prev_path="";
	vis[0][0]=1;
	backtrack(0,0,prev_path,ans,vis,m,n);
	return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector <vector <int> > m(n,vector <int> (n,0));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>m[i][j];
			}
		}
		vector <string> result=findPath(m,n);
		if(result.size()==0)cout<<-1;
		else{
			for(auto x:result){
				cout<<x<<" ";
			}
		}
	}
	return 0;
}
