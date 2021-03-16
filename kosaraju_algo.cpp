// program to print strongly connected components
// in an undirected acyclic graph
// using kosaraju algorithm

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vpii vector<pii>
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define si stack<int>

// function to find transpose of a graph
vvi reverse(vvi &adj,vvi &rev){
	int n=adj.size();
	// vvi rev(n);
	for(int i=0;i<n;i++){
		for(auto j:adj[i]){
			rev[j].push_back(i);
		}
	}

	return rev;
}

void dfs1(int u,vb &vis,vvi &adj,si &s){
	vis[u]=true;
	for(auto v:adj[u]){
		if(!vis[v]){
			dfs1(v,vis,adj,s);
		}
	}
	s.push(u);
}

void dfs2(int u,vb &vis,vvi &rev,si &s){
	cout<<u<<" ";
	// perform dfs on all the adjacent nodes
	for(auto v:rev[u]){
		if(!vis[v]){
			dfs2(v,vis,rev,s);
			cout<<endl;
		}
	}
}

void find_scc_kosaraju(vvi &adj){
	int n=adj.size();
	si s;
	vb vis(n,false);

	// perform first dfs
	for(int i=0;i<n;i++){
		if(!vis[i]){
			dfs1(i,vis,adj,s);
		}
	}

	// get the transpose of the graph
	vvi rev(n);
	reverse(adj,rev);

	// make the vis array false again
	for(int i=0;i<n;i++){
		vis[i]=false;
	}

	// pop items from stack and do dfs
	while(!s.empty()){
		int curr=s.top();
		s.pop();
		if(!vis[curr]){
			dfs2(curr,vis,rev,s);
			cout<<endl;
		}
	}

}

int main(){

	// number of vertices
	int N;
	cin>>N;

	// number of edges
	int edges;
	cin>>edges;

	// adjacency graph represenntation
	vvi adj(N);

	// input edges
	int u,v;
	for(int i=0;i<edges;i++){
		cin>>u>>v;
		adj[u].push_back(v);
	}

	// print the graph
	for(int i=0;i<N;i++){
		for(auto x:adj[i]){
			cout<<i<<" "<<x<<endl;
		}
	}

	// call the function to print all the articulation points
	find_scc_kosaraju(adj);
}
