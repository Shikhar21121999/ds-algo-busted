// program to find the size of largest square formed in a binary matrix
// a square is valid only if all the values in it are 1

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

class Solution{
public:
	int maxSquare(int n,int m,vvi a){

		vvi dp(n,vi(m,0));

		// copy first row and column as it is
		for(int i=0;i<n;i++){
			dp[i][0]=a[i][0];
		}
		for(int j=0;j<m;j++){
			dp[0][j]=a[0][j];
		}

		// fill the dp using bottom up itterative approach
		for(int i=1;i<n;i++){
			for(int j=1;j<m;j++){

				// if a[i][j]==1
				if(a[i][j]==1){
					dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
				}
				else{
					dp[i][j]=0;
				}
			}
		}

		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(ans<dp[i][j]){
					ans=dp[i][j];
				}
			}
		}
		return ans;
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vvi matr(n,vi(m,0));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>matr[i][j];
			}
		}
		Solution ob;
		cout<<ob.maxSquare(n,m,matr)<<endl;
	}
}
