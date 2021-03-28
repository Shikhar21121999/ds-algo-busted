// program to find the solution for 0-1 knapsack problem

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vvpii>
#define ll long long
#define vll vector<ll>

class Solution
{
public:
	int knapsack(int W,int wt[],int val[],int n){

		int max_sum=0;
		// find the sum of all the values
		for(int i=0;i<n;i++){
			max_sum+=val[i];
		}

		// create a dp array of values
		// which represents the min wt required to achieve
		// a particular value
		vll dp(max_sum+1,INT_MAX);

		// min wt required to get value 0 is zero
		// dp[0]=0;
		// for(int i=max_sum;i>=0;i--){
		// 	for(int j=0;j<n;j++){
		// 		dp[i]=min(dp[i],dp[i-val[j]]+wt[j]);
		// 	}
		// }

		for(int i=0;i<n;i++){
			for(int j=max_sum;j>=0;j--){
				if(j>=val[i]){
					dp[j]=min(dp[j],dp[j-val[i]]+wt[i]);					
				}
			}
		}

		int ans=0;
		// iterate throug to get the max value that can be attained
		// such that wt is lesser or equal to W
		for(int i=0;i<max_sum+1;i++){
			// cout<<i<<" "<<dp[i]<<endl;
			if(dp[i]<=W){
				ans=max(ans,i);
			}
		}
		return ans;
	}

	int knapsack1(int W,int wt[],int val[],int n){
		// we do this by maximizing value for a particular wt
		vll dp(W+1,0);

		for(int i=0;i<n;i++){

			for(int wt_already=W-wt[i];wt_already>=0;wt_already--){
				dp[wt_already+wt[i]]=max(dp[wt_already+wt[i]],dp[wt_already]+val[i]);
			}
		}

		long long int ans=0;
		// find the max value till the wt
		for(int i=0;i<W+1;i++){
			ans=max(dp[i],ans);
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
		cout<<n<<" "<<w<<endl;

		int val[n];
		int wt[n];

		// Inserting the values
		for(int i=0;i<n;i++){
			cin>>val[i];
			cout<<val[i]<<" ";
		}
		cout<<endl;

		// Inserting the wieghts
		for(int i=0;i<n;i++){
			cin>>wt[i];
			cout<<wt[i]<<" ";
		}
		cout<<endl;

		Solution ob;
		cout<<ob.knapsack(w,wt,val,n)<<endl;

	}
	return 0;
}