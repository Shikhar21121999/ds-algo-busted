// maximum number that can be formed by swapping at most k digits
// of a string
// link:https://www.geeksforgeeks.org/find-maximum-number-possible-by-doing-at-most-k-swaps/

#include <bits/stdc++.h>
using namespace std;

void findmaxminiNum(string str,int k,string& num){
	
	// base case
	// no swaps left
	if(k==0)return;
	
	int n=str.length();
	if(str.compare(num)>0){
		num=str;
	}
	
	// consider by swapping every digit
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(str[i]<str[j]){
				// do 
				swap(str[i],str[j]);
				// recur
				findmaxminiNum(str,k-1,num);
				// redo
				swap(str[i],str[j]);
			}
		}
	}
	return;
}

int main(){
	string inp;
	cin>>inp;
	int k;
	cin>>k;
	string max=inp;
	findmaxminiNum(inp,k,max);
	cout<<max<<endl;
	return 0;
}
