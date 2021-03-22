// program to print euler path or euler circuit
// in a given graph
// using fleury's algorithm

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

// for a graph to have a euler path
// it must either be a euler graph or a semi euler graph

int DfsCount(int u,vvi &adj,vi &vis){
	int count=1;
	vis[u]=1;
	// recurse for all adjacent nodes
	for(auto v:adj[u]){
		if(v!=-1 and vis[v]==0){
			count+=DfsCount(v,adj,vis);
		}
	}
	return count;
}

void rmEdge(int u,int v,vvi &adj){
	// function to remove edge u-v from the graph
	// this is an undirected graph and is in the adjacency list representation

	// remove v from the ajacency list representation of u
	vi::iterator iv=find(adj[u].begin(), adj[u].end(),v);
	*iv=-1;

	// remove u from adjacency list representation of v
	vi::iterator iu=find(adj[v].begin(), adj[v].end(),u);
	*iu=-1;
}

bool validEdge(int u,int v,vvi &adj){
	// function to check if the edge u-v is valid

	int n=adj.size();
	// edge u-v is valid in two conditions
	// 1. if u-v is the last edge between u and v
	int edge_cnt=0;
	for(auto x:adj[u]){
		if(x!=-1)edge_cnt++;
	}
	if(edge_cnt==1)return true;

	// 2. if u-v is not the last edge and u-v is not a bridge edge

	// count number of connected nodes in dfs traversal before removing edge u-v
	// and compare it with number of connected nodes after removing edge u-v

	// before removing
	int count1=0;
	vi vis(n,0);
	count1=DfsCount(u,adj,vis);

	// remove edge
	rmEdge(u,v,adj);

	fill(vis.begin(),vis.end(),0);
	int count2=DfsCount(u,adj,vis);
	
	// add the edge back
	adj[u].push_back(v);
	adj[v].push_back(u);
	return (count1>count2)?false:true;
}

void printEulerUtil(int u,vvi &adj){
	// utility function to print euler path or ckt
	// by choosing and printing an edge from u to some v
	cout<<u<<" "<<adj[u].size()<<endl;
	for(auto v:adj[u]){
		cout<<u<<" "<<v<<" "<<adj[u].size()<<endl;
		for(auto v:adj[u]){
			cout<<v<<" ";
		}
		cout<<endl;
		if(v!=-1 and validEdge(u,v,adj)){
			cout<<u<<"-"<<v<<"\n";
			cout<<"vertices in u\n";
			for(auto x:adj[u]){
				cout<<x<<" ";
			}
			cout<<endl;
			cout<<"vertices in v\n";
			for(auto x:adj[v]){
				cout<<x<<" ";
			}
			cout<<endl;
			rmEdge(u,v,adj);
			rmEdge(u,v,adj);

			cout<<"vertices in u\n";
			for(auto x:adj[u]){
				cout<<x<<" ";
			}
			cout<<endl;
			cout<<"vertices in v\n";
			for(auto x:adj[v]){
				cout<<x<<" ";
			}
			cout<<endl;
			printEulerUtil(v,adj);
		}
	}
	cout<<"exitting\n";
}

void printEuler(vvi &adj){
	// function to print euler path or ckt
	// cout<<"inside euler\n";
	int n=adj.size();
	// find the starting node (in case of euler path)
	int st=0;
	for(int i=0;i<n;i++){
		if(adj[i].size()&1){
			st=i;
			break;
		}
	}
	cout<<"Euler is fine\n";
	// cout<<st<<endl;
	printEulerUtil(st,adj);
}

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
		printEuler(adj);
		cout<<endl;
		return 1;
	}
	printEuler(adj);
	cout<<endl;
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
