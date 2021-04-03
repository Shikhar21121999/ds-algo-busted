// program to solve painting the fence problem

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	long long countWays(int n,int k){
		int m=1e9+7;
		if(n==1)return k;
		long long same=k;
		long long kdiffmod=(k-1)%m;
		long long different=((k%m)*kdiffmod)%m;
		long long total=same+different;

		if(n==2)return total;

		for(int i=3;i<=n;i++){
			same=different%m;
			different=(total%m*kdiffmod)%m;
			total=(same%m)+(different%m);
		}
		return total;

	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}