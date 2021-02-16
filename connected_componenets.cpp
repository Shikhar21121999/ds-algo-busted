// finding connected components in a graph
// a program that finds both number of connected components
// and also the beginning and end of each component

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

vector <vector <pair <int,int> > > G;
vector <int> vis;

int dfs(int a){
	// here a denotes the vertex number
	// we perform dfs starting from index a
	vis[a]=1;
	for(auto x:G[a]){
		if(vis[x.first]==1)return 0;
		if(vis[x.first]==0)return dfs(x.first);
	}
	return 1;
}
void solve(){
	// function to solve the program
	
	// input vector and edges in a graph
	int v,e;
	cin>>v>>e;
	
	// make a vector of vector to store a graph
	G.resize(v+1);
	vis.resize(v+1,0);
	
	int v1,v2,w;
	// input edges
	for(int i=0;i<e;i++){
		cin>>v1>>v2>>w;
		G[v1].push_back(make_pair(v2,w));
	}
	
	// print all the edges for a vertex
	for(int i=1;i<v;i++){
		// now G[i] is a vector of pair
		// which represent vertices connected to i and edge wieght
		for(auto x:G[i]){
			cout<<i<<"\t"<<x.first<<"\t"<<x.second<<"\n";
		}
	}
	
	int conn_comp=0;
	for(int i=1;i<=v;i++){
		if(vis[i]==0){
			if(dfs(i))conn_comp+=1;
		}
	}
	cout<<conn_comp;
	
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
