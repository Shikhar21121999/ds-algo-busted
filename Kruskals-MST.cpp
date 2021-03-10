
// Program to find Minimum Spanning Tree
// For an undirected wieghted graph

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vpii>

// dsu
vector<int> parent;
vector<int> size;

void print_edge_coll(vvi &edge_list){
	// print the edges in the edge list
	for(auto x:edge_list){
		for(auto y:x){
			cout<<y<<" ";
		}
		cout<<endl;
	}
}

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

bool comp(vi a,vi b){
	return (a[2]<b[2]);
}

// program to find minimum spanning tree for undirected graph
// using Kruskal's Algorithm
void Kruskal_MST(int V,vvi &edge_coll){

	// initialize the dsu
	parent.resize(V);
	for(int i=0;i<V;i++){
		parent[i]=i;
	}
	size.resize(V,1);

	// sort all the edges of the graph on the basis of wieght
	sort(edge_coll.begin(),edge_coll.end(),comp);

	// print the sorted edge_coll
	print_edge_coll(edge_coll);

	// now we include edge one by one
	// ensure including it in the edge_coll does not form a cycle
	// select such V-1 edges

	vvi mst_edges;
	int i=0;
	int edge_cnt=1;

	// vvpii ans_mst(V);
	// int i=0;
	// int vert_cnt=0;
	// int mst_wt=0;

	while(edge_cnt<=V-1 && i<edge_coll.size()){
		// check if including this edge forms a cycle
		// current edge in consideration
		// edge_coll[i];
		// check if including this edge forms a cycle
		if(find_set(edge_coll[i][0])!=find_set(edge_coll[i][1])){
			edge_cnt++;
			mst_edges.push_back(edge_coll[i]);
			union_set(edge_coll[i][0],edge_coll[i][1]);
		}
		i++;
	}

	// print the mst edge
	cout<<"mst edges\n";
	print_edge_coll(mst_edges);
}

int main(){
	int V,E;
	cin>>V>>E;
	cout<<V<<" "<<E<<endl;

	// make a collection of edges
	vvi edge_list;

	vector<int> edge(3);
	for(int i=0;i<E;i++){
		cin>>edge[0]>>edge[1]>>edge[2];
		edge_list.push_back(edge);
	}

	// print the edge list
	print_edge_coll(edge_list);
	cout<<"calling function\n";
	Kruskal_MST(V,edge_list);
}
