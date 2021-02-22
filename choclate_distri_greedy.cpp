// program to find the minimum difference between max. and 
// min. choclate packet distributed among students

#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	
	vector <long long> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	int m;
	cin>>m;
	
	sort(a.begin(),a.end());
	
	// next we iterate the array and find the min_diff
	// between packet at a seperation of m
	long long ans=INT_MAX;
	for(int i=0;(m+i-1)<n;i++){
		ans=min(ans,a[m+i-1]-a[i]);
	}
	cout<<ans<<"\n";
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
