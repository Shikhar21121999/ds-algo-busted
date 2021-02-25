// program to solve n-queens problem using backtracking
// we are given a nXn grid filled with zero's
// and we return a grid with some one's denoting possible
// positions of queens such that no queen is attacking anyone else

#include <bits/stdc++.h>
using namespace std;

vector <vector <int> > grid;
vector <pair<int,int> > queen_cords;

bool possible_selection(int i,int j){
	// function to check if a queen can be placed at i,j
	// satisfying all the conditons
	for(auto x:queen_cords){
		if(i==x.first or j==x.second or abs(i-x.first)==abs(j-x.second)){
			return false;
		}
	}
	return true;
}

void backtrack(int chosn,int n,int stx,int sty){
	// cout<<chosn<<" "<<n<<" "<<stx<<" "<<sty<<endl;
	
	// base case
	// all queens are chosen
	if(chosn==n){
		// mark the coords of queens as 1 in the grid
		// and print the grid
		// grid.resize(n,vector <int> (n,0));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				grid[i][j]=0;
			}
		}
		for(auto x:queen_cords){
			grid[x.first][x.second]=1;
		}
		cout<<"queen placement is as follows\n";
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<grid[i][j]<<" ";
			}
			cout<<"\n";
		}
		return;
	}
	
	// recursive case
	// try to select a new coords for queen ensuring
	// condition is still satisfied
	for(int i=stx;i<n;i++){
		for(int j=0;j<n;j++){
			// cout<<i<<" "<<j<<"\t";
			if(possible_selection(i,j)){
				// add this queen to selection and recurse further
				// do
				queen_cords.push_back(make_pair(i,j));
				// recur
				backtrack(chosn+1,n,i,j);
				// undo
				queen_cords.pop_back();
			}
		}
		// cout<<endl;
	}
}
	

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		grid.resize(n,vector <int> (n,0));
		backtrack(0,n,0,0);
	}
}
