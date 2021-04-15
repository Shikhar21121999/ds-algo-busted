// program to solve weighted job scheduling problem

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

class Job{
public:
	int start,endtime,profit;
};

int binarySearch(vector<Job> sched,int index){
	int lo,hi,mid;
	lo=0;
	hi=index-1;
	while(lo<=hi){
		mid=(lo+hi)/2;

		if(sched[mid].endtime<=sched[index].start){
			if(sched[mid+1].endtime<=sched[index].start){
				lo=mid+1;
			}
			else{
				return mid;
			}
		}
		else{
			hi=mid-1;
		}
	}
	return -1;
}

bool comp(Job a,Job b){
	return (a.endtime<=b.endtime);
}

int maxProfitJobScheduling(vector<Job> sched,int n){

	// sort the sched according to the endtime of the job
	sort(sched.begin(),sched.end(),comp);

	// dp[i] store the maximum profit achievable
	// till job i
	vi dp(n,0);
	dp[0]=sched[0].profit;

	// now we get the max profit achievable till ith  index
	for(int i=0;i<n;i++){

		// profit including current job
		int inclprof=sched[i].profit;
		int l=binarySearch(sched,i);
		if(l!=-1){
			inclprof+=dp[l];
		}

		// get maximum profit achievable by finding max of including current job
		// and excluding it
		dp[i]=max(inclprof,dp[i-1]);
	}
	return dp[n-1];
}

int main(){
	int n;
	cin>>n;
	vector<Job> list(n);
	int a,b,c;
	for(int i=0;i<n;i++){
		cin>>a>>b>>c;
		list[i].start=a;
		list[i].endtime=b;
		list[i].profit=c;
	}

	// printing the job list
	for(int i=0;i<n;i++){
		cout<<list[i].start<<" "<<list[i].endtime<<" "<<list[i].profit<<endl;
	}

	cout<<maxProfitJobScheduling(list,n)<<endl;
	return 0;
}
