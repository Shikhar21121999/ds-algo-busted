//program to find the number of combination ways to reach a given score in a game
// link:https://practice.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll count(ll n){
	ll dp[n+1],i;
	memset(dp, 0, sizeof(dp));
	dp[0]=1; 

	int arr[3]={3,5,10};
	for(int i=0;i<3;i++){
		for(int j=arr[i];j<=n;j++){
			if(dp[j-arr[i]]>=1){
				dp[j]+=dp[j-arr[i]];
			}
		}
	}

	return dp[n];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
}