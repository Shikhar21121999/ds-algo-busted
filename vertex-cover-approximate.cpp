// program to print vertex cover of a given undirected graph
// this gives apporximate answer as vertex cover problem
// is a known NP-complete problem

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
#define minpq priority_queue<int,vi,greater<int>>
#define space " "

int main(){
	int n,m;
	cin>>n>>m;
	vvi adj(n);
	int u,v;

	vpii edge;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		edge.push_back(make_pair(u,v));
	}

	vi result;
	vi in_res(n,0);

	for(int i=edge.size()-1;i>=0;i--){
		pii x=edge[i];
		cout<<x.first<<" "<<x.second<<endl;
		if(in_res[x.first]==0 and in_res[x.second]==0){
			cout<<"push inside\n";
			// add both the node to the vertex cover or result
			result.push_back(x.first);
			result.push_back(x.second);
			in_res[x.first]=1;
			in_res[x.second]=1;
		}
	}

	cout<<"vertex cover is : "<<result.size()<<endl;
	for(auto x:result){
		cout<<x<<" ";
	}
	cout<<endl;
	
}