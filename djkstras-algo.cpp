// program to show implementation of djkstras algorithm
// djkstras algo is used to find 1 source to all shortest path

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define gi greater<int>

int main(){
	int V;
	cin>>V;
	vvpii graph(V);

	int E;
	cin>>E;
	int v1,v2,wt;
	for(int i=0;i<E;i++){
		cin>>v1>>v2>>wt;
		graph[v1].push_back(make_pair(v2,wt));
		graph[v2].push_back(make_pair(v1,wt));
	}

	// input the starting node
	int st;
	cin>>st;

	// print the graph
	for(int i=0;i<V;i++){
		for(auto x:graph[i]){
			cout<<i<<" "<<x.first<<" "<<x.second<<endl;
		}
	}

	// now we have to find shortest distance from source to all vertices
	vector<int> sd(V,INT_MAX);
	vector<bool> vis(V,false);
	// create a min_priority que to get the node 
	// which is at min distance at a particular instant
	priority_queue<int,vi,greater<int>> mpq;

	sd[st]=0;
	mpq.push(st);

	while(!mpq.empty()){
		int curr_node=mpq.top();
		mpq.pop();
		if(vis[curr_node])continue;
		vis[curr_node]=true;

		// now we visit all the adjacent nodes
		for(auto x:graph[curr_node]){
			// relax the edge if node is unvisited
			sd[x.first]=min(sd[x.first],sd[curr_node]+x.second);
			if(!vis[x.first])mpq.push(x.first);
		}
	}

	cout<<"shortest distances from "<<st<<endl;
	// print the calculated shortest distances
	for(int i=0;i<V;i++){
		cout<<sd[i]<<endl;
	}

}
