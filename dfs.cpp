// program to perform dfs on a graph

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

// a global graph
vector <vector <pair <int,int> > > adj;
vector <int> vis;

void dfs(int a){
	// here a denotes the vertex number
	// we perform dfs starting from index a
	
	for(auto x:adj[a]){
		if(vis[x.first]==0)dfs(x.first);
	}
	return;
}

void solve(){
	// abstract program to call dfs on a graph
	
	// input no of vertex and edge
	int v,e;
	cin>>v>>e;
	
	// resize adjacency representation of graph
	adj.resize(v+1);
	vis.resize(v+1,0);
	
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
	
	
	
	// calling dfs on all nodes if unvisited 
	// considering that a graph may have disconnected componenets
	
	for(int i=1;i<=v;i++){
		if(vis[i]==0)dfs(i);
	}
	
	for(int i=1;i<=v;i++){
		cout<<vis[i]<<"\n";
	}
}

int main(){
	solve();
}

