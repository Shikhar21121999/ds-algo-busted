// program to check if given sum can be found
// by adding some subset elements of the array

#include <bits/stdc++.h>
using namespace std;
# define vi vector <int>
# define vb vector <bool>

bool recur(vi &arr,int ind,int reqd_sum,vb &inc){
	// base case
	if(reqd_sum==0)return true;
	// base case
	if(ind<0)return false;
	
	// recursive case
	// include current element
	inc[ind]=true;
	if(recur(arr,ind-1,reqd_sum-arr[ind],inc)){
		return true;
	}
	inc[ind]=false;
	return recur(arr,ind-1,reqd_sum,inc);
	// return recur(arr,ind-1,reqd_sum)||recur(arr,ind-1,reqd_sum-arr[ind]);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector <int> arr(n);
		vector <bool> inc(n,false);
		int t_sum=0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			t_sum+=arr[i];
		}
		int reqsum;
		cin>>reqsum;
		if(recur(arr,n-1,reqsum,inc)){
			cout<<"answer found\n";
			for(int i=0;i<n;i++){
				if(inc[i])cout<<arr[i]<<" ";
			}
		}
		else cout<<"Nopse";
	}
}
		
