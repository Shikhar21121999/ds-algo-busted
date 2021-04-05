// program to solve longest increasing subsequence problem

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

class Solution
{
public:
	// O(N log N) solution
	int longestSubsequence(int n,int a[]){
		// make a dp array
		vi dp(n,0);
		int length=1;
		dp[0]=a[0];

		for(int i=1;i<n;i++){

			// find the index of the element just greater than a[i] in dp
			auto it=lower_bound(dp.begin(),dp.begin()+length,a[i]);

			// in case the element is greatest encountered till now
			if(it==dp.begin()+length){
				dp[length++]=a[i];
			}
			else{
				*it=a[i];
			}
		}
		return length;
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