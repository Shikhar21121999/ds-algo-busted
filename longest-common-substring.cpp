// program to find longest common substring

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
class Solution{
public:
	int longestCommonSubstr(string s1,string s2,int n,int m){
		vvi dp(n+1,vi(m+1,0));

		// fill the dp array
		// dp of i,j represent longest common suffix till i and j
		int result=0;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				if(i==0 || j==0){
					// for 0 row and 0 col problem is not defined
					dp[i][j]=0;
				}

				// if characters match
				else if(s1[i-1]==s2[j-1]){
					dp[i][j]=dp[i-1][j-1]+1;
					result=max(result,dp[i][j]);
				}
				else{
					dp[i][j]=0;
				}
			}
		}
		return result;
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		string s1,s2;
		cin>>s1>>s2;
		Solution ob;
		cout<<ob.longestCommonSubstr(s1,s2,s1.length(),s2.length())<<endl;
	}
}