// smallest sum contiguous subarray

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

int smallestSumContiguous(vi a,int n){
	int minTillNow=INT_MAX;
	int sumSoFar=0;

	for(int i=0;i<n;i++){
		sumSoFar+=a[i];
		if(sumSoFar<minTillNow){
			minTillNow=sumSoFar;
		}
		if(sumSoFar>0){
			sumSoFar=0;
		}
	}
	return minTillNow;
}

int main(){
	int n;
	cin>>n;
	vi a(n,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<smallestSumContiguous(a,n)<<endl;
}