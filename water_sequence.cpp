// water connection problem

#include <bits/stdc++.h>
using namespace std;
int min_wt_edge,tail_node;

void dfs(int node,const vector <int> &next,const vector <int> &dia){
	tail_node=node;
	if(next[node]!=0){
		min_wt_edge=min(min_wt_edge,dia[node]);
		dfs(next[node],next,dia);
	}
}

void solve(){
	int v,e;
	cin>>v>>e;
	
	vector <int> next(v+1);
	vector <int> dia(v+1);
	vector <bool> has_incomin_edge(v+1,false);
	
	for(int i=0;i<e;i++){
		int from,to,diam;
		cin>>from>>to>>diam;
		has_incomin_edge[to]=true;
		next[from]=to;
		dia[from]=diam;
	}
	
	vector <array <int,3> > ans;
	
	// checking for each vertex
	for(int i=1;i<=v;i++){
		// if not a first vetex
		if(has_incomin_edge[i])continue;
		
		if(next[i]==0)continue;
		
		// node i is a head node
		// and it has some nodes attached to it
		// start dfs from here
		
		min_wt_edge=INT_MAX;
		tail_node=-1;
		
		// call dfs
		dfs(i,next,dia);
		ans.push_back({i,tail_node,min_wt_edge});
	}
	cout<<ans.size()<<"\n";
	
	for(auto x:ans){
		cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<"\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	//ios_base :: sync_with_stdio ( false ) ; cin.tie ( 0 ) ;
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
