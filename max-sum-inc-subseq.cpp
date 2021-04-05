// program to solve maximum sum increasing subsequence problem

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

class Solution
{
public:
	int maxSumIS(int arr[],int n){

		vi dp(n,0);

		dp[0]=arr[0];

		for(int i=1;i<n;i++){
			int maxTillNow=0;

			for(int j=i-1;j>=0;j--){

				if(arr[j]<arr[i]){
					maxTillNow=max(maxTillNow,dp[j]);
				}
			}
			dp[i]=maxTillNow+arr[i];
		}
		int ans=0;
		for(int i=0;i<n;i++){
			ans=max(ans,dp[i]);
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

		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}

		Solution ob;
		cout<<ob.maxSumIS(a,n)<<endl;
	}
}