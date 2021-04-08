// program to find the max path sum in a matrix

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
class Solution{
public:
	int maximumPath(int n,vvi a){
		vvi dp(n,vi(n,0));

		//filll the first row as it is of the dp
		for(int i=0;i<n;i++){
			dp[0][i]=a[0][i];
		}

		// fill rest of the row of the dp table
		for(int i=1;i<n;i++){
			for(int j=0;j<n;j++){
				if(j==0){
					dp[i][j]=max(dp[i-1][j],dp[i-1][j+1])+a[i][j];
				}
				else if(j==n-1){
					dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+a[i][j];
				}
				else{
					dp[i][j]=max(max(dp[i-1][j],dp[i-1][j-1]),dp[i-1][j+1])+a[i][j];
				}
			}
		}

		int ans=0;
		// find the max in the last row
		for(int i=0;i<n;i++){
			if(ans<dp[n-1][i])ans=dp[n-1][i];
		}
		return ans;
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vvi a(n,vi(n,0));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
			}
		}
		Solution ob;
		cout<<ob.maximumPath(n,a)<<endl;
	}
}