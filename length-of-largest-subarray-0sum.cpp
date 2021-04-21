// program to find the length of largest subarray whoose sum is 0

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

int maxLength0sum(vi a,int n){
	int sumTillNow=0;
	int maxLength=0;
	unordered_map<int,int> recd;
	int left=-1;
	int right=-1;

	for(int i=0;i<n;i++){
		sumTillNow+=a[i];

		if(a[i]==0 and maxLength==0){
			maxLength=1;
			left=i;
			right=i;
		}
		if(sumTillNow==0){
			maxLength=i+1;
			left=0;
			right=i;
		}
		if(recd.find(sumTillNow)!=recd.end() ){
			if(maxLength<i-recd[sumTillNow]){
				maxLength=i-recd[sumTillNow];
				left=recd[sumTillNow]+1;
				right=i;
			}
			// maxLength=max(maxLength,i-recd[sumTillNow]);
		}
		else{
			recd[sumTillNow]=i;
		}

	}
	cout<<left<<" "<<right<<endl;

	return maxLength;
}

int main(){
	int n;
	cin>>n;
	vi a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<maxLength0sum(a,n)<<endl;

}