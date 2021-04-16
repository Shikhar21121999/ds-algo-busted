// maximum profit achievable by buying and selling atmost twice
// link:https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-twice/

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

int maxProfitTwice(vi a,int n){
	vi dp(n,0);

	// calculating max profit achievable by buying
	// share at i and selling it before n-1
	int maxprice=a[n-1];
	for(int i=n-2;i>=0;i--){
		if(a[i]>maxprice){
			maxprice=a[i];
		}
		dp[i]=max(dp[i+1],maxprice-a[i]);
	}

	// now dp[i] storest the max profit achievable for i to n-1 in 1 transaction

	// now we find the max profit achivable from 0toi in 1 transaction
	// and use it to compute max profit achievable in two transaction 
	// if one stock is sold at i
	int minprice=a[0];
	for(int i=1;i<n;i++){
		if(a[i]<minprice){
			minprice=a[i];
		}
		dp[i]=max(dp[i-1],dp[i]+a[i]-minprice);
	}
	return dp[n-1];
}

int main(){
	int n;
	cin>>n;
	vi a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];	
		// cout<<a[i]<<" ";
	}
	cout<<maxProfitTwice(a,n);
}