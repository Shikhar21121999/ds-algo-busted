// program to solve longest pallindromic subsequence

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define vll vector<ll>
#define vvll vector<vector<ll>>

// function to calculate lps using bottom up
// iterative dp
int lps1(string inp){
	int n=inp.length();
	vvll dp(n,vll(n,0));
	int m=1e9+7;
	int cnt=n;
	for(int i=0;i<n;i++){
		dp[i][i]=1;
	}

	for(int len=2;len<=n;len++){
		for(int i=0;i<=n-len;i++){
			int j=i+len-1;
			if(inp[i]==inp[j]){
				dp[i][j]=(1+dp[i][j-1]%m+dp[i+1][j]%m)%m;
			}
			else{
				dp[i][j]=(dp[i][j-1]%m+dp[i+1][j]%m-dp[i+1][j-1])%m;
			}
		}
	}
	return dp[0][n-1];
}

int main(){
	string inp;
	cin>>inp;
	cout<<lps1(inp)<<endl;
}