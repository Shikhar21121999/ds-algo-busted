// program to solve path length more than k
// link:https://www.geeksforgeeks.org/find-if-there-is-a-path-of-more-than-k-length-from-a-source/

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vvi vector<vi>

bool path_greater(int node,vvpii &graph,vb &vis,int left_length){
	cout<<node<<" "<<left_length<<endl;
	// base case
	if(left_length<=0){
		return true;
	}
	
	// recursive case
	for(auto x:graph[node]){
		if(!vis[x.first]){
			// do
			vis[x.first]=true;
			if(path_greater(x.first,graph,vis,left_length-x.second)){
				return true;
			}
		}
	}
	return false;
}

int main(){
	int n;
	cin>>n;
	
	vvpii graph(n+1);
	int edges;
	cin>>edges;
	int v1,v2,edg;
	for(int i=0;i<edges;i++){
		cin>>v1>>v2>>edg;
		graph[v1].push_back(make_pair(v2,edg));
		graph[v2].push_back(make_pair(v1,edg));
	}
	
	// print the corrosponding graph
	for(int i=0;i<n;i++){
		for(auto x:graph[i]){
			cout<<i<<" "<<x.first<<" "<<x.second<<endl;
		}
	}
	vb vis(n+1,false);
	int source,k;
	cin>>source>>k;
	cout<<"input over\n";
	vis[source]=true;
	if(path_greater(source,graph,vis,k)){
		cout<<"yes\n";
	}
	else cout<<"No\n";
}
