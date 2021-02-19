// program to give max and min amount to be spent to buy
// all the candies in a store

#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,k;
	cin>>n>>k;
	
	vector <int> candy(n);
	
	for(int i=0;i<n;i++){
		cin>>candy[i];
	}
	
	// sort the candy_store array
	sort(candy.begin(),candy.end());
	
	int min_candy=0;
	// calculate the candies that he will have to buy
	if(n%(k+1)!=0)min_candy=(n/(k+1))+1;
	else min_candy=n/(k+1);
	
	// for minimum price add first min_candy price
	int min_price=0;
	for(int i=0;i<min_candy;i++){
		min_price+=candy[i];
	}
	
	int max_price=0;
	// for max price add last min_candy price
	for(int i=n-1;i>n-1-min_candy;i--){
		max_price+=candy[i];
	}
	cout<<min_price<<" "<<max_price<<"\n";
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
