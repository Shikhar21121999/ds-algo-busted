// program to solve eggs dropping problem
// using recursion and itterative bottom up dp

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>

class Solution{
public:
	int eggDropDP(int n,int k){
		vvi dp(n+1,vi(k+1,0));

		// we need 0 drops for 0 floor
		// and 1 drop for 1 floor
		for(int i=1;i<=n;i++){
			dp[i][0]=0;
			dp[i][1]=1;
		}

		// we need i drops when we have i floor
		// and only 1 egg
		for(int i=1;i<=k;i++){
			dp[1][i]=i;
		}

		// fill dp for other cases
		for(int i=2;i<=n;i++){
			for(int j=2;j<=k;j++){
				dp[i][j]=INT_MAX;
				for(int x=1;x<=j;x++){
					dp[i][j]=min(dp[i][j],max(dp[i-1][x-1],dp[i][j-x])+1);
				}
			}
		}

		return dp[n][k];
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.eggDropDP(n,k)<<endl;
	}

}