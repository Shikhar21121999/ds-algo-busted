// program to solve ones and zeroes problem (leetcode april day 2)
// link: https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/593/week-1-april-1st-april-7th/3694/

#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define vpii vector<pii>

int dp[101][101][601];

pii countZeroOnes(string s){
	int zer,one;
	int n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]=='0')zer++;
		else if(s[i]=='1')one++;
	}
	pii ans=make_pair(zer,one);
	return ans;
}

int recur(vpii binpair,int i,int m,int p){

	// out of bounds
	if(m<0 or p<0 or i>=binpair.size()){
		return 0;
	}

	// memoize optimization step
	if(dp[m][p][i]!=-1){
		return dp[m][p][i];
	}

	// recursive steps

	int incl=0;
	int excl=0;

	// including the current pair in the subset if possible
	if(m-binpair[i].first>=0 and p-binpair[i].second>=0){
		incl=1+recur(binpair,i+1,m-binpair[i].first,p-binpair[i].second);
	}

	// excluding the current pair in the subset
	excl=recur(binpair,i+1,m,p);

	return dp[m][p][i]=max(incl,excl);
}

class Solution{
public:
	int findMaxForm(vector<string>& strs, int m, int p) {
        
        // convert vector of strings to vector of pair
        // which stores number of 1 and 0's
		int n=strs.size();
		vpii binpair(n);
        for(int i=0;i<n;i++){
        	binpair[i]=countZeroOnes(strs[i]);
        }

        // use recursive dp to get answer
        memset(dp,-1,sizeof(dp[0][0][0]*m*p*n));
        return recur(binpair,0,m,p);
    }
};

int main(){
	int n;
	cin>>n;
	vector<string> inp(n);
	for(int i=0;i<n;i++){
		cin>>inp[i];
	}
	int m,p;
	cin>>m>>p;
	Solution ob;
	cout<<ob.findMaxForm(inp,m,p);
}