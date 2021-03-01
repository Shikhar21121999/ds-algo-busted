// program to solve combination sum problem
// link:https://practice.geeksforgeeks.org/problems/combination-sum/0

#include <bits/stdc++.h>
using namespace std;
# define vi vector <int>
# define vvi vector<vi>

void backtrack(int curr_sum,int* reqd_sum,vi &curr_ele,vvi &ans,vi &A){
	// base case
	if(curr_sum==*reqd_sum){
		ans.push_back(curr_ele);
		return;
	}
	// recurse case
	// iterate for all the array elements and recurse
	// for all such that sum does not exceed reqd sum
	for(int i=0;i<A.size();i++){
		if((curr_sum+A[i])<=*reqd_sum){
			// do
			curr_ele.push_back(A[i]);
			// recur
			backtrack(curr_sum+A[i],reqd_sum,curr_ele,ans,A);
			// redo
			curr_ele.pop_back();
		}
	}

}

class Solution{
	public:
		vvi combinationSum(vi &A,int B){
			vvi ans;
			vi curr_ele;
			sort(A.begin(),A.end());
			// ar.erase(unique(ar.begin(), ar.end()), ar.end());
			A.erase(unique(A.begin(),A.end()),A.end());
			backtrack(0,&B,curr_ele,ans,A);
			sort(ans.begin(),ans.end());
			return ans;
			
		}
};


int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vi A;
		int x;
		for(int i=0;i<n;i++){
			cin>>x;
			A.push_back(x);
		}
		int sum;
		cin>>sum;
		Solution ob;
		vvi result=ob.combinationSum(A,sum);
		if(result.size()==0){
			cout<<"empty";
		}
		for(int i=0;i<result.size();i++){
			cout<<"(";
			for(int j=0;j<result[i].size();j++){
				cout<<result[i][j];
				if(j<result[i].size()-1){
					cout<<" ";
				}
			}
			cout<<")\n";
		}
		cout<<"\n";
	}
}
