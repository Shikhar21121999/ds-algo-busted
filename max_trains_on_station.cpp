// program to calculate max trains for which stoppage can be provided
// Link:https://www.geeksforgeeks.org/maximum-trains-stoppage-can-provided/

#include <bits/stdc++.h>
using namespace std;

bool comp(const vector <int> &a,const vector <int> &b){
	return a[1]<b[1];
}

int solve(){
	// n is no of plateform and m is no of train data
	int n,m;
	cin>>n>>m;
	
	vector <vector <int> > train_sched(m,vector <int>(3));
	int arr,dep,plat_no;
	for(int i=0;i<m;i++){
		cin>>arr>>dep>>plat_no;
		train_sched[i][0]=arr;
		train_sched[i][1]=dep;
		train_sched[i][2]=plat_no;
	}
	
	// sort the train sched depending on the train that leaves the 
	// station first
	sort(train_sched.begin(),train_sched.end(),comp);
	
	// a vector to store the time of last left train
	vector <int> last_left(n+1,0);
	
	int ans=0;
	
	// traverse the train_sched
	// for every train check if the plateform it has to occupy is empty
	for(auto x:train_sched){
		if(x[0]>last_left[x[2]]){
			ans+=1;
			last_left[x[2]]=x[1];
		}
	}
	
	return ans;

}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
