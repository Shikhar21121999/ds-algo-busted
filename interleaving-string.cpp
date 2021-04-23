// program to if third string is interleaving of first two string

#include<bits/stdc++.h>
using namespace std;


int dp[1001][1001];
bool recur(int i,int j,int k,string a,string b,string c){
	if(k==0)return 1;
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	int p,q;
	p=q=0;
	if(i-1>=0 and a[i-1]==c[k-1])p=recur(i-1,j,k-1,a,b,c);
	if(j-1>=0 and b[j-1]==c[k-1])q=recur(i,j-1,k-1,a,b,c);
	return dp[i][j]=p or q;
}
bool isInterleave(string A, string B, string C) 
{
    int n=A.length();
    int m=B.length();
    int len=C.length();
    if(n+m!=len){
    	return false;
    }
    dp[n][m];
    memset(dp,-1,sizeof(dp));
    return recur(n,m,len,A,B,C);
}


int main(){
	string A,B,C;
	cin>>A>>B>>C;
	cout<<isInterleave(A,B,C)<<endl;
}