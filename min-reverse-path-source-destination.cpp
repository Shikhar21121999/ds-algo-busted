// program to print minumum number of paths to reverse
// to go from source to destination

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

int minEdgesReversal(vvpii &adj,int src,int dest){

	// now we need to find shortest path from source to destination
	// since this a directed graph with positive edge wieghts
	// we use djkstras algo

	int n=adj.size();
	vi sd(n,INT_MAX);
	vi vis(n,0);

	sd[src]=0;
	minpq pq;
	pq.push(src);

	while(!pq.empty()){
		int curr_node=pq.top();
		pq.pop();
		if(vis[curr_node])continue;
		vis[curr_node]=1;

		for(auto x:adj[curr_node]){

			// relax the shortest path
			sd[x.first]=min(sd[x.first],sd[curr_node]+x.second);
			if(vis[x.first]==0)pq.push(x.first);
		}
	}
	// for(int i=0;i<n;i++){
	// 	cout<<i<<" "<<sd[i]<<endl;
	// }

	// return the shortest distance to destination
	return sd[dest];

}

int main(){
	int n,m;
	cin>>n>>m;
	vvpii adj(n);
	int u,v;
	vi temp(3);
	for(int i=0;i<m;i++){
		cin>>u>>v;
		adj[u].push_back(make_pair(v,0));
		adj[v].push_back(make_pair(u,1));
	}

	// cout<<"prinitng the graph\n";
	// for(int i=0;i<n;i++){
	// 	for(auto x:adj[i]){
	// 		cout<<i<<" "<<x.first<<" "<<x.second<<endl;
	// 	}
	// }
	int sr,dest;
	cin>>sr>>dest;

	// cout<<sr<<" "<<dest<<endl;

	cout<<minEdgesReversal(adj,sr,dest)<<endl;
	return 0;
}