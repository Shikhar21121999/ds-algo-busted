// program to find and print maximum meetings possible
// in one room

#include <bits/stdc++.h>
using namespace std;

bool comp(const vector <int> &a,const vector <int> &b){
	return a[1]>b[1];
}

void solve(){
	int n;
	cin>>n;
	
	vector <int> st(n),et(n);
	
	// input start time
	for(int i=0;i<n;i++){
		cin>>st[i];
	}
	for(int i=0;i<n;i++){
		cin>>et[i];
	}
	
	// make a vector of pair for meeting
	vector <vector <int> > meet(n,vector <int>(3,0));
	for(int i=0;i<n;i++){
		meet[i][0]=st[i];
		meet[i][1]=et[i];
		meet[i][2]=i+1;
	}
	
	// sort the meet vector wrt to ending time
	sort(meet.begin(),meet.end(),comp);
	
	// now we go through the array and include the meeting whose
	// start time is after the ending time of last meeting
	
	int last_end=meet[0][1];
	vector <int> ans;
	
	for(int i=0;i<n;i++){
		if(meet[i][0]>last_end){
			last_end=meet[i][1];
			ans.push_back(meet[i][2]);
		}
	}
	
	// sort the ans array and print
	sort(ans.begin(),ans.end());
	
	// print the ans array
	for(auto x:ans){
		cout<<x<<" ";
	}
	 
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
