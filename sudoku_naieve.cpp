// program to solve sudoku solver
// link:https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1

#include <bits/stdc++.h>
using namespace std;
#define N 9
#define vi vector <int>
#define vvi vector <vi>

void printGrid (vvi &grid){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<grid[i][j]<<" ";
		}
		cout<<"\n";
	}
}

bool check_grid(int stx,int sty,vvi &grid){
	int occur[10]={0};
	for(int i=stx;i<stx+3;i++){
		for(int j=sty;j<sty+3;j++){
			occur[grid[i][j]]+=1;
			if(occur[grid[i][j]]>1)return false;
		}
	}
	return true;
}

bool valid_ans(vvi &grid){
	// we get a grid and we have to check if it is a vaild sudoku
	
	int occur[10]={0};
	//checking grid wise
	for(int row=0;row<9;row++){
		for(int col=0;col<9;col++){
			occur[grid[row][col]]+=1;
			if(occur[grid[row][col]]>1)return false;
		}
		memset(occur, 0, sizeof(occur));
	}
	
	// checking column wise
	for(int col=0;col<9;col++){
		for(int row=0;row<9;row++){
			occur[grid[row][col]]+=1;
			if(occur[grid[row][col]]>1)return false;
		}
		memset(occur, 0, sizeof(occur));
	}
	
	// checking all the grids
	return check_grid(0,0,grid)&&check_grid(0,3,grid)&&check_grid(0,6,grid)&&
			check_grid(3,0,grid)&&check_grid(3,3,grid)&&check_grid(3,6,grid)&&
			check_grid(6,0,grid)&&check_grid(6,3,grid)&&check_grid(6,6,grid);
}

bool backtrack(int row,vvi &grid,int unfilled){
	cout<<unfilled<<endl;
	// base case
	if(unfilled==0){
		// implies all the cells are filled
		printGrid(grid);
		return valid_ans(grid);
	}
	
	// recur case
	// we try to fill the unfilled cells of the sudoku
	// and see if we can get an answer
	for(int i=row;i<N;i++){
		for(int j=0;j<N;j++){
			if(grid[i][j]==0){
				// unfilled grid we try to fill it with all the possible
				// values from 1 to 9
				for(int no=1;no<=9;no++){
					// do
					grid[i][j]=no;
					if(backtrack(row,grid,unfilled-1)){
						return true;
					}
				}
				grid[i][j]=0;
			}
		}
	}
	return false;
}




int main(){
	vvi grid(9,vi(9));
	int unfilled=0;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin>>grid[i][j];
			if(grid[i][j]==0)unfilled+=1;
		}
	}
	cout<<backtrack(0,grid,unfilled);
	
}
