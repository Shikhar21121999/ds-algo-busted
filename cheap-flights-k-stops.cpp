// program to find the price of shortest flight
// provided there are stops not more than k

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector <vpii>
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define si stack<int>
#define ll long long
#define vll vector<ll>
#define space " "
// push_back make_pair

class Solution {
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for (int i = 0; i < (int) flights.size(); ++i) {
            adj[flights[i][0]].push_back(make_pair(flights[i][1],flights[i][2]));
        }
        vector<int> cost(n,100000);
        priority_queue<pair<pair<int,int>,int>> pq;
        pq.push(make_pair(make_pair(0,0),src));
        cost[src] = 0;
        while (!pq.empty()) {
            int route = abs(pq.top().first.first);
            int node_cost = abs(pq.top().first.second);
            int node = pq.top().second;
            pq.pop();
            for (pair<int,int> child : adj[node]) {
                if (node_cost + child.second < cost[child.first] and route <= k) {
                    cost[child.first] = node_cost + child.second;
                    pq.push(make_pair(make_pair((route + 1) ,cost[child.first]),child.first));
                }
            }
        }
        return cost[dst] >= 100000 ? -1 : cost[dst];
    }
};

int main(){
	int n,m;
	cin>>n>>m;
	vvi adj(n);
	// int u,v,e;
	vi temp(3);
	for(int i=0;i<m;i++){
		cin>>temp[0]>>temp[1]>>temp[2];
		adj[i]=temp;
	}
	int sr,dest,k;
	cin>>sr>>dest>>k;

	Solution obj;
	int ans=obj.findCheapestPrice(n,adj,sr,dest,k);
	cout<<ans<<endl;
	return 0;
}
