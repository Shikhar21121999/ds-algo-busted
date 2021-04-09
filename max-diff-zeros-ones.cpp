// program to find maximum difference of zeroes and ones in a binary string
// link: https://practice.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
class Solution{
public:
	int maxSubstring(string s){

		// convert the string s into an array a[]
		// such that if s[i]=='0' put a[i]=1 else a[i]=-1
		int n=s.length();
		vi a(n);
		for(int i=0;i<n;i++){
			a[i]=(s[i]=='0'?1:-1);
		}

		// now we need to find max sum subarray for a
		// and that will be the answer
		// using kadane algo

		int maxTillNow=INT_MIN;
		int maxEndnow=0;
		for(int i=0;i<n;i++){
			maxEndnow=maxEndnow+a[i];
			if(maxTillNow<maxEndnow)maxTillNow=maxEndnow;
			if(maxEndnow<0)maxEndnow=0;
		}
		return maxTillNow;
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.maxSubstring(s)<<endl;
	}
}