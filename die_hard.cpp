// program to solve die hard problem
// Link:https://www.spoj.com/problems/DIEHARD/
//1 - air 		h += 3 a+= 2
//2 - water		h-= 5  a -= 10
//3 - fire		h-=20 a+= 5


#include <bits/stdc++.h>
using namespace std;
vector <vector <int> > dp(1000,vector <int>(1018,-1));

int recur(int h,int a){
	int t=0;
	if(h<=0 or a<=0){
		return 0;
	}
	
	if(dp[h][a] != -1) {
		return dp[h][a];
	}
		
	if(h>20){
		// we can take two steps first fire than air
		t=max(t,2+recur(h-17,a+7));
	}
	if(h>5 and a>10){
		// we can take two steps first water than air
		t=max(t,2+recur(h-2,a-8));
	}
	return dp[h][a]=t;
}

void solve(){
	int h,a;
	cin>>h>>a;
	int ans=recur(h+3,a+2)+1;
	cout<<ans<<"\n";
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
