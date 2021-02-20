// program to maximize sum of arr[i]*i
// we can re-arrange the numbers so as to maximize the sum

#include <bits/stdc++.h>
using namespace std;

int mod=1e9+7;

int Maximize(int a[],int n){
	// sort the array in decreasing order
	sort(a,a+n,greater<int>());
	
	int ans=0;
	int curr_sum=0;
	for(int i=0;i<n;i++){
		curr_sum=((a[i]%mod)*(i%mod))%mod;
		ans=(ans+curr_sum)%mod;
	}
	return ans;
}

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
		cout<<Maximize(a,n)<<endl;
	}
}
