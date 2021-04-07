// maximum sum subsequence such that no three elements are consecutive

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

int maxSumSubseq(vi a,int n){

	vi dp(n,0);
	// cout<<a[0];

	if(n>=1){
		dp[0]=a[0];
	}
	if(n>=2){
		dp[1]=a[0]+a[1];
	}
	if(n>=3){
		dp[2]=max(dp[1],max(a[0]+a[2],a[1]+a[2]));
	}

	for(int i=3;i<n;i++){
		int p=dp[i-1];	// exclude a[i]
		int q=dp[i-2]+a[i]; // exclude a[i-1]
		int r=dp[i-3]+a[i-1]+a[i]; //exclude a[i-2]

		dp[i]=max(p,max(q,r));
	}

	return dp[n-1];
}

int main(){
	int n;
	cin>>n;
	vi a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		cout<<a[i]<<" ";
	}
	cout<<endl;
	// printarr(a,n);

	cout<<maxSumSubseq(a,n)<<endl;
}
