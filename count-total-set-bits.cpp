// program to count total number of set bits
// in all the numbers from 1 to n

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int countSetBits(int n){

		// adding 1 to account for 0
		n+=1;

		int tSetBits=0;
		int p=1;
		while(p<=n){
			int groupOfZerOne=n/p;
			int setBitsgrp=groupOfZerOne/2;
			tSetBits+=setBitsgrp*p;
			if(groupOfZerOne&1){
				tSetBits+=n%p;
			}
			p=p<<1;
		}
		return tSetBits;
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		Solution ob;
		cout<<ob.countSetBits(n)<<endl;
	}
}