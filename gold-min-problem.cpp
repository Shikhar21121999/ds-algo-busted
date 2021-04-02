// program to solve Gold mine probem
// iterative dp bottom up solution

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>

int goldMineProblem(vvi &a){
	int n=a.size();
	int m=a[0].size();
	vvi dp(n,vi(m,0));

	// fill the dp from last column to first
	// and moving down the row
	for(int j=m-1;j>=0;j--){
		for(int i=0;i<n;i++){
			int right=(j==m-1)?0:dp[i][j+1];
			int upright=(j==m-1 or i==0)?0:dp[i-1][j+1];
			int downright=(j==m-1 or i==n-1)?0:dp[i+1][j+1];
			dp[i][j]=a[i][j]+max(right,max(upright,downright));
		}
	}

	// get the first column of the row which has max
	int ans=0;
	for(int i=0;i<n;i++){
		ans=max(ans,dp[i][0]);
	}
	return ans;
}

int main(){
	int n,m;
	cin>>n>>m;
	vvi arr(n,vi(m,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}

	cout<<goldMineProblem(arr);
	return 0;
}