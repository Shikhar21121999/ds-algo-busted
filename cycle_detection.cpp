// program to detect cycle in an undirected graph
// solution to  the problem https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		bool isCycle(int V,vector<int> adj[]){
			// code starts here
			stack<pair <int,int> > s;
			vector <int> vis(V+1);
			// bool cycle=false;
			for(int i=0;i<V;i++){
				if(!vis[i]){
					// cout<<"perform dfs on component"<<i<<endl;
					vis[i]=1;
					s.push(make_pair(i,-1));
					// current node pair represent
					// first the current node and second parent of curr node
					pair<int,int> curr_node_pair;
					int curr_node;
					int parent;
					while(!s.empty()){
						curr_node_pair=s.top();
						s.pop();
						curr_node=curr_node_pair.first;
						parent=curr_node_pair.second;
						// cout<<"current node pair :"<<curr_node<<" "<<parent<<endl;
						
						// visit all the child nodes of the current node
						for(auto x:adj[curr_node]){
							if(x==parent)continue;
							if(vis[x] and parent!=x){
								// cycle found
								return true;
							}
							vis[x]=1;
							s.push(make_pair(x,curr_node));
						}
					}
				}
			}
			return false;
							 
		}
};


// Driver code
int main(){
	int tc;
	cin>>tc;
	while(tc--){
		int V,E;
		cin>>V>>E;
		vector <int> adj[V];
		for(int i=0;i<E;i++){
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans=obj.isCycle(V,adj);
		if(ans)cout<<"1\n";
		else cout<<"0\n";
	}
	return 0;
}
		
