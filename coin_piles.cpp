// question link: https://practice.geeksforgeeks.org/problems/coin-piles/0

#include <bits/stdc++.h>
using namespace std;

void solve(){
	// number of coin piles and k respectively
	int n,k;
	cin>>n>>k;
	
	// input coin piles array
	vector <int> coin_arr(n);
	for(int i=0;i<n;i++){
		cin>>coin_arr[i];
	}
	
	// sort the array
	sort(coin_arr.begin(),coin_arr.end());
	cout<<"print sorted array \n";
	for(auto x:coin_arr){
		cout<<x<<" ";
	}
	cout<<"\n";
	
	// creating a prefix_sum array
	vector <int> psa(n);
	psa[0]=coin_arr[0];
	for(int i=1;i<n;i++){
		psa[i]=psa[i-1]+coin_arr[i];
	}
	cout<<"printing the psa\n";
	for(auto x:psa){
		cout<<x<<" ";
	}
	cout<<"\n";
	
	int c1,c2=INT_MAX,tempc1=0,tempc2=0;
	int i=0;
	
	// traverse for each element
	while(i<n){
		
		// get the index of first coin pile
		// that voilates the condition
		int pos=upper_bound(coin_arr.begin(),
			coin_arr.end(),coin_arr[i]+k)-coin_arr.begin();
		
		if(pos==n){
			// there is no coin piles that voilates the condition
			// implies that none combination voilate the condition
			// as the array are sorted
			break;
		}
		
		// now the condition is voilated and we have to satisfy it
		// it can be done in two ways
		
		// remove the whole pile of coins (smaller one)
		tempc1=coin_arr[i];
		
		// or ensure that all the piles that have coins more than arr[i]+k
		// get the coins equal to arr[i]+k by removing coins from each
		// one of them
		tempc2=(psa[n-1]-psa[pos-1])-((coin_arr[i]+k)*(n-pos));
		
		// tempc1 represent coins to be removed for first way
		// tempc2 represent coins to be removed for second way
		
		// taking the min. of both
		c2=min(c2,tempc2+c1);
		c1+=tempc1;
		i++;
	}
	cout<<min(c1,c2)<<"\n";	
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}



