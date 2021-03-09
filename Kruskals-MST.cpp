
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
vvpii Kruskal_MST(int V,vvi &graph){

	// initialize the dsu
	parent.resize(V);
	for(int i=0;i<V;i++){
		parent[i]=i;
	}
	size.resize(V,1);

	// sort all the edges of the graph on the basis of wieght
	sort(graph.begin(),graph.end(),comp);

	// now we include edge one by one
	// ensure including it in the graph does not form a cycle
	// select such V-1 edges

	vvpii ans_mst(V);
	int i=0;
	int vert_cnt=0;
	int mst_wt=0;

	while(vert_cnt<V-1 && i<V){
		// check if including this edge forms a cycle
		vi curr_edge=graph[i];
		if(find_set(curr_edge[0])!=find_set(curr_edge[1])){
			// now we can include this edge in the graph
			vert_cnt++;
			ans_mst[curr_edge[0]].push_back(make_pair(curr_edge[1],curr_edge[2]));
			ans_mst[curr_edge[1]].push_back(make_pair(curr_edge[0],curr_edge[2]));
			mst_wt+=curr_edge[2];
		}
		i++;
	}

	return ans_mst;

}

int main(){
	int V,E;
	cin>>V>>E;

	vvi edge_list(V);

	vector<int> edge(3);
	// int u,v,e;
	for(int i=0;i<E;i++){
		cin>>edge[0]>>edge[1]>>edge[2];
		edge_list[i]=edge;
	}

	vvpii MST=Kruskal_MST(V,edge_list);
}
