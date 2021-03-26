// program to find number of bits
// that need to be flipped to convert 1 number to another

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int countBitsFlip(int a,int b){
		// we just count the number of bits that are set
		// in the bigger number and are not set in the smaller number
		int p=1;
		int cnt=0;
		while(p<=max(a,b)){
			if((p&a)!=(p&b))cnt++;
			p=p<<1;
		}
		return cnt;
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;

		Solution ob;
		int ans=ob.countBitsFlip(a,b);
		cout<<ans<<endl;
	}
}