// Given a Directed Graph with V vertices and E edges, Find any Topological Sorting of that Graph.
// link:https://practice.geeksforgeeks.org/problems/topological-sort/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	void topsort_util(int node,vector <int> adj[],stack <int> &ans,vector <int> &vis){
		// visit all the child nodes if possible
		for(auto x:adj[node]){
			if(!vis[x]){
				vis[x]=1;
				topsort_util(x,adj,ans,vis);
				ans.push(x);
			}
		}
	}
	vector <int> topoSort(int V,vector <int> adj[]){
		// perform a bfs and keep count of visited vertices

		// an outer loop to perform topological sort on all
		stack <int> ans;
		vector <int> vis(V,0);
		for(int i=0;i<V;i++){
			if(!vis[i]){
				vis[i]=1;
				topsort_util(i,adj,ans,vis);
				ans.push(i);
			}			
		}
		vector <int> retans;
		
		while(!ans.empty()){
			int curr=ans.top();
			ans.pop();
			retans.push_back(curr);
		}

		return retans;
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int N,E;
		cin>>E>>N;
		int u,v;

		vector<int> adj[N];

		for(int i=0;i<E;i++){
			cin>>u>>v;
			adj[u].push_back(v);
		}

		Solution obj;
		vector <int> res=obj.topoSort(N,adj);
		for(auto x:res){
			cout<<x<<" ";
		}

	}
}
