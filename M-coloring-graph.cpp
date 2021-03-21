// program to solve m-coloring-graph problem
// link:https://practice.geeksforgeeks.org/problems/m-coloring-problem/0

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
#define qi queue<int>

bool graphColoring(bool graph[101][101],int m,int n){
	// initially color all the graph with color 0
	vi color(n,1);
	// color used till now are 0
	int max_Color=1;
	vi vis(n,0);

	// color all the nodes in a connected component using bfs traversal
	// to color different connected components use for loop
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			qi q;
			vis[i]=1;
			q.push(i);

			// bfs using queue
			while(!q.empty()){
				int curr_node=q.front();
				q.pop();

				// checking all the adjacent edges of the node
				for(int j=0;j<n;j++){
					if(graph[curr_node][j]==1){
						// j is an adjacent node to curr_node
						if(color[curr_node]==color[j]){
							cout<<curr_node<<" "<<j<<" "<<color[curr_node]<<" "<<color[j]+1<<endl;
							color[j]+=1;
						}

						max_Color=max(max_Color,color[j]);

						if(max_Color>m){
							return 0;
						}

						// if this node is not visited
						// then push this node in queue
						// to perform further bfs
						if(!vis[j]){
							vis[j]=1;
							q.push(j);
						}
					}
				}

			}
		}
	}
	return 1;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,e;
		cin>>n>>m>>e;
		int i;
		bool graph[101][101];
		for(i=0;i<n;i++){
			memset(graph[i],0,sizeof(graph[i]));
		}
		int a,b;
		for(i=0;i<e;i++){
			cin>>a>>b;
			graph[a-1][b-1]=1;
			graph[b-1][a-1]=1;
		}

		// print the graph
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<graph[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<graphColoring(graph,m,n)<<endl;
	}
	return 0;
}

