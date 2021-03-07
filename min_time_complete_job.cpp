// minimum time taken to complete job

#include <bits/stdc++.h>
using namespace std;


vector <int> min_time(int V,vector <int> adj[]){

	// first we need to find indegree for all the graph
	vector<int> indegree(V+1,0);

	// now we need to recurse all the edges
	// and see how many times each node occurs
	for(int i=1;i<=V;i++){
		for(auto x:adj[i]){
			indegree[x]++;
		}
	}

	// print indegree of all the vertices
	// for(int i=1;i<=V;i++){
	// 	cout<<indegree[i]<<" ";
	// }
	// cout<<endl;

	// to store time for completion of job
	vector <int> job(V+1,0);

	// make a queue
	queue <int> q;

	// push all the nodes whose indegree is zero into the queue
	for(int i=1;i<=V;i++){
		if(indegree[i]==0){
			q.push(i);
			job[i]=1;
		}
	}

	while(!q.empty()){
		int curr_node=q.front();
		q.pop();

		// mark all its adjacent indegree lesser by one 
		for(auto x:adj[curr_node]){
			indegree[x]--;

			if(indegree[x]==0){
				// update job
				job[x]=job[curr_node]+1;
				q.push(x);
			}
		}
	}

	return job;

}

int main(){
	int t;
	cin>>t;
	while(t--){
		int N,E;
		cin>>N>>E;
		int u,v;

		vector<int> adj[N+1];

		for(int i=0;i<E;i++){
			cin>>u>>v;
			adj[u].push_back(v);
		}
		vector<int> ans;
		ans=min_time(N,adj);
		for(int i=1;i<=N;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;

	}
}
