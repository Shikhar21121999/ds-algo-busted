// program to find if it is possbile
// to partition the array into k-equal subsets
// such that there sum is equal and each element is present
// in exactly one subset

#include <bits/stdc++.h>
using namespace std;
# define vi vector<int>
# define vvi vector<vi>

bool is_ansfound(vi subsetsum,int k,int tsum){
	// function to check if all the elements in subsetsum equal
	// n/k
	for(auto x:subsetsum){
		if(x!=tsum/k){
			return false;
		}
	}
	return true;
}

void print_test_case(int i,vvi &ksubset,vi &subsetsum){
	cout<<i<<endl;
	cout<<"subsetsum :";
	for(auto x:subsetsum){
		cout<<x<<" ";
	}
	cout<<endl;
	cout<<"subsets :\n";
	for(auto x:ksubset){
		for(auto y:x){
			cout<<y<<" ";
		}
		cout<<endl;
	}
}

bool backtrack(int a[],int n,int k,vi &subsetsum,int i,int tsum){
	// print_test_case(i,ksubset,subsetsum);
	// base case all subsets have sum equal to n/k
	if(subsetsum[k-1]==tsum/k && is_ansfound(subsetsum,k,tsum))return true;
	// recursive case
	// include current element in all the subsets
	// and recurse to see if answer possible
	for(int j=0;j<k;j++){
		if((subsetsum[j]+a[i])<=tsum/k){
			// include in the subset
			subsetsum[j]+=a[i];
			// recurse
			if(backtrack(a,n,k,subsetsum,i+1,tsum)){
				return true;
			}
			// undo 
			subsetsum[j]-=a[i];
		}
	}
	return false;
}

bool isKPartitionPossible(int a[],int n,int k){
	// declare a vector of vector to store elements for k subsets
	// vector to store sum for each subset
	vi subsetsum(k,0);
	int tsum=0;
	if(k==1)return true;
	if(k>n)return false;
	for(int i=0;i<n;i++)tsum+=a[i];
	if(tsum%k!=0)return false;
	return backtrack(a,n,k,subsetsum,0,tsum);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int k;
		cin>>k;
		cout<<isKPartitionPossible(a,n,k);
	}
}
