// program to find a minimum spanning tree using prims algo

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vpii>

vvpii prims_mst(vvpii &graph,int V){
	vi included;
	vb not_included(V,1);
	vvpii prims_mst(V);
	int edge_cnt=1;

	included.push_back(0);
	not_included[0]=0;

	// cout<<"initialization okay"<<endl;
	while(edge_cnt<=V-1){
		// cout<<edge_cnt<<endl;

		// stores the new edge with index and edge wt
		vi new_edge(3,-1);
		new_edge[2]=INT_MAX;
		// find the shortest edge
		// connecting included and not included node
		for(auto stnode:included){
			// cout<<stnode<<endl;
			for(auto endnode:graph[stnode]){
				if(not_included[endnode.first] && endnode.second<new_edge[2]){
					new_edge[0]=stnode;
					new_edge[1]=endnode.first;
					new_edge[2]=endnode.second;
				}
				// cout<<new_edge[0]<<" "<<new_edge[1]<<" "<<new_edge[2]<<endl;
			}
		}

		// include this node
		included.push_back(new_edge[1]);
		not_included[new_edge[1]]=0;
		prims_mst[new_edge[0]].push_back(make_pair(new_edge[1],new_edge[2]));
		// prims_mst[new_edge[1]].push_back(make_pair(new_edge[0],new_edge[2]));
		edge_cnt++;
	}

	// after this we must be having a minimum spanning tree
	return prims_mst;

}

void print_wt_graph(vvpii &graph,int V){
	for(int i=0;i<V;i++){
		for(auto x:graph[i]){
			cout<<i<<" "<<x.first<<" "<<x.second<<endl;
		}
	}
}

int main(){
	int tc;
	cin>>tc;
	while(tc--){
		int V,E;
		cin>>V>>E;

		// indexing of vertices are from 0
		vvpii graph(V);
		
		int u,v,e;
		for(int i=0;i<E;i++){
			cin>>u>>v>>e;
			graph[u].push_back(make_pair(v,e));
			graph[v].push_back(make_pair(u,e));
		}
		// undirected graph
		print_wt_graph(graph,V);

		vvpii mst=prims_mst(graph,V);
		cout<<"minimum spanngin tree\n";
		print_wt_graph(mst,V);
	}
	return 0;
}