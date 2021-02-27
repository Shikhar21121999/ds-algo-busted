// program to solve m-coloring-graph problem
// link:https://practice.geeksforgeeks.org/problems/m-coloring-problem/0

#include <bits/stdc++.h>
using namespace std;

bool graphColoring(bool graph[101][101],int m,int n){
	// vector to store color of vertices
	vector <int> color(n,0);
	vector <int> already_occupied(n,0);
	
	for(int i=0;i<n;i++){
		// color the ith vertex
		
		for(int j=0;j<n;j++){
			// find all the edges that go from ith vertex
			if(graph[i][j]==1){
				already_occupied[color[j]]=1;
			}
		}
		// iterate throught the already_occupied colors
		// and find the smallest color that is not occupied
		int assign_color=-1;
		for(int color=1;color<=m;color++){
			if(already_occupied[color]==0){
				assign_color=color;
				break;
			}
		}
		if(assign_color==-1)return false;
		color[i]=assign_color;
	}
	return true;
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
		cout<<graphColoring(graph,m,n)<<endl;
	}
	return 0;
}

