// program to find articluation point using tarjan's algorithm
// undirected unwieghted graph

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vpii vector<pii>
#define vi vector<int>
#define vvi vector<vi>

// function to perform dfs and check if a node is articluation point
void dfsArticluationPoint(int u,vi &disc,vi &low,vi &is_ap,vvi &adj,vi &parent){
	static int time=0;
	int children=0;
	disc[u]=low[u]=time;
	time++;

	// traverse all the unvisited children of this node
	for(auto v:adj[u]){
		if(disc[v]==-1){
			parent[v]=u;
			children++;
			dfsArticluationPoint(v,disc,low,is_ap,adj,parent);

			// ancestor of current is the oldest ancestor
			// of itself or the children
			low[u]=min(low[u],low[v]);

			// check for articluation point
			// condition 1
			// u is a root node and number of children>1
			if(parent[u]==-1 and children>1){
				is_ap[u]=1;
			}

			// condition 2
			// u is not a root node and a node v does not
			// have an ancestor which is older than current node
			if(parent[u]!=-1 and low[v]>disc[u]){
				is_ap[u]=1;
			}
		}
		// the adjacent node is already visited
		// two posibillities either a back edge to node itself
		// or a back edge to previous ancestor
		else if(v!=parent[u]){
			low[u]=min(low[u],disc[v]);
		}
	}

}

// abstract function to print articulation point
void printArticulationPointsTarjan(vvi &adj){
	// disct to store discovery time
	// low to store oldest ancestor of a node not parent
	// is_app to store wether a node is articulation point or not
	int n=adj.size();
	vi disc(n,-1),low(n,-1),is_ap(n,0);
	vi parent(n,-1);
	for(int i=0;i<n;i++){
		if(disc[i]!=-1){
			dfsArticluationPoint(i,disc,low,is_ap,adj,parent);
		}
	}

	// print all the articluation points
	for(int i=0;i<n;i++){
		if(is_ap[i]==1){
			cout<<i<<" is an articluation points\n";
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
	printArticulationPointsTarjan(adj);
}
