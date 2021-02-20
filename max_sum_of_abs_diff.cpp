// program to find max. sum of absolute differences
// in an array of non-negative numbers

#include <bits/stdc++.h>
using namespace std;

int abs_diff(int a,int b){
	int ans=a-b;
	if(ans<0){
		ans=(-1)*ans;
	}
	return ans;
}

void solve(){
	int n;
	cin>>n;
	
	vector <int> a(n);
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	// first we sort the array
	sort(a.begin(),a.end());
	
	// now we turn by turn take highest and lowest element 
	// of the array and construct a new vector 
	vector <int> b(n);
	int high=n-1;
	int low=0;
	int i=0;
	while(high>low){
		b[i]=a[low];
		b[i+1]=a[high];
		i+=2;
		high--;
		low++;
	}
	if(n%2!=0){
		b[n-1]=a[low];
	}
	int abs_diff_sum=abs_diff(b[n-1],b[0]);
	for(int i=1;i<n;i++){
		abs_diff_sum+=abs_diff(b[i],b[i-1]);
	}
	cout<<abs_diff_sum<<"\n";
	
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
