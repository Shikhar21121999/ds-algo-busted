// program to print non-repeating numbers in the given array

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

class Solution
{
public:
	vi singleNumber(vi nums){
		int xr=nums[0];
		int n=nums.size();
		for(int i=1;i<n;i++){
			xr=xr^nums[i];
		}
		// now xr stores the xor of the two distinct numbers

		// by the property of xor
		// a particular bit that is active in xr would have been active
		// in only one of the two distinct numbers

		// find a bit that is active in xr (least significant bit)
		int lsb_num=1;
		while(lsb_num<=xr){
			if(lsb_num&xr){
				break;
			}
			lsb_num=lsb_num<<1;
		}

		// lsb_num contains the no corrosponding to the active bit in xr
		int xrcpy=xr;
		for(int i=0;i<n;i++){
			if(nums[i]&lsb_num){
				xr=xr^nums[i];
			}
			else{
				xrcpy=xrcpy^nums[i];
			}
		}
		vi b{xr,xrcpy};
		return b;

	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		n=2*n+2;
		vi a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		Solution ob;
		vi ans=ob.singleNumber(a);
		for(auto i:ans){
			cout<<i<<" ";
		}
		cout<<endl;
	}
	return 0;
}
