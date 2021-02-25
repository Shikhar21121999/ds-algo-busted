// program to print all the permutations of a string
// with distinct characters using backtracking

#include <bits/stdc++.h>
using namespace std;

void backtrack(string s,int left,int right){
	// give all the perumtations
	
	// base case
	// when all the characters are fixed
	if(left==right){
		cout<<s<<"\n";
		return;
	}
	
	// recursive case
	
	for (int i=left;i<=right;i++){
		
		// swap left character with i 
		// to generate new first portion of the string
		swap(s[left],s[i]);
		
		// recurse more fix more string
		backtrack(s,left+1,right);
		
		// now we need to restore the previous string
		// so that it does not affect other states
		swap(s[left],s[i]);
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		backtrack(s,0,s.length()-1);
	}
}
