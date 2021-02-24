// program to solve min cost of ropes problem
// link:https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

#include <bits/stdc++.h>
using namespace std;

long long minCost(long long arr[],long long n){
	
	// create a priority queue which gives the min values
	priority_queue<long long,vector <long long>,greater<long long> >pq;
	
	// push all the values into the priority_queue
	for(int i=0;i<n;i++){
		pq.push(arr[i]);
	}
	// now we pop out two ropes of min length
	// then we add them and push them back into the vector
	
	long long ans=0;
	while(pq.size()>1){
		long long first=pq.top();
		pq.pop();
		long long second=pq.top();
		pq.pop();
		ans+=first+second;
		pq.push(first+second);
	}
	return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		long long i,a[n];
		for(i=0;i<n;i++){
			cin>>a[i];
		}
		cout<<minCost(a,n)<<endl;
	}
	return 0;
}
