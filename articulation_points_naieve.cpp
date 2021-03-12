// program to find articulation point
// naieve implementation by removing a vertex
// and checking if graph still remains disconnected

// Time Complexity O(V*(V+E))

// undirected unwieghted graph

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vpii vector<pii>
#define vi vector<int>
#define vvi vector<vi>

vector<int> parent;
vector<int> size;

int find_set(int v){
	// to find the set in which element v is part of 
	if(v==parent[v])return v;
	return parent[v]=find_set(parent[v]);
}

void union_set(int a,int b){
	// to perform union of the set in which element a and b are present
	a=find_set(a);
	b=find_set(b);
	if(size[a]<size[b]){
		swap(a,b);
	}
	// size of a is bigger
	// adding set of smaller size b to a
	parent[b]=a;
	size[a]+=size[b];
}

// function to print all the articulation points in the graph
void printArticulationPoints(vvi &adj){
	// initialize the dsu
	int N=adj.size();
	parent.resize(N);

	// one by remove a point from the graph
	// and check if the graph becomes disconnected
	for(int probhitted=0;probhitted<N;probhitted++){
		cout<<"currently disconnecting vertix :"<<probhitted<<endl;
		int st_node=0;
		if(st_node==probhitted)st_node++;

		// perform bfs and try to reach all the nodes
		queue<int> q;
		vi vis(N,0);
		vis[st_node]=1;
		q.push(st_node);

		while(!q.empty()){
			int curr_node=q.front();
			q.pop();

			// traverse all the adjacent nodes
			// provided they are not equal to prohibitted node
			for(auto x:adj[curr_node]){
				if(x!=probhitted && !vis[x]){
					vis[x]=1;
					q.push(x);
				}
			}
		}

		// at the end if all the nodes are visited except prohibitted
		for(int i=0;i<N;i++){
			if(i!=probhitted and vis[i]==0){
				cout<<probhitted<<" is an articulation point\n";
				break;
			}
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
	printArticulationPoints(adj);
}
