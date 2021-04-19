// program to solve mobile numeric keypad problem

#include<bits/stdc++.h>
using namespace std;
#define vi vector<long long>
#define vvi vector<vi>

class Solution{
public:
	long long getCount(int n){
		if(n==1){
			return 10;
		}
		vvi nextNum(10);

		// filling the nextNum according to given conditions of the keypad problem
		nextNum[0]={0,8};
		nextNum[1]={1,2,4};
		nextNum[2]={1,2,5,3};
		nextNum[3]={2,3,6};
		nextNum[4]={1,4,5,7};
		nextNum[5]={2,4,5,8,6};
		nextNum[6]={3,5,6,9};
		nextNum[7]={4,7,8};
		nextNum[8]={5,7,8,9,0};
		nextNum[9]={6,8,9};

		vvi dp(10,vi(n+1,0));

		// number of length 1 ending with a particular number is 1
		for(int i=0;i<=9;i++){
			dp[i][1]=1;
		}

		// generating answer for other length
		for(int cnt=2;cnt<=n;cnt++){
			for(int lastNo=0;lastNo<=9;lastNo++){
				for(auto adjNo:nextNum[lastNo]){
					dp[adjNo][cnt]+=dp[lastNo][cnt-1];
				}
			}
		}

		// get sum of all the numbers of length n
		long long ans=0;
		for(int i=0;i<=9;i++){
			ans+=dp[i][n];
		}
		return ans;

	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		Solution ob;
		cout<<ob.getCount(n)<<endl;
	}
}