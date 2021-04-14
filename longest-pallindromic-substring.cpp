// program to solve longest pallindromic substring

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vpii>

class Solution{
public:
	pii maxF(pii a,pii b){
		if(a.first>=b.first)return a;
		return b;
	}
	string longestPallindrome(string s){
		int n=s.length();
		vvpii dp(n,vpii(n));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dp[i][j]=make_pair(1,i);
			}
		}

		for(int len=2;len<=n;len++){
			for(int i=0;i<=n-len;i++){
				int j=i+len-1;
				// length of substring is 2
				if(len==2 and s[i]==s[j]){
					dp[i][j]=make_pair(2,i);
				}

				else if(s[i]==s[j]){
					dp[i][j]=dp[i+1][j-1];
					if(s[i+1]==s[j-1]){
						dp[i][j]=make_pair(dp[i][j].first+2,i);
					}
				}
				else{
					dp[i][j]=maxF(dp[i][j-1],dp[i+1][j]);
				}

			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<dp[i][j].first<<","<<dp[i][j].second<<"  ";
			}
			cout<<endl;
		}
		cout<<dp[0][n-1].first<<" "<<dp[0][n-1].second<<endl;
		string ans=s.substr(dp[0][n-1].second,dp[0][n-1].first);
		// cout<<ans<<endl;
		return ans;
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		string inp;
		cin>>inp;
		Solution ob;
		cout<<ob.longestPallindrome(inp)<<endl;
	}
	return 0;
}