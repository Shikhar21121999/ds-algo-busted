// program to find the max sum after k negotations

#include <bits/stdc++.h>
using namespace std;

long long getMin(vector <long long> a){
	int ind=-1;
	long long min_el=INT_MAX;
	for(int i=0;i<a.size();i++){
		if(a[i]<min_el){
			ind=i;
			min_el=a[i];
		}
	}
	return ind;
}

long long getSum(vector <long long> a){
	long long sum=0;
	for(auto x:a){
		sum+=x;
	}
	return sum;
}


void solve(){
	int n,k;
	cin>>n>>k;
	
	vector <long long> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	sort(a.begin(),a.end());
	
	// traverse the array and keep converting all the -ve elements
	int i=0;
	while(i<n and k>0){
		
		// if a positive number break
		if(a[i]>=0){
			break;
		}
		
		// if negative number convert it into +ve
		if(a[i]<0){
			a[i]=-1*a[i];
			k--;
		}
		i++;
	}
	
	if(k>0 and k%2!=0){
		// find the min element of the array and make it negative
		// then find the sum of the array and return it
		int min_ind=getMin(a);
		a[min_ind]=-1*a[min_ind];
	}
	cout<<getSum(a);

}
		

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
