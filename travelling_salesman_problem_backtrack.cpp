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

// start node
// curr_node
// vis
// curr_wt
// global_wt
// curr_path
// global path
// adj
void shortestHamiltonianCycle(int start_node,int curr_node,int curr_wt,int &global_wt,vi curr_path,vi &global_path,vi &vis,vvi &adj){
	
	// Total vertices
	int v=adj.size();

	// Current no of vetices
	int n=curr_path.size();

	// base case
	// if a hamoltanian path is found
	// then check for hamoltonian cycle
	if(n==v){
		// check if there is an edge from curr node to first node
		if(adj[curr_node][start_node]!=-1){
			// Hamoltonian cycle exist
			// check if wt of this path is less than global path
			if(curr_wt+adj[curr_node][start_node]<global_wt){
				// we need to store this path as the optimal path
				// and also update global wt
				global_path.clear();
				for(auto x:curr_path){
					global_path.push_back(x);
				}
				global_path.push_back(start_node);
				global_wt=curr_wt+adj[curr_node][start_node];
			}
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
		if(adj[curr_node][i]!=-1 and vis[i]==0){
			// try to find a hamoltonian path through this vertex

			// do 
			vis[i]=1;
			curr_path.push_back(i);
			curr_wt+=adj[curr_node][i];

			// recur
			shortestHamiltonianCycle(start_node,i,curr_wt,global_wt,curr_path,global_path,vis,adj);

			// redo
			vis[i]=0;
			curr_path.pop_back();
			curr_wt-=adj[curr_node][i];
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
		vector<vector<int>> adj(v,vi(v,-1));
		int e;
		cin>>e;
		int a,b,c;
		for(int i=0;i<e;i++){
			cin>>a>>b>>c;
			adj[a][b]=c;
			adj[b][a]=c;
		}
		for(int i=0;i<v;i++){
			for(int j=0;j<v;j++){
				cout<<adj[i][j]<<" ";
			}
			cout<<endl;
		}

		// look for the shortest path from given index
		// with starting from different positions
		vi vis(v,0);
		vi curr_path;
		vi global_path;
		int curr_wt=0;
		int global_wt=INT_MAX;
		for(int st_node=0;st_node<v;st_node++){
			// try to find hamoltonian cycle starting from st_node
			vis[st_node]=1;
			curr_path.push_back(st_node);
			shortestHamiltonianCycle(st_node,st_node,curr_wt,global_wt,curr_path,global_path,vis,adj);
			curr_path.pop_back();
			vis[st_node]=0;
		}
		cout<<"minimum path length for hamoltonian cycle is :"<<global_wt<<endl;
		// printing the path
		for(auto x:global_path){
			cout<<x<<" ";
		}
		cout<<endl;

	}
}