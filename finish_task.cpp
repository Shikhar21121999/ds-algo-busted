// program to find if it is possible to finish task

#include <bits/stdc++.h>
using namespace std;


bool is_cyclic(vector <int> adj[],int N){
	// initially mark all the vertex as unvisited
	vector<int> vis(N,0);
	stack<int> s;

	for(int i=0;i<N;i++){
		if(!vis[i]){
			// this is seperate component
			vector<int> recur_vis(N,0);
			s.push(i);
			vis[i]=1;
			recur_vis[i]=1;
			int curr_node;
			while(!s.empty()){
				curr_node=s.top();
				s.pop();

				// traversing all the adjacent nodes of the current nodes
				for(auto x:adj[curr_node]){
					if(recur_vis[x]==1)return true;
					if(!vis[x]){
						vis[x]=1;
						recur_vis[x]=1;
						s.push(x);
					}
				}
			}
		}
	}
	return false;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int N,E;
		cin>>N>>E;
		int u,v;

		vector<int> adj[N];

		for(int i=0;i<E;i++){
			cin>>u>>v;
			adj[u].push_back(v);
		}

		// printing graph
		// for(int i=0;i<N;i++){
		// 	for(auto x:adj[i]){
		// 		cout<<i<<" "<<x<<endl;
		// 	}
		// }

		// cout<<is_cyclic(adj,N);
		if(!is_cyclic)cout<<"Possible to do all task"<<endl;
		else cout<<"Not possible to perform all tasks"<<endl;
		
		// we have a graph adj
		// now we check if it is cyclic
	}
}
