// In travelling salesman problem
// we basically have to find a hamiltonian cycle whoose wieght is lowest
// here graph is unwieghted undirected graph
// and is represented as adjacency matrix
// if an edge does not exist between two nodes
// then -1 is present there
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define gi greater<int>
#define vvi vector<vi>

void shortestHamiltonianCycle(int start_node,int curr_node,vi vis,vvi adj,int curr_wt,int &global_wt,int node_cnt){
	
	int v=adj.size();

	// base case
	// if a hamoltanian path is found
	// then check for hamoltonian cycle
	if(node_cnt==v){
		// check if there is an edge from curr node to first node
		if(adj[curr_node][start_node]!=-1){
			// update global wt if we get a better solution
			global_wt=min(global_wt,curr_wt+adj[curr_node][start_node]);
		}
		return ;
	}
	

	// optimization
	// here we have solved the problem assuming there are no
	// negative edges hence if curr_wt >=global_wt
	// we can leave the curr_case
	if(curr_wt>=global_wt)return;


	// recursive case

	// now we look at all the possible unvisited nodes
	// that can be reached from current node
	for(int i=0;i<v;i++){
		if(adj[curr_node][i]!=-11 and vis[i]==0){
			// try to find a hamoltonian path through this vertex

			// do 
			vis[i]=1;

			// recur
			shortestHamiltonianCycle(start_node,i,vis,adj,curr_wt+adj[curr_node][i],global_wt,node_cnt+1);

			// redo
			vis[i]=0;
		}
	}
	return ;
}

int main(){
	int tc;
	cin>>tc;
	while(tc--){
		int v;
		cin>>v;
		vector<vector<int>> adj(v,vi(v,0));
		for(int i=0;i<v;i++){
			for(int j=0;j<v;j++){
				cin>>adj[i][j];
			}
		}

		// look for the shortest path from given index
		// with starting from different positions
		vi vis(v,0);
		int curr_wt=0;
		int global_wt=INT_MAX;
		int node_cnt=0;
		for(int st_node=0;st_node<v;st_node++){
			// try to find hamoltonian cycle starting from st_node
			vis[st_node]=1;
			shortestHamiltonianCycle(st_node,st_node,vis,adj,curr_wt,global_wt,node_cnt+1);
			// path.pop_back();
			vis[st_node]=0;
		}
		cout<<global_wt<<endl;

	}
}