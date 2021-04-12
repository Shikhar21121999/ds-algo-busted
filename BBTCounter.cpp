// program to compute the maximum possible number of balanced binary trees possible

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<long long int>
class Solution{
public:
	long long int countBT(int h){
		int m=1e9+7;

		vi dp(h+1);
		dp[1]=1;
		dp[2]=3;

		for(int i=3;i<=h;i++){
			dp[i]=((dp[i-1]%m)*((2*(dp[i-2])%m)%m+dp[i-1]%m))%m;
		}
		return dp[h];
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int h;
		cin>>h;
		Solution ob;
		cout<<ob.countBT(h)<<endl;
	}
	return 0;
}