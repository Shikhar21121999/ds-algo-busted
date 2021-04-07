// program to find the longest subseq such that difference
// between adjacent element is one

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

class Solution{
public:
int longestSubsequence(int n, int a[])
    {
        // code here
        vi dp(n,1);

        // dp[i] denote the longest subsequence with diff between adjacent element 1
        // ending at index i
        for(int i=1;i<n;i++){
        	for(int j=0;j<i;j++){
        		// j denote the current element try to include in the subseq
        		if(abs(a[j]-a[i])==1){
        			dp[i]=max(dp[i],dp[j]+1);
        		}
        	}
        }
		
		// find the max in all the dp
		int ans=1;
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
		cout<<ob.longestSubsequence(n,a);
	}
}