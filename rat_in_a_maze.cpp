// program to solve rat in a maze problem
// we take a grid as an input and we have to print all the possible paths
// that can be taken to reach n-1*n-1 coord if mouse is standing at 0,0
// Link:https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include <bits/stdc++.h>
using namespace std;

bool is_allowed(int i,int j,vector <vector <int> >&vis,vector <vector <int> > &m){
	// check if this coordinate is visitable
	if(i<n and j<n and vis[i][j]==0 and m[i][j]!=0)return true;
	return false;
}

void backtrack(int i,int j,vector <vector <int> >&m,vector <vector <int> > &vis){
	// base case
	if(i==n-1 and j==n-1){
		// add the string to the ans string
		 

class Solution{
	public:
	vector <string> findPath(vector <vector <int> >&m,int n){
		// create ans string
		vector <string> ans;
		vector <vector <int> > vis(n,vector <int>(n,0);
		backtrack(0,0,m,ans,vis);
		return ans;
	}
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
				cin>>m[i];
			}
		}
		Solution obj;
		vector <string> result=obj.findPath(m,n);
		if(result.size()==0)cout<<-1;
		else{
			for(auto x:result){
				cout<<x<<" ";
			}
		}
	}
	return 0;
}
