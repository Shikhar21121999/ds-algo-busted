// program to solve longest pallindromic subsequence

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>

// function to calculate lps using bottom up
// iterative dp
int lps1(string inp){
	int n=inp.length();
	vvi dp(n,vi(n,1));

	for(int len=2;len<=n;len++){
		for(int i=0;i<=n-len;i++){
			int j=i+len-1;
			// case 1 length of the string is 2 and characters match
			if(len==2 && inp[i]==inp[j]){
				dp[i][j]=2;
			}

			// case 2 characters match
			if(inp[i]==inp[j]){
				dp[i][j]=dp[i+1][j-1]+2;
			}
			else{
				dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
			}
		}
	}
	return dp[0][n-1];
}

// find lps using lcs
int lps2(string inp){
	string cp=inp;
	reverse(cp.begin(),cp.end());

	int n=inp.length();
	vvi dp(n+1,vi(n+1,0));

	// now we need to find lcs of inp and cp
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			// if characters match
			if(inp[i-1]==cp[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else{
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[n][n];
}

int main(){
	string inp;
	cin>>inp;
	cout<<lps2(inp)<<endl;
}