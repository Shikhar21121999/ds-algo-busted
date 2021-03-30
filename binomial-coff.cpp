// program to caculate binomial coffecient
// here we find modulo of the answer to get the the answer in int

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vvpii>
#define ll long long
#define vll vector<ll>

class Solution{
public:
	int nCr(int n,int r){
		if(r>n)return 0;


		long long int m=1000000007;
		long long inv[r+1]={0};

		inv[1]=1;

		// getting the value of inversion for all
		// the possible coefficients
		for(int i=2;i<=r;i++){
			inv[i]=m-(m/i)*inv[m%i]%m;
		}

		int ans=1;

		// for 1/(r)! part
		for(int i=2;i<=r;i++){
			ans=((ans%m)*(inv[i]%m))%m;
		}

		// for n*(n-1)*(n-2)*(n-3).....(n-r+1) part
		for(int i=n-r+1;i<=n;i++){
			ans=((ans%m)*(i%m))%m;
		}
		return ans;
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,r;
		cin>>n>>r;

		Solution ob;
		cout<<ob.nCr(n,r);
	}
}