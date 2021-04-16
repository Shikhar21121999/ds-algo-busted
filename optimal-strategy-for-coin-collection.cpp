// program to solve optimal strategy for coin collection
// link:https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1

#include<bits/stdc++.h>
using namespace std;

long long maximumAmount(int a[], int n) 
{
    // Your code here
    int table[n][n];

    for(int gap=0;gap<n;gap++){
    	for(int i=0,j=gap;j<n;i++,j++){
    		int x=((i+2)<=j)?table[i+2][j]:0;
    		int y=((i+1)<=(j-1))?table[i+1][j-1]:0;
    		int z=(i<=(j-2))?table[i][j-2]:0;
    		table[i][j]=max(a[i]+min(x,y),a[j]+min(y,z));
    	}
    }
    return table[0][n-1];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		cout<<maximumAmount(a,n)<<endl;
	}
	return 0;
}