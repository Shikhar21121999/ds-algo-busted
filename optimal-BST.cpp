// program to find min number of search operations
// for a given array of key and there frequency
// in an optimal bst
// assuming that key values are sorted

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

int optimalBSTCost(int key[],int freq[],int n){
	int dp[n][n];

	// create a suffix array to store the sum of frequency for subarray
	// i to j
	vi suffArray(n+1,0);
	for(int i=1;i<=n;i++){
		suffArray[i]=freq[i-1]+suffArray[i-1];
	}
	
	// for(int i=0;i<=n;i++){
	// 	cout<<suffArray[i]<<" ";
	// }
	// cout<<endl;

	// dp[i][j] represent min cost to construct bst for subarray[i..j]

	// we use gap approach here as cost of bigger bst will depend on
	// cost of smaller bst

	// cost of bst of length 1 is equal to freq of root node
	for(int i=0;i<n;i++){
		dp[i][i]=freq[i];
	}

	// calculating cost for bst of length greater than 1
	for(int len=2;len<=n;len++){
		for(int i=0;i<=n-len;i++){
			int j=i+len-1;

			// now we have a subarray in consideration
			// which has length 2 and starts at i and ends at j
			// now we check the cost of bst by making each element as root
			// one by one

			// we have to optimize or minimize cost over all such possible bst
			int optCost=INT_MAX;
			for(int r=i;r<=j;r++){
				// if first element is root then cost of left subtree will be 0
				// else cost of left subtree will be equal to cost of left subtree
				int leftCost=(r>i)?dp[i][r-1]:0;

				// if last element is root thne cost of right subtree will be 0
				// else cost of right subtree will be equal to cost of right subtree
				int rightCost=(r<j)?dp[r+1][j]:0;

				int tcost=leftCost+rightCost+suffArray[j+1]-suffArray[i];
				// cout<<i<<" "<<j<<" "<<r<<" "<<leftCost<<" "<<rightCost<<" "<<tcost<<endl;
				if(tcost<optCost){
					optCost=tcost;
				}

			}
			dp[i][j]=optCost;
		}
	}
	return dp[0][n-1];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int key[n];
		int freq[n];
		for(int i=0;i<n;i++){
			cin>>key[i];
		}
		for(int i=0;i<n;i++){
			cin>>freq[i];
		}
		cout<<optimalBSTCost(key,freq,n);
	}
}