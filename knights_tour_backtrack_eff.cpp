// efficient program to solve knight tour problem
// link:https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/

#include <bits/stdc++.h>
using namespace std;

# define N 8 

bool is_safe(int i,int j,int sol[N][N]){
	return (i>=0 && j>=0 && i<N  && j<N && sol[i][j]==-1);
}

int backtrack(int x,int y,int movei,int sol[N][N],int movex[N],int movey[N]){
	// cout<<x<<" "<<y<<" "<<movei<<endl;
	// base case
	if(movei==N*N){
		return 1;
	}
	
	//recurse case
	// try all the next moves from the current coordinates
	for(int i=0;i<8;i++){
		int next_x=x+movex[i];
		int next_y=y+movey[i];
		// check these coordinates
		if(is_safe(next_x,next_y,sol)){
			// try with this coordinate
			sol[next_x][next_y]=movei;
			if(backtrack(next_x,next_y,movei+1,sol,movex,movey)==1){
				return 1;
			}
			else{
				// redo
				sol[next_x][next_y]=-1;
			}
		}
	}
	return 0;
}
			
void printSolution(int sol[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<sol[i][j]<<" ";
		}
		cout<<endl;
	}
	
}	

int solveKT(){
	// utility function to solve the problem using backtracking
	int sol[N][N];
	
	// initialize the array to -1
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			sol[i][j]=-1;
		}
	}
	
	// define moves of knight
	int movex[8]={ 2, 2, -2, -2, +1, -1, +1, -1 };
	int movey[8]={ 1, -1, 1, -1, 2, 2, -2, -2 };
	
	// mark the initial position of the sol grid
	sol[0][0]=0;
	
	// start from 0,0
	if(backtrack(0,0,1,sol,movex,movey)==0){
		cout<<"No solution exist\n";
		return 0;
	}
	else printSolution(sol);
	return 1;
}
	

int main(){
	// call the function
	solveKT();
	return 0;
}
