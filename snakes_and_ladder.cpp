#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define gi greater<int>
#define vvi vector<vi>

int convert_board(int r,int c,int n){
	if(n%2==0){
		if(r%2==0)return (n*(n-r))-c;
		return (n*(n-r))-(n-c-1);
	}
	if(r%2==0)return (n*(n-r))-(n-c-1);
	return (n*(n-r))-c;
}

int main(){
	int tc;
	cin>>tc;
	while(tc--){
		int v;
		cin>>v;
		vector<vector<int>> adj(v,vi(v,0));
		for(int i=0;i<v;i++){
			for(int j=0;j<v;j++){
				adj[i][j]=convert_board(i,j,v);
			}
		}

		for(int i=0;i<v;i++){
			for(int j=0;j<v;j++){
				cout<<adj[i][j]<<" ";
			}
			cout<<endl;
		}

	}
}