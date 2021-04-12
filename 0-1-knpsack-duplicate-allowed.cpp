// program to solve 0-1 knapsack problem when multiple items of same type can be chosen
// that is there are infinite number of items of a type

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
class Solution{
public:
	int knapsack(int n,int w,int val[],int wt[]){

		// we solve this using iterative dp bottom up approach
		vi dp(w+1,-2);
		dp[0]=0;

		// dp[i] holds the max value that can be achieved using a particular wt
		for(int i=0;i<n;i++){
			for(int j=wt[i];j<=w;j++){
				if(dp[j-wt[i]]!=-2 and dp[j-wt[i]]+val[i]>dp[j]){
					dp[j]=dp[j-wt[i]]+val[i];
				}
			}
		}
		int ans=0;
		for(int i=0;i<=w;i++){
			if(ans<dp[i]){
				ans=dp[i];
			}
		}
		return ans;
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,w;
		cin>>n>>w;
		int val[n],wt[n];
		for(int i=0;i<n;i++){
			cin>>val[i];
		}
		for(int i=0;i<n;i++){
			cin>>wt[i];
		}

		Solution ob;
		cout<<ob.knapsack(n,w,val,wt)<<endl;
	}
}