// program to solve longest repeated subsequence

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
class Solution{
public:
	int longestRepeatingSubsequence(string str){
		string cpy=str;
		int n=str.length();
		vvi dp(n+1,vi(n+1,0));
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){

				// recursive case character match
				if(str[i-1]==cpy[j-1] && i!=j){
					dp[i][j]=1+dp[i-1][j-1];
				}

				// recursive case characters do not match
				else{
					dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
				}
			}
		}
		return dp[n][n];
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestRepeatingSubsequence(str)<<endl;
	}
}