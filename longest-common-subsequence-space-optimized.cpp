// program to solve longest commone subsequence
// in space optimized way

// Time complexity : O(N*N)
// Space complexity : O(N)

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>

// iterative bottom up approach dp
// space optimization
int longestCommonSubseq(string s1,string s2){
	int n=s1.length();
	int m=s2.length();
	vvi dp(2,vi(s2.length()+1,0));

	int bi=0;
	for(int i=1;i<=n;i++){
		// we have to toggle curr and prev row from dp each and every time
		bi=!bi;
		for(int j=1;j<=m;j++){
			
			// if character matches
			if(s1[i]==s2[j]){
				dp[bi][j]=1+dp[!bi][j-1];
			}

			// if characer do not match
			else{
				dp[bi][j]=max(dp[bi][j-1],dp[!bi][j]);
			}
		}
	}
	return dp[bi][m];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string s1,s2;
		cin>>s1>>s2;
		cout<<longestCommonSubseq(s1,s2)<<endl;
	}
}