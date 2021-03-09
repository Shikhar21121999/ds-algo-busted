// program to find connected components in a graph using dsu

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

int connected_components(int N,vpii &edge_list){
	// initialize dsu of size N
	parent.resize(N);
	for(int i=0;i<N;i++){
		parent[i]=i;
	}
	size.resize(N,1);

	// traverse through edge list
	// and keep performing union in the vertices of set
	for(auto x:edge_list){
		// here x is a pair
		union_set(x.first,x.second);
	}

	unordered_map <int,int> recd;
	// traverse the parent array of dsu
	// to count number of disconnected components
	for(int i=0;i<N;i++){
		recd[parent[i]]++;
		// cout<<i<<" "<<parent[i]<<endl;
	}


	int cnt=recd.size();
	// cout<<cnt;
	return cnt;
}

int main(){

	// number of vertices
	int N;
	cin>>N;

	// number of edges
	int edges;
	cin>>edges;

	// edge info
	vector<pair<int,int>> edge_list(edges);
	int u,v;
	for(int i=0;i<edges;i++){
		cin>>u>>v;
		edge_list[i]=make_pair(u,v);
	}
	cout<<connected_components(N,edge_list);

}
