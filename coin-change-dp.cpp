// program to solve coin change problem
// using dp

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

class Solution
{
public:
	long long int count(int S[],int m,int n){
		// consider all the values that can be reached using only one coing
		// that is solve if there was only 1 coin and move forward

		vll table(n+1,0);
		table[0]=1;

		for(int i=0;i<m;i++){
			for(int j=1;j<=n;j++){
				// table[i]+=table[i-s[j]];
				table[j]+=table[j-s[i]];
			}
		}
		return table[n];
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++){
			cin>>arr[i];
		}
		Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
}