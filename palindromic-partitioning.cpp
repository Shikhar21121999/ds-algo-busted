// program to solve pallindromic partitioning of a string
// we basically have to find minimum number of splits needed such that
// after partitioning all the strings are pallindromic in nature

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
class Solution{
public:
	int palindromicPartition(string s)
    {
    	int n=s.length();
        // first we make a dp such that dp[i][j] stores wether substring of
        // of str from i to j is a pallindrom or not
        // initially all are kept as false
        vvi isPallin(n,vi(n,0));

        // all substrings of length are pallindrome
        for(int i=0;i<n;i++){
        	isPallin[i][i]=1;
        }

        // a string from i to j is pallindrom if last two characters are same
        // and middle substring is also pallindrome
        for(int len=2;len<=n;len++){
        	for(int i=0;i<=n-len;i++){
        		int j=i+len-1;

        		if(len==2 and s[i]==s[j]){
        			isPallin[i][j]=1;
        		}
        		else if(s[i]==s[j] and isPallin[i+1][j-1]){
        			isPallin[i][j]=1;
        		}
        	}
        }

        // we make an array S such that S[i] stores minimum number of cuts
        // needed to make substring from 0 to i into pallindromic partitions
        vi dp(n,INT_MAX);

        for(int i=0;i<n;i++){
        	if(isPallin[0][i]){
        		// is it is pallindrom no splits are required
        		dp[i]=0;
        	}
        	else{
        		for(int j=0;j<i;j++){
        			// total splits equal to s[j]+1 if j+1 to n is a pallindrome
        			if(isPallin[j+1][i] and (dp[j]+1)<dp[i]){
        				dp[i]=dp[j]+1;
        			}
        		}
        	}

        }
        
        return dp[n-1];
        
    }
};

int main(){
	int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.palindromicPartition(str)<<endl;
	}
}