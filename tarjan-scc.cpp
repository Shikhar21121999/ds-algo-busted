// program to print strongly connected components
// in an undirected acyclic graph

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vpii vector<pii>
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define si stack<int>

void dfs_scc(int u,vi &disc,vi &low,vb &in_stack,si &s,vvi &adj){
	static int time=0;
	disc[u]=low[u]=time;
	time++;
	s.push(u);
	in_stack[u]=true;

	// analyze all the adjacent edges
	for(auto v:adj[u]){
		if(disc[v]==-1){
			dfs_scc(v,disc,low,in_stack,s,adj);
		}
		// if v is in stack or in the dfs path
		// then v 
		if(in_stack[v]){
			low[u]=min(low[u],low[v]);
		}
	}

	if(low[u]==disc[u]){
		cout<<"Scc is :";
		while(s.top()!=u){
			cout<<s.top()<<" ";
			in_stack[s.top()]=false;
			s.pop();
		}
		cout<<s.top()<<endl;
		in_stack[s.top()]=false;
		s.pop();
	}
}

// abstract function to find strongly connected components
// in a graph
void find_scc_tarjan(vvi &adj){
	int n=adj.size();
	vi disc(n,-1),low(n,-1);
	vb in_stack(n,false);
	si s;

	// if some component of graph is not connected
	// we have to call the function on all the disconnected components
	for(int i=0;i<n;i++){
		if(disc[i]==-1){
			dfs_scc(i,disc,low,in_stack,s,adj);
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
	}

	// print the graph
	for(int i=0;i<N;i++){
		for(auto x:adj[i]){
			cout<<i<<" "<<x<<endl;
		}
	}

	// call the function to print all the articulation points
	find_scc_tarjan(adj);
}
