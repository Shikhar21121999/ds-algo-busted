// program to print number of one bits

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
		int setBits(int n){
			// function to set your bits
			int p=1;
			int cnt=0;
			while(p<=n){
				// cout<<p<<" "<<n<<endl;
				if(p&n){
					cnt++;
				}
				p=p<<1;
			}
			return cnt;
		}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;

		Solution ob;
		int cnt=ob.setBits(n);
		cout<<cnt<<endl;
	}
	return 0; 
}