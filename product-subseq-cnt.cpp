// program to count number of subsequences
// such that the product of elements in subsequence is less than k

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>

int productCountSubseq(vi &a,int k){
	int n=a.size();
	vvi dp(k+1,vi(n+1,0));

	// dp[i][j] represent number of subsequences possible
	// including j which have product less than or equal to i

	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){

			// subsequences without including current element
			dp[i][j]=dp[i][j-1];

			// see if its possible to include this element to get product
			// less than i
			if(a[j-1]<=i and a[j-1]>0){
				dp[i][j]+=dp[i/a[j-1]][j-1]+1;
			}
		}
	}
	return dp[k][n];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vi a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int k;
		cin>>k;
		cout<<productCountSubseq(a,k)<<endl;
	}
}