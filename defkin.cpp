// program to give answer of defence of a kingdom problem
// link: https://www.spoj.com/problems/DEFKIN/

#include <bits/stdc++.h>
using namespace std;

void solve(){
	int w,h,n;
	cin>>w>>h>>n;
	
	vector <int> x(n+1),y(n+1);
	
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
	}
	x[n]=w+1;
	y[n]=h+1;
	
	// sort x and y lists
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	
	// find the max diff btw consicutive x
	// find the max diff btw consicutive y
	int max_del_x=x[0];
	int max_del_y=y[0];
	
	for(int i=1;i<=n;i++){
		max_del_x=max(max_del_x,(x[i]-x[i-1]));
		max_del_y=max(max_del_y,(y[i]-y[i-1]));
	}
	cout<<(max_del_x-1)*(max_del_y-1)<<endl;
}
	

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}

