// program to find bridge edges in a graph using tarjan's algorithm
// undirected unwieghted graph

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vpii vector<pii>
#define vi vector<int>
#define vvi vector<vi>

void dfsBridge(int u,vi &disc,vi &low,vi &parent,vvi &adj,vpii &ans){
	static int time=0;
	disc[u]=low[u]=time;
	time++;

	// recurse for all unvisited adjacent nodes
	for(auto v:adj[u]){
		if(disc[v]==-1){
			parent[v]=u;
			dfsBridge(v,disc,low,parent,adj,ans);
			low[u]=min(low[v],low[u]);

		}

		// condition to check for bridge edge
		if(low[v]>disc[u]){
			// bridge edge has been found
			ans.push_back(make_pair(u,v));
		}

		// if the adjacent node is already visited
		// there are two conditions either it is the parent
		// or it is back edge to some ancestor
		else if(parent[v]!=u){
			low[u]=min(low[u],disc[v]);
		}
	}
}

void printBridgeEdges(vvi &adj){
	int n=adj.size();
	vi parent(n,-1),disc(n,-1),low(n,-1);
	vpii ans;

	// perform dfs from each undiscovered node
	for(int i=0;i<n;i++){
		if(disc[i]==-1){
			dfsBridge(i,disc,low,parent,adj,ans);
		}
	}

	// print the bridge edges
	for(auto x:ans){
		cout<<x.first<<" "<<x.second<<endl;
	}
}

int main(){

	// number of vertices
	int N;
	cin>>N;

	// number of edges
	int edges;
	cin>>edges;

	// adjacency matrix
	vvi adj(N);

	// input edges
	int u,v;
	for(int i=0;i<edges;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// print the graph
	// for(int i=0;i<N;i++){
	// 	for(auto x:adj[i]){
	// 		cout<<i<<" "<<x<<endl;
	// 	}
	// }

	// call the function to print all the articulation points
	printBridgeEdges(adj);
}
