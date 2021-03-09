// program to detect cycle in a graph using dsu
// in an undirected graph

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vpii vector<pii>

vector<int> parent;
vector<int> size;

int find_set(int v){
	// to find the set in which element v is part of 
	if(v==parent[v])return v;
	return parent[v]=find_set(parent[v]);
}

void union_set(int a,int b){
	// to perform union of the set in which element a and b are present
	a=find_set(a);
	b=find_set(b);
	if(size[a]<size[b]){
		swap(a,b);
	}
	// size of a is bigger
	// adding set of smaller size b to a
	parent[b]=a;
	size[a]+=size[b];
}

bool isCycle(int V,vector<int> adj[]){
	
	// initialize a dsu
	parent.resize(V);
	size.resize(V,1);

	for(int i=0;i<V;i++){
		parent[i]=i;
	}

	// a vector of vector to ensure that a back edge does not get counted as a cycle
	vector<vector<int>> vis(V,vector<int> (V,0));

	// traverse all the edges and make a dsu accordingly
	for(int i=0;i<V;i++){
		for(auto j:adj[i]){
			if(!vis[i][j]){
				// include i and j in one component
				// first check if they are already in one component
				if(find_set(i)==find_set(j)){
					// cout<<i<<" "<<j<<endl;
					return true;
				}
				union_set(i,j);
				vis[i][j]=1;
				vis[j][i]=1;
			}
		}
	}
	return false;
}

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
		bool ans=isCycle(V,adj);
		if(ans)cout<<"1\n";
		else cout<<"0\n";
	}
	return 0;
}
