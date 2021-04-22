// program to if third string is interleaving of first two string

#include<bits/stdc++.h>
using namespace std;

bool recur(int i,int j,int k,string a,string b,string c){
	// base case
	if(i==a.length() and j==b.length() and k==c.length()){
		return true;
	}
	// condition 1 when current character of a matches with c
	bool cndn1=false;
	if(i<a.length() and a[i]==c[k] and recur(i+1,j,k+1,a,b,c)){
		return true;
	}
	if(j<b.length() and b[j]==c[k] and recur(i,j+1,k+1,a,b,c)){
		return true;
	}
	return false;
}

int main(){
	string A,B,C;
	cin>>A>>B>>C;
	cout<<recur(0,0,0,A,B,C)<<endl;
}