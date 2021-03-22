// program to print number of triangles in graph

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

void matrixSquare(vvi &A,vvi &B,vvi &ans){
	int n=A.size();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				ans[i][j]+=A[i][k]*B[k][j];
			}
		}
	}
}

int trianglesInGraph(vvi &adj){
	// function to find number of trianges in the given graph

	int n=adj.size();
	// naieve method using trace graph
	// first we find v3 of the graph
	// that is effectively find cube of the given matrix
	vvi square(n,vi(n,0));
	vvi cube(n,vi(n,0));

	// find square
	matrixSquare(adj,adj,square);
	// find cube
	matrixSquare(adj,square,cube);

	// now we need to find trace of the graph
	int cnt=0;
	for(int i=0;i<n;i++){
		cnt+=cube[i][i];
	}
	return cnt/6;

}

int trianglesInGraph1(vvi &adj,int isDirected){
	int ans=0;
	int n=adj.size();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(adj[i][j] && adj[j][k] && adj[k][i]){
					ans+=1;
				}
			}
		}
	}
	isDirected?ans/=3:ans/=6;
	return ans;
}

int main(){
	int n,m;
	cin>>n>>m;
	// adjacencly matrix representation
	vvi adj(n,vi(n,0));
	int u,v;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		adj[u][v]=1;
		adj[v][u]=1;
	}
	int isDirected;
	cin>>isDirected;

	int ans=trianglesInGraph(adj);
	cout<<ans<<endl;
	cout<<trianglesInGraph1(adj,isDirected);
	return 0;
}