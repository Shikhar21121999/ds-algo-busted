// program to calculate maximum profit by buying and selling shares
// given that unlimitted transactions can be made

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

int maxProfit(vi a,int n){
	int maxprofit=0;
	for(int i=0;i<n-1;i++){
		if(a[i+1]>a[i]){
			maxprofit+=a[i+1]-a[i];
		}
	}
	return maxprofit;
}

int main(){
	int n;
	cin>>n;
	vi a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	cout<<maxProfit(a,n)<<endl;
}