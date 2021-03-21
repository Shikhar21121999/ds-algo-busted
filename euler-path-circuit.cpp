// program to identify if graph is a euler graph
// semilerian graph or none of these

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
#define minpq priority_queue<int,vi,greater<int>>
#define space " "

void dfs(int curr_node,vvi &adj,vi &vis){
	// perform dfs to mark all the nodes in the connected component
	cout<<"curr node is :"<<curr_node<<endl;
	vis[curr_node]=1;
	for(auto x:adj[curr_node]){
		if(vis[x]==0){
			dfs(x,adj,vis);
		}
	}
}

bool multiConnectedGraph(vvi &adj){
	// function to check if the graph contains multiple connected component
	
	int n=adj.size();
	vi vis(n,0);
	int conn_node=-1;		// to check if a connected component is found
	for(int i=0;i<n;i++){
		if(adj[i].size()>0){
			// found a node from which dfs can be performed
			// to mark the connected component
			conn_node=i;
			dfs(i,adj,vis);
			break;
		}
	}

	if(conn_node==-1){
		// implies that all the nodes are individual
		// and no edge exist between any of the node
		// such a graph is always eulerian
		return 0;
	}

	for(int i=0;i<n;i++){
		cout<<i<<" "<<vis[i]<<endl;
	}

	// otherwise a connected component exist and we have marked it
	for(int i=0;i<n;i++){
		if(vis[i]==0 and adj[i].size()>1){
			// if any node that is not part of the connected component
			// and has an edge is found then this is not a eulerian graph
			// not even semi eulerian graph
			cout<<i<<" "<<adj[i].size()<<endl;
			return 1;
		}
	}
	return 0;
}

int eulerGraphType(vvi &adj){
	int n=adj.size();
	// first we need to check if all the nodes that have degree
	// greater than 1 lie in the same connected component
	if(multiConnectedGraph(adj)){
		cout<<"multiple connected graph"<<endl;
		return 0;
	}

	// now graph only has a single connected component
	// in which degree are greater than 1
	// rest all the nodes of the graph have degree equal to 0

	// now we check the nodes in the connected component
	// that is how many of the nodes have degree as odd

	int oddDegCnt=0;
	for(int i=0;i<n;i++){
		if(adj[i].size()&1){
			oddDegCnt++;
		}
	}

	if(oddDegCnt>2){
		// not a euler and not a semi euler graph
		return 0;
	}
	if(oddDegCnt==2){
		// a semi euler graph
		return 1;
	}
	return 2;
}

int main(){
	int n,m;
	cin>>n>>m;
	vvi adj(n);
	int u,v;
	vi temp(3);
	for(int i=0;i<m;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	cout<<"prinitng the graph\n";
	for(int i=0;i<n;i++){
		for(auto x:adj[i]){
			cout<<i<<" "<<x<<endl;
		}
	}


	int graph_type=eulerGraphType(adj);
	if(graph_type==0){
		cout<<"graph is not a euler graph"<<endl;
	}
	else if(graph_type==1){
		cout<<"graph is a semi eulerian graph"<<endl;
	}
	else{
		cout<<"euler graph"<<endl;
	}
	return 0;
}
