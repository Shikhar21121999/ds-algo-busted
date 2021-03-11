// program to find presence of hamoltanian cycle
// and print a hamoltanian cycle
// here graph is unwieghted undirected graph
// and is represented as adjacency matrix


#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define gi greater<int>
#define vvi vector<vi>

bool is_hamoltoniancycle(int start_node,int curr_node,vi &path,vi vis,vvi adj){
	
	int v=adj.size();

	// base case
	// if a hamoltanian path is found
	// then check for hamoltonian cycle
	if(path.size()==v){
		// check if there is an edge from curr node to first node
		if(adj[curr_node][start_node]==1){
			cout<<"Cycle exists and the cycle is : ";
			for(auto x:path){
				cout<<x<<" ";
			}
			cout<<start_node<<endl;
			return true;
		}
		return false;
	}


	// recursive case

	// now we look at all the possible unvisited nodes
	// that can be reached from current node
	for(int i=0;i<v;i++){
		if(adj[curr_node][i]==1 and vis[i]==0){
			// try to find a hamoltonian path through this vertex

			// do 
			path.push_back(i);
			vis[i]=1;

			// recur
			if(is_hamoltoniancycle(start_node,i,path,vis,adj))return true;

			// redo
			path.pop_back();
			vis[i]=0;
		}
	}
	return false;
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

		// look for hamoltanian cycle
		// with starting from different positions
		vi path;
		vi vis(v,0);
		for(int st_node=0;st_node<v;st_node++){
			// try to find hamoltonian cycle starting from st_node
			path.push_back(st_node);
			vis[st_node]=1;
			if(is_hamoltoniancycle(st_node,st_node,path,vis,adj))return 0;
			path.pop_back();
			vis[st_node]=0;
		}

	}
}