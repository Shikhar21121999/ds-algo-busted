// program to find and print largest sub mtrix whoose sum is 0

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
int main(){
	vector<vector<int>> vect
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vvi colSum(3,vi(3));
    int row=3;
    int col=3;
    for(int i=0;i<row;i++){
    	for(int j=0;j<col;j++){
    		colSum[i][j]=(j>0)?colSum[i][j-1]+vect[i][j]:vect[i][j];
    	}
    }

    for(int i=0;i<row;i++){
    	for(int j=0;j<col;j++){
    		cout<<colSum[i][j]<<" ";
    	}
    	cout<<endl;
    }

    vvi totalSum(row,vi(col,0));
    for(int i=0;i<row;i++){
    	for(int j=0;j<col;j++){
    		totalSum[i][j]=(i>0)?totalSum[i-1][j]+colSum[i][j]:colSum[i][j];
    	}
    }
    cout<<endl;

    for(int i=0;i<row;i++){
    	for(int j=0;j<col;j++){
    		cout<<totalSum[i][j]<<" ";
    	}
    	cout<<endl;
    }
}