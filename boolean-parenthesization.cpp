// programt to solve boolean parenthesization problem

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
class Solution{
public:
	int countWays(int n, string s){
        // code here
        int m=1003;
		vvi T(n,vi(n,0));
		vvi F(n,vi(n,0));

		// T[i][j] indicate number of ways to get the result of solving sequence
		// from i to j as True
		// F[i][j] indicate number of ways to get the result of solving sequence
		// from i to j as True

		// calculating for length 1
		for(int i=0;i<n;i+=2){
			T[i][i]=(s[i]=='T')?1:0;
			F[i][i]=(s[i]=='F')?1:0;
		}

		// filling for other lengths
		// it is important to note that lengh of sequence can only be odd
		// as we need even operands and odd operator between them

		for(int gap=3;gap<=n;gap+=2){
			for(int i=0;i<=n-gap;i+=2){
				int j=i+gap-1;
				for(int k=i+1;k<j;k+=2){

					int totalik=(T[i][k-1]%m+F[i][k-1]%m)%m;
					int totalkj=(T[k+1][j]%m+F[k+1][j]%m)%m;

					// if operator at k is |
					if(s[k]=='|'){
						T[i][j]=(T[i][j]%m+((totalik%m*totalkj%m)%m-(F[i][k-1]%m*F[k+1][j]%m)%m)%m)%m;
						F[i][j]=(F[i][j]%m+(F[i][k-1]%m*F[k+1][j]%m)%m)%m;
					}
					// if operator is &
					else if(s[k]=='&'){
						T[i][j]=(T[i][j]%m+(T[i][k-1]%m*T[k+1][j]%m)%m)%m;
						F[i][j]=(F[i][j]%m+((totalik%m*totalkj%m)%m-(T[i][k-1]%m*T[k+1][j]%m)%m)%m)%m;
					}
					// if operator is ^
					else if(s[k]=='^'){
						T[i][j]=(T[i][j]%m+((T[i][k-1]%m*F[k+1][j]%m)%m+(F[i][k-1]%m*T[k+1][j]%m)%m)%m)%m;
						F[i][j]=(F[i][j]%m+((T[i][k-1]%m*T[k+1][j]%m)%m+(F[i][k-1]%m*F[k+1][j]%m)%m)%m)%m;
					}
				}
			}
		}

		return T[0][n-1];

    }
};

int main(){
	int t;
	cin>>t;
	while(t--){
		string inp;
		cin>>inp;
		Solution ob;
		cout<<ob.countWays(inp.length(),inp)<<endl;
	}
}