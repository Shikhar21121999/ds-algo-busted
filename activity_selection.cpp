// program to give max number of meetings
// that can be held in a single room such that no meetings overlap

#include <bits/stdc++.h>
using namespace std;

bool comp(pair <int,int> a,pair <int,int> b){
	return a.second<b.second;
}

int maxMeetings(int start[],int end[],int n){

	// first we create a vector of pairs
	vector <pair < int,int > > meet(n);
	for(int i=0;i<n;i++){
		meet[i]=make_pair(start[i],end[i]);
	}
	
	// sort the meet array with respect to end time of array
	// that is the meeting that gets over soon comes first
	sort(meet.begin(),meet.end(),comp);
	
	// traverse the meet array and count the meeting that do not overlap
	int ans=0;
	int last_meet_end=0;
	for(auto x:meet){
		if(x.first>last_meet_end){
			ans++;
			last_meet_end=x.second;
		}
	}
	return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		
		int start[n],end[n];
		for(int i=0;i<n;i++)cin>>start[i];
		for(int i=0;i<n;i++)cin>>end[i];
		
		int ans=maxMeetings(start,end,n);
		cout<<ans<<endl;
	}
}
