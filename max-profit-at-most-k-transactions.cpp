// program to find and calculate maximum profit that can be attained
// by buying and selling stocks at most k transactions

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

class Solution{
public:
	int maxProfit(vi p,int n,int k){

		// make a vvi dp
		// where dp[i][j] denote max profit attainable by
		// at most i transactions in j days

		vvi dp(k+1,vi(n+1,0));

		// max profit when 0 transactions are made is 0
		for(int i=0;i<=n;i++){
			dp[0][i]=0;
		}

		// max profit on 0th day is zero as we can only buy and sell the stock
		// at same price hence no profit
		for(int i=0;i<=k;i++){
			dp[i][0]=0;
		}

		// filling the dp array
		// recursive formula for dp[i][j] :
		// dp[i][j]=max(dp[i][j-1],max(dp[i-1][k]+price[j]-price[k]))
		// that is we either made all the transactions before the current day
		// or we made a total of i-1 transactions at a particular day
		// and made last transaction by buying stock at that day and selling it today

		for(int i=1;i<=k;i++){
			int maxSoFar=INT_MIN;
			for(int j=1;j<n;j++){
				// update maxSoFar
				maxSoFar=max(maxSoFar,dp[i-1][j-1]-p[j-1]);
				dp[i][j]=max(dp[i][j-1],maxSoFar+p[j]);
			}
		}

		return dp[k][n-1];
	}
};

int main(){
	int n;
	cin>>n;
	vi a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int k;
	cin>>k;
	Solution ob;
	cout<<ob.maxProfit(a,n,k)<<endl;
}