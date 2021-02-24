// program to solve smallest problem
// link:https://practice.geeksforgeeks.org/problems/smallest-number5829/1

#include <bits/stdc++.h>
using namespace std;

string solve(){
	int S,D;
	cin>>S>>D;
	
	// this is the smalles number of D digit
	int ans=pow(10,D-1);
	
	// now we add S to different from back to front
	// so as to keep it min but also ensure that its sum is equal to S
	// do notice that 1 is already used
	S-=1;
	
	int dig_cnt=1;
	while(S>0){
		if(S>9){
			int num=dig_cnt*9;
			ans+=num;
			dig_cnt*=10;
			S-=9;
		}
		else{
			int num=dig_cnt*S;
			ans+=num;
			S=0;
		}
	}
	return to_string(ans); 
}
	

int main(){
	int t;
	cin>>t;
	cout<<solve()<<endl;
}
