// program to print min cost to fill given wieght in a bag
// link:https://practice.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
class Solution{
public:
	int minimumCost(int cost[],int n,int w){
		vi dp(w+1,INT_MAX);
		dp[0]=0;

		for(int i=0;i<n;i++){
			if(cost[i]==-1)continue;
			for(int j=i+1;j<=w;j++){
				if(dp[j-(i+1)]!=INT_MAX && dp[j]>dp[j-(i+1)]+cost[i]){
					dp[j]=dp[j-(i+1)]+cost[i];
				}
			}
		}

		// for(int i=0;i<w;i++)cout<<dp[i]<<" ";
		// cout<<endl;
		int ans=dp[w];
		if(dp[w]==INT_MAX)return -1;
		return dp[w];
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,w;
		cin>>n>>w;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.minimumCost(a,n,w)<<endl;
	}
}

