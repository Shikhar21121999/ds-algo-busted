// program to find the max diff that can be achived such that
// all the pairs have a difference of less than or equal to k between them

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>

class Solution{
public:
	int maxSumPairWithDifferenceLessThanK(int arr[],int n,int k){
		// declare a dp array of size n
		if(n==1)return 0;
		vi dp(n,0);
		sort(arr,arr+n);

		for(int i=1;i<n;i++){
			dp[i]=dp[i-1];
			if(arr[i]-arr[i-1]<k and dp[i]<dp[i-2]+arr[i-1]+arr[i]){
				// cout<<"a match is found\n"<<arr[i]<<" "<<arr[i-1]<<endl;
				if(i>=2)dp[i]=dp[i-2]+arr[i-1]+arr[i];
				else{
					dp[i]=arr[i]+arr[i-1];
				}
			}
		}
		// for(int i=0;i<n;i++)cout<<dp[i]<<" ";
		return dp[n-1];
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int k;
		cin>>k;
		Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,n,k)<<endl;
	}
}