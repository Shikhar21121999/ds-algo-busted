// program to solve water sequencing problem
#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

vector <vector <pair <int,int> > > adj;
vector <int> vis;
vector <int> sec;

void ans_mag(int a){
	// need a function that gives us
	// the last node as well as 
	// the smallest edge in the path
	
}


void solve(){
	// input no of vertex and edges
	int v,e;
	cin>>v>>e;
	
	// resize graph and vis vector
	adj.resize(v+1);
	vis.resize(v+1,0);
	sec.resize(v+1,0)
	
	int v1,v2,edg;
	// input and make a graph
	for(int i=0;i<e;i++){
		cin>>v1>>v2>>edg;
		adj[v1].push_back(make_pair(v2,edg));
		sec[v2]=1;
	}
	
	// all the node that don't have a edge
	// in which they are the second vertex
	// impilies these nodes are the first node for all components
	for
	
}
