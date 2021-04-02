// program to solve assembley scheduling problem

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

int carAssembley(vvi &a,vvi &t,int e1,int e2,int x1,int x2)
{
	int first,second;

	// Time taken leave first
	// station in line 1
	first=a[0][0]+e1;
	
	// Time taken leave second
	// station in line 2
	second=a[1][0]+e2;

	// Fill tables 
	for(int i=1;i<a.size();i++){
		int top = a[0][i]+min(first,second+t[1][i]);
		int bottom = a[0][i]+min(second,first+t[0][i]);
		first=top;
		second=bottom;
	}
	first+=x1;
	second+=x2;
	return min(first,second);
}

int main(){
	int numStations;
	cin>>numStations;

	vvi a(2,vi(numStations,0));
	for(int i=0;i<2;i++){
		for(int j=0;j<numStations;j++){
			cin>>a[i][j];
		}
	}

	vvi t(2,vi(numStations,0));
	for(int i=0;i<2;i++){
		for(int j=0;j<numStations;j++){
			cin>>t[i][j];
		}
	}

	// time for entry into the assembley line
	int e1,e2;
	cin>>e1>>e2;

	// time for exit form the assebley line
	int x1,x2;
	cin>>x1>>x2;
}