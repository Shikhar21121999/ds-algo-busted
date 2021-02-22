// program to solve die hard problem
// Link:https://www.spoj.com/problems/DIEHARD/

#include <bits/stdc++.h>
using namespace std;
vector <vector <vector <int> > > cat;

int recur(int h,int a,int p){
	
	if(h<=0 or a<=0){
		return -1;
	}
	
	// if already computed
	if(cat[h][a][p]!=-2)return cat[h][a][p];
	
	
	if(p!=0){
		// previous was not wind so we can take wind now
		return cat[h][a][p]=recur(h+3,a+2,0)+1;
	}
	if(p==0){
		int t_f=recur(h-20,a+5,2);
		int t_w=recur(h-5,a-10,1);
		return cat[h][a][p]=max(t_f,t_w)+1;
	}
}

void solve(){
	int h,a;
	cin>>h>>a;
	cat.resize(h*h,vector < vector <int> >(a*a,vector <int>(5,-2)));
	// vector<vector<vector<int> > > vec (5,vector<vector<int> >(3,vector <int>(2,4)));
	
	cout<<recur(h,a,3)<<"\n";
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
