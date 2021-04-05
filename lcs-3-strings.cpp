// program to print longest common subsequences in three strings

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
int LCSof3(string A,string B,string C,int n1,int n2,int n3){

	// create a 3d vector
	vvvi dp(n1+1,vvi(n2+1,vi(n3+1,0)));

	for(int i=0;i<=n1;i++){
		for(int j=0;j<=n2;j++){
			for(int k=0;k<=n3;k++){

				// base case
				if(i==0 || j==0 || k==0){
					dp[i][j][k]=0;
				}

				// character match
				else if(A[i-1]==B[j-1] && B[j-1]==C[k-1]){
					// cout<<i<<" "<<j<<" "<<k<<endl;
					// cout<<A[i]<<" "<<B[j]<<" "<<C[k]<<endl;
					dp[i][j][k]=1+dp[i-1][j-1][k-1];
				}

				// character do not match
				else{
					dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
				}
			}
		}
	}
	return dp[n1][n2][n3];

}

int main(){
	int t;
	cin>>t;
	while(t--){
		string s1,s2,s3;
		cin>>s1>>s2>>s3;
		cout<<LCSof3(s1,s2,s3,s1.length(),s2.length(),s3.length());
	}
}