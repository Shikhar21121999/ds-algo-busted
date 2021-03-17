// program to solve journey-to-moon problem

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
#define vvll vector<vll>

void dfs(int i,int &cnt,vi &vis,vvll &adj){
	// visit adjacent nodes
	// cout<<cnt<<endl;
	if(vis[i])return;
	vis[i]=1;
	cnt+=1;
	// cout<<cnt<<endl;
	for(auto x:adj[i]){
		if(!vis[x])dfs(x,cnt,vis,adj);
	}
	return;
}

int main(){

	// number of vertices
	ll n;
	cin>>n;

	// number of edges
	ll edges;
	cin>>edges;

	// edge info
	vvll adj(n);
	ll u,v;
	for(int i=0;i<edges;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	// total possible ways
	ll ans=(n*(n-1))/2;

	// finding components using dfs and counting them
	vi vis(n,0);
	// cout<<ans<<endl;
	for(int i=0;i<n;i++){
		int cnt=0;
		dfs(i,cnt,vis,adj);
		// cout<<cnt<<" "<<ans<<endl;
		ans-=(cnt*(cnt-1))/2;
	}
	cout<<ans<<endl;
	return 0;
}
