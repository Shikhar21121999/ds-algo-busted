// program to solve longest common subsequence problem

#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

class Solution
{
public:
	int lcs(int x,int y,string s1,string s2){
		vector<vector<int> > dp(x,vector<int>(y,0));

		for(int i=0;i<x;i++){
			for(int j=0;j<y;j++){

				// base case
				if(x==0 || y==0){
					dp[i][j]=0;
				}

				// characters match case
				else if(s1[i]==s2[j]){
					dp[i][j]=1+dp[i-1][j-1];
				}

				// characters do not match
				else{
					dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
				}
			}
		}

		return dp[x-1][y-1];
	}
};

int main(){
	int t,x,y;
	cin>>t;
	while(t--){
		cin>>x>>y;
		string s1,s2;
		cin>>s1>>s2;				
		Solution ob;
		cout<<x<<" "<<y<<endl;
		cout<<s1<<" "<<s2<<endl;
		cout<<ob.lcs(x,y,s1,s2)<<endl;
	}
}