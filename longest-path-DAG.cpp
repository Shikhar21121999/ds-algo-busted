// program to find the longest path
// from one node to all
// in an directed wieghted acyclic graph

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector <vpii>
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define si stack<int>
#define ll long long
#define vll vector<ll>

void toposortUtil(int i,vvpii &adj,vi &vis,si &s){
	// cout<<i<<" ";
	// visit all the unvisited nodes in the dfs call of the current node
	// and push them in the stack
	for(auto x:adj[i]){
		if(vis[x.first]==0){
			vis[x.first]=1;
			toposortUtil(x.first,adj,vis,s);
			// cout<<"pushing "<<x.first<<"in stack"<<endl;
			s.push(x.first);
		}
	}
	return;
}

// shortest path between source to all nodes
void shortest_path(vvpii &adj,int source){
	int n=adj.size();
	vll ld(n,-INT_MAX);

	// find topological sorting of the graph
	si s;
	vi vis(n,0);
	ld[source]=0;
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			vis[i]=1;
			toposortUtil(i,adj,vis,s);
			s.push(i);
		}
	}

	// at the end we have topological sorting of the current graph
	// cout<<"prinitng stack\n";
	// while(!s.empty()){
	// 	cout<<s.top()<<" ";
	// 	s.pop();
	// }

	// no we process every node from the topo sort and process them
	// to relax sd to all the adjacent edges
	while(!s.empty()){
		int curr_node=s.top();
		s.pop();

		for(auto x:adj[curr_node]){
			// cout<<"relaxing edge "<<curr_node<<" "<<x.first<<endl;
			ld[x.first]=max(ld[x.first],ld[curr_node]+x.second);
		}
	}

	// print the shortest distance for all
	cout<<"shortest distance of all from source are";
	for(int i=0;i<n;i++){
		cout<<ld[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int n,m;
	cin>>n>>m;
	vvpii adj(n);
	int u,v,e;
	for(int i=0;i<m;i++){
		cin>>u>>v>>e;
		adj[u].push_back(make_pair(v,e));
	}
	int source;
	cin>>source;

	shortest_path(adj,source);
	return 0;
	// adj[i]=> {j,k},{p,k},{q.s}
}
