// program to solve the maximize the cut segments problem

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

int maximizeTheCuts(int n,int x,int y,int z){
	vi dp(n+1,-1);
	dp[0]=0;
	vi segment{x,y,z};

	for(int i=0;i<3;i++){
		for(int j=segment[i];j<=n;j++){
			if(dp[j-segment[i]]>=0){
				// an allowed length
				dp[j]=max(dp[j],dp[j-segment[i]]+1);
			}
		}
	}
	// for(int i=0;i<=n;i++){
	// 	cout<<dp[i]<<" ";
	// }
	// cout<<endl;
	if(dp[n]==-1){
		return 0;
	}
	return dp[n];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,x,y,z;
		cin>>n>>x>>y>>z;
		cout<<maximizeTheCuts(n,x,y,z)<<endl;
	}
	return 0;
}