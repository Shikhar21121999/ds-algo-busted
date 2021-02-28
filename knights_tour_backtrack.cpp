// program to solve knights tour problem
// using backtrack

#include <bits/stdc++.h>
using namespace std;
# define vi vector <int>
# define vvi vector <vi>
# define pii pair<int,int>
# define vpii vector <pii>

vpii valid_cords(int x,int y,const vvi &vis,int n){
	// function to generate and return all the valid postions
	// for knight from cords i,j
	vpii coll,ans;
	coll.push_back(make_pair(x+2,y+1));
	coll.push_back(make_pair(x+2,y-1));
	coll.push_back(make_pair(x-2,y+1));
	coll.push_back(make_pair(x-2,y-1));
	coll.push_back(make_pair(x+1,y+2));
	coll.push_back(make_pair(x-1,y+2));
	coll.push_back(make_pair(x+1,y-2));
	coll.push_back(make_pair(x-1,y-2));
	
	// traverse the vector to check and add the vaild cords
	// to the ans vector
	for(auto x:coll){
		if(x.first>=0 && x.second>=0 && x.first<n && x.second<n && vis[x.first][x.second]<0){
			ans.push_back(x);
		}
	} 
	return ans;
}
	

bool backtrack(int currx,int curry,vvi &grid,int cnt,int n){
	// cout<<"current recursion with values\n";
	// cout<<currx<<" "<<curry<<" "<<cnt<<endl;
	// base case
	// all the cells are visited
	if(cnt==(n*n-1)){
		// print the grid
		cout<<"answer found printing grid\n";
		for(auto x:grid){
			for(auto y:x){
				cout<<y<<" ";
			}
			cout<<endl;
		}
	}
	
	// recurse case
	vpii poss;
	poss=valid_cords(currx,curry,grid,n);
	// cout<<"poss answeres are:\n";
	// for(auto x:poss){
	// 	cout<<x.first<<" "<<x.second<<endl;
	// }
	for(auto x:poss){
		// do
		grid[x.first][x.second]=cnt+1;
		// recur
		if(backtrack(x.first,x.second,grid,cnt+1,n)){
			return true;
		}
		else{
			// undo
			grid[x.first][x.second]=-1;
		}
	}
	return false;
}

		

int main(){
	int n;
	cin>>n;
	// enter a grid of nXn
	vector <vector <int> > grid(n,vector <int> (n,-1));
	grid[2][2]=0;
	backtrack(2,2,grid,0,n);
	cout<<"finished"<<endl;
}
	
