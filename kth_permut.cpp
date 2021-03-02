// program to find kth_permutation for a sequence of n natural number
// link:https://www.geeksforgeeks.org/partition-set-k-subsets-equal-sum/

#include <bits/stdc++.h>
using namespace std;

int get_index(int &k,int n){
	// gets the index of the number to put in the first position
	// for a number of size n
	// if only one number
	if(n==1)return 0;
	
	// as we have to perform n-1 factorial
	n=n-1;
	// for more than 1 number we first find partial_fact
	int partial_fact=n;
	while(partial_fact<k && n>1){
		partial_fact=partial_fact*(n-1);
		n--;
	}
	
	int index=k/partial_fact;
	k=k%partial_fact;
	return index;
}

string find_kth_permut(int n,int k){
	// create a set to store all the natural numbers in ascending order
	set <int> s;
	for(int i=1;i<=n;i++){
		s.insert(i);
	}
	
	auto itr=s.begin();
	string ans="";
	
	// decrease k by one to get 0 based indexing
	k-=1;
	
	for(int i=0;i<n;i++){
		int incr_ahead=get_index(k,n-i);
		advance(itr,incr_ahead);
		
		ans+=to_string(*itr);
		s.erase(itr);
		itr=s.begin();
	}
	return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int k;
		cin>>k;
		cout<<find_kth_permut(n,k);
	}
}
