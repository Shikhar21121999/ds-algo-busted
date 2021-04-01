// program to find if it is possible
// to partition the array into two equal subsets

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int equalPartition(int N,int arr[]){

		int maxsum=0;
		for(int i=0;i<N;i++){
			maxsum+=arr[i];
		}
		if(maxsum%2){
			return 0;
		}
		vector<int> subsum(maxsum+1,0);
		subsum[0]=1;
		for(int i=0;i<N;i++){
			// elements of the array
			for(int j=maxsum;j>=0;j--){
				if(subsum[j-arr[i]]==1){
					subsum[j]=1;
				}
			}
		}
		for(int i=0;i<=maxsum;i++){
			cout<<subsum[i]<<" ";
		}
		cout<<endl;
		return subsum[maxsum/2];
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
		Solution ob;
		cout<<ob.equalPartition(n,arr)<<endl;
	}
	return 0;
}