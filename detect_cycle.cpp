// program to detect cycle in a graph
// link:https://www.geeksforgeeks.org/detect-cycle-in-a-graph/

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>

void dfs()

bool is_cyclic(vpii &adj,int v){
	// function to check if the graph is cyclic or not
	
	vi vis(v,0);
	for(int i=0;i<v;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(adj,i);
		}
	}
			
}
	

void solve(){
	// input no of vertex and edge
	int v,e;
	cin>>v>>e;
	
	// adjacency list representation of graph
	vpii adj(v+1);
	
	// take in e edges
	int v1,v2,edg;
	for(int i=0;i<v;i++){
		cin>>v1>>v2>>edg;
		adj[v1].push_back(make_pair(v2,edg));	
	}
	
	// printing the generated graph
	for(int i=1;i<=v;i++){
		for(auto x:adj[i]){
			cout<<i<<"\t"<<x.first<<"\t"<<x.second<<"\n";
		}
	}
}

int main(){
	solve();
}
