// program to detect cycle in a directed graph
// link:https://www.geeksforgeeks.org/detect-cycle-in-a-graph/

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vpii>

// use dfs to detect cycle
void dfs(int node,vvpii &adj,bool &cycle,vi &vis){
	if(cycle)return;
	
	// perform dfs on the current node
	for(auto x:adj[node]){
		if(vis[x.first]){
			cycle=true;
		}
		else{
			vis[x.first]=true;
			dfs(x.first,adj,cycle,vis);
		}
	}
	return;
}


bool is_cyclic(vvpii &adj,int v){
	// function to check if the graph is cyclic or not
	
	vi vis(v,0);
	bool cycle=false;
	for(int i=0;i<v;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(i,adj,cycle,vis);
		}
	}
	return cycle;
			
}
	

void input_adj_graph(){
	// input no of vertex and edge
	int v,e;
	cin>>v>>e;
	
	// adjacency list representation of graph
	vvpii adj(v+1);
	
	// take in e edges
	int v1,v2,edg;
	for(int i=0;i<e;i++){
		cin>>v1>>v2>>edg;
		adj[v1].push_back(make_pair(v2,edg));	
	}
	
	// printing the generated graph
	for(int i=1;i<=v;i++){
		for(auto x:adj[i]){
			cout<<i<<"\t"<<x.first<<"\t"<<x.second<<"\n";
		}
	}
	cout<<is_cyclic(adj,v);
}

int main(){
	input_adj_graph();
}
