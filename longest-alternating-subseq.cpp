// program to solve longest alternating subsequence
// O(N) solution

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	int AlternatingaMaxLength(vector<int>&nums){
		int inc=1;
		int dec=1;

		int n=nums.size();
		for(int i=1;i<n;i++){
			if(nums[i]>nums[i-1]){
				inc=dec+1;
			}
			if(nums[i]<nums[i-1]){
				dec=inc+1;
			}
		}
		return max(inc,dec);
	}
};

int main(){
	int tc;
	cin>>tc;
	while(tc--){
		int n;
		cin>>n;
		vector<int> nums(n);
		for(int i=0;i<n;i++){
			cin>>nums[i];
		}
		Solution ob;
		cout<<ob.AlternatingaMaxLength(nums)<<endl;
	}
	return 0;
}