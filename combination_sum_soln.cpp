// program to solve combination sum problem
// link:https://practice.geeksforgeeks.org/problems/combination-sum/0

#include <bits/stdc++.h>
using namespace std;
# define vi vector <int>
# define vvi vector<vi>

// Print all members of ar[] that have given
void findNumbers(vector<int>& ar, int sum,
                 vector<vector<int> >& res, vector<int>& r,
                 int i)
{
    // If  current sum becomes negative
    if (sum < 0)
        return;

    // if we get exact answer
    if (sum == 0) {
        res.push_back(r);
        return;
    }

    // Recur for all remaining elements that
    // have value smaller than sum.
    while (i < ar.size() && sum - ar[i] >= 0) {

        // Till every element in the array starting
        // from i which can contribute to the sum
        r.push_back(ar[i]); // add them to list

        // recur for next numbers
        findNumbers(ar, sum - ar[i], res, r, i);
        i++;

        // Remove number from list (backtracking)
        r.pop_back();
    }
}

class Solution{
	public:
		vector<vector<int> > combinationSum(vector<int> &ar, int B) {
        // Your code here
        // sort input array
    sort(ar.begin(), ar.end());

    // remove duplicates
    ar.erase(unique(ar.begin(), ar.end()), ar.end());

    vector<int> r;
    vector<vector<int> > res;
    findNumbers(ar, B, res, r, 0);

    return res;
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

