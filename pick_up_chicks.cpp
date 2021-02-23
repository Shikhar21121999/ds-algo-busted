// program to solve pick_up_chicks
// link:https://www.spoj.com/problems/GCJ101BB/

#include <bits/stdc++.h>
using namespace std;

void solve(){
	
	long long n,k,b,t;
	cin>>n>>k>>b>>t;
	
	vector <long long> x(n);
	vector <long long> v(n);
	vector <bool> finished(n);
	
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	
	// create finished vector
	long long eff_dis=0;
	float eff_time=0;
	for(int i=0;i<n;i++){
		eff_dis=b-x[i];
		eff_time=float(eff_time/v[i]);
		if(eff_time<=t){
			finished[i]=true;
		}
	}
	
	// printing vectors in line
	for(auto a:x){
		cout<<a<<" ";
	}
	cout<<"\n";
	for(auto a:v){
		cout<<a<<" ";
	}
	cout<<"\n";
	for(auto a:finished){
		cout<<a<<" ";
	}
	cout<<"\n";
}
	
int main(){
	int c;
	cin>>c;
	while(c--){
		solve();
	}
	return 0;
}
