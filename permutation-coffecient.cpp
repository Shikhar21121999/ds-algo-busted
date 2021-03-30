// program to find permutation coefficient or value of nPr

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vvpii>
#define ll long long
#define vll vector<ll>


int permutCoeff(int n,int k){
	// function to calculate nPr

	int ans=1;
	for(int i=n-k+1;i<=n;i++){
		ans*=i;
	}
	return ans;
}

int permutCoeffDp(int n,int k){
	// use formula
	// P(n,k) = P(n-1,k)+k*P(n-1,k-1)
	// to calcuate answer

	vi dp(k+1,0);
	for(int i=0;i<=n;i++){
		for(int j=0;j<=min(i,k);j++){
			if(j==0)dp[j]=1;
			else{
				dp[j]=dp[j]+j*dp[j-1];
			}
			dp[j+1]=0;
		}
	}
	// for(int i=0;i<=k;i++)cout<<dp[i]<<" ";
	// cout<<endl;
	return dp[k];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;

		cout<<permutCoeff(n,k)<<endl;
		cout<<permutCoeffDp(n,k)<<endl;
	}
}