// minimum number of connections to make graph connected
// link:https://leetcode.com/problems/number-of-operations-to-make-network-connected/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	int makeConnected(int n,vector<vector<int>> &connections){
		// base case
		// when it is possible to rearrange connections
		// to make the graph connected
		if(connections.size()<(n-1)){
			return -1;
		}

		// other case
		// it is possible to connect all the edges to form a connected a graph
		vector<vector<int>> graph(n);

		// create graph from the given connections
		for(auto x:connections){
			graph[x[0]].push_back(x[1]);
			graph[x[1]].push_back(x[0]);
		}

		// print the graph
		// for(int i=0;i<n;i++){
		// 	for(auto y:graph[i]){
		// 		cout<<i<<" "<<y<<endl;
		// 	}
		// }

		// now we traverse the graph to count number of disconnected components
		vector<bool> vis(n,false);
		int cnt=0;
		for(int i=0;i<n;i++){
			if(!vis[i]){
				cnt++;

				// perform bfs traversal and visit all the nodes
				// that lies in this component
				queue <int> q;
				q.push(i);
				vis[i]=true;
				int curr_node;
				while(!q.empty()){
					curr_node=q.front();
					q.pop();

					// peform bfs on all the adjacent nodes
					for(auto x:graph[curr_node]){
						if(!vis[x]){
							vis[x]=true;
							q.push(x);
						}
					}
				}
			}
		}
		// this will give the number of components in the end
		return cnt-1;
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int edge;
		cin>>edge;
		vector<vector<int> > conn;
		int pc1,pc2;
		// vector<int> e(2);
		for(int i=0;i<edge;i++){
			cin>>pc1>>pc2;
			vector<int> e;
			e.push_back(pc1);
			e.push_back(pc2);
			conn.push_back(e);
		}
		cout<<"printing connections";
		for(auto x:conn){
			cout<<x[0]<<" "<<x[1]<<endl;
		}
		cout<<"ends"<<endl;
		Solution obj;
		int ans=obj.makeConnected(n,conn);
		cout<<ans;
	}
}
