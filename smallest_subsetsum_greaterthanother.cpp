// program to determine smallest subset
// whoose sum is greate than all other elements

#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	
	vector <int> a(n);
	int t_sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		t_sum+=a[i];
	}
	
	sort(a.begin(),a.end(),greater<int>());
	
	// traverse through the array till you find sum
	// which is greater than half of the array
	int c_sum=0;
	int ans=0;
	for(int i=0;i<n;i++){
		c_sum+=a[i];
		if(c_sum>t_sum/2){
			ans=i+1;
		}
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
