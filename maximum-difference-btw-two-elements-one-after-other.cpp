// proagram to find maximum difference between two elements such that larger element appears after the smaller number
// link::https://www.geeksforgeeks.org/maximum-difference-between-two-elements/

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

// naieve solution
int maxSumffdiff1(vi a,int n){
	int maxDiff=INT_MIN;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[j]-a[i]>maxDiff){
				maxDiff=a[j]-a[i];
			}
		}
	}
	return maxDiff;
}

// min fixed solution
int maxSumffdiff2(vi a,int n){
	int gmin=a[0];
	int maxDiff=a[1]-a[0];
	for(int i=1;i<n;i++){
		if(a[i]-gmin>maxDiff){
			maxDiff=a[i]-gmin;
		}
		if(a[i]<gmin){
			gmin=a[i];
		}
	}
	return maxDiff;
}

// max fixed solution
int maxSumffdiff3(vi a,int n){
	int gmax=a[n-1];
	int maxDiff=a[n-1]-a[n-2];
	for(int i=n-2;i>=0;i--){
		if(gmax-a[i]>maxDiff){
			maxDiff=gmax-a[i];
		}
		if(a[i]>gmax){
			gmax=a[i];
		}
	}
	return maxDiff;
}

// subarray approach
int maxSumffdiff4(vi a,int n){
	vi dp(n-1);
	for(int i=0;i<n-1;i++){
		dp[i]=a[i+1]-a[i];
	}

	// apply kadane's algo to find subarray sum
	int sumSoFar=0;
	int maxSumTillNow=INT_MIN;
	for(int i=0;i<n-1;i++){
		sumSoFar+=dp[i];
		if(sumSoFar>maxSumTillNow){
			maxSumTillNow=sumSoFar;
		}
		if(sumSoFar<0){
			sumSoFar=0;
		}
	}
	return maxSumTillNow;
}

int main(){
	int n;
	cin>>n;
	vi a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<maxSumffdiff1(a,n)<<endl;
	cout<<maxSumffdiff2(a,n)<<endl;
	cout<<maxSumffdiff3(a,n)<<endl;
	cout<<maxSumffdiff4(a,n)<<endl;

}