// Negative cycle detection using Bellman Ford algo
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define gi greater<int>
#define vvi vector<vi>

class Solution{
public:
	int isNegativeWieghtCycle(int n,vvi edges){

		vector<long long> sd(n,INT_MAX);

		for(int i=1;i<n;i++){
			for(auto x:edges){
				// use this edge to relax the shortest distance
				sd[x[1]]=min(sd[x[1]],sd[x[0]]+x[2]);
			}
		}


		// perform an extra iteration
		// if edges are relaxed then it means a negative cycle
		// int ans=1;
		for(auto x:edges){
			if(sd[x[1]]>sd[x[0]]+x[2])return 1;
		}
		return 0;
	}
};

int main(){
	int tc;
	cin>>tc;
	while(tc--){
		int n,m;
		cin>>n>>m;
		vvi edges;
		int u,v,e;
		for(int i=0;i<m;i++){
			cin>>u>>v>>e;
			edges.push_back({u,v,e});
		}
		Solution obj;
		int ans=obj.isNegativeWieghtCycle(n,edges);
		cout<<ans<<"\n";
	}
	return 0;
}
