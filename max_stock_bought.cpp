// program to find max stock that can be bought

#include <bits/stdc++.h>
using namespace std;

int solve(int price[],int n,int k){
	
	// first we create a vector of price and max_stock
	// that can be bought on each day
	
	vector <pair <int,int>> cat(n);
	for(int i=0;i<n;i++){
		cat[i]=make_pair(price[i],i+1);
	}
	
	//sort the catalog array
	sort(cat.begin(),cat.end());
	
	int stock_bought=0;
	// iterate over the catalgue array and but max stocks that can be bought0
	for(auto x:cat){
		// we can buy a max of x.second stock if we have limmited stock
		// max stock that we can buy with current money
		int curr_stock_buy=k/x.first;
		curr_stock_buy=min(curr_stock_buy,x.second);
		stock_bought+=curr_stock_buy;
		k-=curr_stock_buy*x.first;
	}
	return stock_bought;
	
}


int main(){
	int n,k;
	cin>>n>>k;
	
	int price[n];
	for(int i=0;i<n;i++){
		cin>>price[i];
	}
	cout<<solve(price,n,k);
}
