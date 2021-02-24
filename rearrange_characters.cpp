// program to solve rearrange_character
// link:https://practice.geeksforgeeks.org/problems/rearrange-characters/0

#include <bits/stdc++.h>
using namespace std;

int solve(){
	string inp;
	cin>>inp;
	
	unordered_map<char,int> store;
	
	for(int i=0;i<inp.length();i++){
		store[inp[i]]++;
	}
	
	// find the frequency of most occuring character
	int freq=0;
	for(auto x:store){
		freq=max(freq,x.second);
	}
	
	// now if length of inp is even
	// we can have most occuring character n/2 times
	if(inp.length()%2==0 and freq<=inp.length()/2){
		return 1;
	}
	if(inp.length()%2!=0 and freq<=(inp.length()/2)+1){
		return 1;
	}
	return 0;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cout<<solve()<<endl;
	}
	return 0;
}
