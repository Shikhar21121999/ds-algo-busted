// program to solve longest pallindromic substring

#include<bits/stdc++.h>
using namespace std;

#define vb vector<bool>
#define vvb vector<vb>

class Solution{
public:
	string longestPallindrome(string s){
		int n=s.length();
		vvb dp(n,vb(n,0));

		// all substring of length 1 are pallindrome
		for(int i=0;i<n;i++){
			dp[i][i]=1;
		}
		pair<int,int> ans=make_pair(1,0);

		for(int len=2;len<=n;len++){
			for(int i=0;i<=n-len;i++){
				int j=i+len-1;

				// case length is 2 and a pallindrome
				if(len==2 and s[i]==s[j]){
					dp[i][j]=1;
					if(len>ans.first){
						ans=make_pair(len,i);
					}
				}

				// if characters are same
				if(s[i]==s[j] and dp[i+1][j-1]){
					dp[i][j]=1;
					if(len>ans.first){
						ans=make_pair(len,i);
					}
				}
			}
		}

		// cout<<ans.first<<" "<<ans.second<<endl;
		string ansstr=s.substr(ans.second,ans.first);
		// cout<<ansstr<<endl;
		return ansstr;

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