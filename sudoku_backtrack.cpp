// program to solve sudoku using backtrack
// link:https://leetcode.com/problems/remove-invalid-parentheses/

#include <bits/stdc++.h>
using namespace std;
# define N 9
# define unassigned 0 
bool FindUnassigned(int grid[N][N],int &row,int &col){
	// function to find if an unassigned value exists in the array
	// if it does return true and assign row and col to unassigned cell
	// else return false
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(grid[i][j]==unassigned){
				row=i;
				col=j;
				return true;
			}
		}
	}
	return false;
}

bool used_inrow(int grid[N][N],int row,int num){
	// check if number num exist in the given row
	for(int j=0;j<9;j++){
		if(grid[row][j]==num){
			return true;
		}
	}
	return false;
}

bool used_incol(int grid[N][N],int col,int num){
	// check if number exist in the given column
	for(int i=0;i<N;i++){
		if(grid[i][col]==num)return true;
	}
	return false;
	
}

bool in_grid(int grid[N][N],int boxstrow,int boxstcol,int num){
	// check if same number exist in the same grid
	for(int i=boxstrow;i<boxstrow+3;i++){
		for(int j=boxstcol;j<boxstcol+3;j++){
			if(grid[i][j]==num)return true;
		}
	}
	return false;
}

bool is_safe(int grid[N][N],int row,int col,int num){
	// function to check if number num exists
	// in same row and column as that of the given coordinate
	
	// find the starting grid_index for the current row and col
	return !used_inrow(grid,row,num)&&!used_incol(grid,col,num)&&
			!in_grid(grid,row-row%3,col-col%3,num)&&grid[row][col]==unassigned;
}

bool Solvesudoku(int grid[N][N]){
	// base case when no unassigned cell is left
	// in the grid
	int row,col;
	if(!FindUnassigned(grid,row,col)){
		return true;
	}
	
	// else we have to fill the grid
	// we select a value from 1 to 9 and see if it is a safe value
	// that is if same value exists
	// in same row,col or grid
	
	for(int num=1;num<=9;num++){
		if(is_safe(grid,row,col,num)){
			// fill the grid with this value
			grid[row][col]=num;
			// recur with this
			if(Solvesudoku(grid)){
				return true;
			}
			// redo
			grid[row][col]=unassigned;
		}
	}
	return false;
}

void printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row++) 
    {
        for (int col = 0; col < N; col++)
            cout << grid[row][col] << " ";
        cout << endl;
    }
}
	


int main(){
	// input the sudoku grid
	int grid[N][N];
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>grid[i][j];
		}
	}
	if(Solvesudoku(grid)){
		printGrid(grid);
	}
	else cout<<"No solution exists";
}

