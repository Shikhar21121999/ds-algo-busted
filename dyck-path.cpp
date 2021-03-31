// program to find nth catalan number

#include<bits/stdc++.h>
using namespace std;

long long getNthNum(int n){
// recursive dp bottom up function to find nth catalan number

	vector<long long> dp(n+1,0);
	dp[0]=dp[1]=1;

	for(int i=1;i<n;i++){
		// here we calculate i+1 catalan number
		for(int j=0;j<=i;j++){
			dp[i+1]+=dp[j]*dp[i-j];
		}
	}

	// for(int i=0;i<n;i++){
	// 	cout<<dp[i]<<" ";
	// }
return dp[n];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<getNthNum(n)<<endl;
	}
}
