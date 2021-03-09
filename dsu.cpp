// template program for various operations in dsu

#include <bits/stdc++.h>
using namespace std;

// to declare a dsu of size n
int parent[1000];
int size[1000];

void make_set(int v){
	// to make a set with element v
	parent[v]=v;
	size[v]=1;
}

int find_set(int v){
	// to find the set in which element v is part of 
	if(v==parent[v])return v;
	return parent[v]=find_set(parent[v]);
}

void union_set(int a,int b){
	// to perform union of the set in which element a and b are present
	a=find_set(a);
	b=find_set(b);
	if(size[a]<size[b]){
		swap(a,b);
	}
	// size of a is bigger
	// adding set of smaller size b to a
	parent[b]=a;
	size[a]+=size[b];

}
int main(){
	int t;
	cin>>t;
	cout<<"This is dsu template";
}