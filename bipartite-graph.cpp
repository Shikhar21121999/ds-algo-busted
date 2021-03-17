// program to check wether a graph is bipartite or not

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vpii vector<pii>
#define vi vector<int>
#define vvi vector<vi>

// to check if the graph is bipartite or not
bool is_bipartite(vvi &adj){
	// here -1 represent an unvisited node
	// 0 and 1 represent different color
	int n=adj.size();
	vi color(n,-1);
	
	queue <int> q;
	color[0]=0;
	q.push(0);

	while(!q.empty()){
		int curr_node=q.front();
		q.pop();

		// color all the adjacent nodes with different color
		for(auto x:adj[curr_node]){
			if(color[x]!=-1 and color[curr_node]==color[x]){
				return false;
			}
			if(color[x]==-1){
				color[x]=!color[curr_node];
				q.push(x);
			}
		}
	}
	return true;
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
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// // print the graph
	// for(int i=0;i<N;i++){
	// 	for(auto x:adj[i]){
	// 		cout<<i<<" "<<x<<endl;
	// 	}
	// }

	// call the function to print all the articulation points
	cout<<is_bipartite(adj)<<endl;
}