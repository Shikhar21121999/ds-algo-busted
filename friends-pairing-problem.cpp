// program to solve friends pairing problem

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int countFriendsPairings(int n){
		if(n<=2)return n;
		long long int ans=0;
		long long int m=1000000007;
		long long a=1,b=2,c;
		for(int i=3;i<=n;i++){
			c=(a%m+(((i-1)%m)*a%m)%m)%m;
			a=b;
			b=c;
		}
		return c;
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		Solution ob;
		cout<<ob.countFriendsPairings(n);
		cout<<endl;
	}
}