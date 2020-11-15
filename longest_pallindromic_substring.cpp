// longest pallindromic substring
// using dp
#include <bits/stdc++.h>
 
# define C continue
# define R return
 
# define D double
# define I insert
# define ll long long
# define ld long double
 
# define ull unsigned long long
# define ui unsigned int
 
# define pb push_back
# define pf push_front
 
# define vi vector < int >
# define vc vector < char >
# define vs vector < string >
# define vb vector < bool >
# define vd vector < D >
# define vll vector < ll >
# define vull vector < ull >
# define vld vector < ld >
# define PQ priority_queue
 
# define vvi vector < vector < int > >
# define vvb vector < vector < bool > >
# define vvc vector < vector < char > >
# define vvll vector < vector < ll > >
# define vvd vector < vector < D > >
# define vvld vector < vector < ld > >
 
# define all(v) (v).begin() , (v).end()
# define allrev(v) (v).rbegin() , (v).rend()
# define allcomp(v) v.begin() , v.end() , comp
# define allrevcomp(v) v.rbegin() , v.rend() , comp
 
# define pii pair < int , int >
# define pll pair < ll , ll >
# define pld pair < ld , ld >
# define pDD pair < D , D >
# define pipii pair<int, pii >
# define pcpii pair<char,pii>
 
# define vpld vector < pld >
# define vpii vector < pii >
# define vpll vector < pll >
# define vpDD vector < pDD >
 
# define vvpii vector < vector < pii > >
# define vpipii vector< pipii >
 
# define F first
# define S second
# define mp make_pair
 
# define unm unordered_map
# define unmii unm< int , int >
# define unmll unm< ll , ll >
# define unms unm<string,int>
# define unmci unm<char,int>
 
# define sortvia sort(a.begin(),a.end());
# define sortvib sort(b.begin(),b.end());
# define revsorta sort(a.begin(), a.end(), greater <int>());
# define revsortb sort(b.begin(), b.end(), greater <>());
# define loop(q,n) for(int i=q;i<n;i++)
# define loop2(q,n) for(int j=q;j<n;j++)
# define test int t;cin >> t;while(t--)
# define nextline "\n"
# define tab "\t"
# define space " "
# define get_arr_size_n int n;cin>>n;int arr[n];loop(0,n)cin>>arr[i];
//vector<vector<int> > vec( n , vector<int> (m, 0));
//YES
//NO
//cout
//true
//false
//yes
//no
 
const ll mod9=1e9+7;
const ll maxsize=2e9+1;
// const ll mod =998244353;
const ll mod2=1073741824;
const ll INF=1e18L+5;
const int IINF=1e9+5;
const int two_pow_fiv=200008;
using namespace std;

void solve(){
	string s;
	cin>>s;

	int n=s.length();

	// make a dp of size n*n
	// dp[i][j] represent wether the substring from i to j both inclusive
	// is a pallindromic substring or not

	vector <vector <int> > dp(n,vector <int >(n,0));
	// initially all are false

	// as all the individual characters are a pallindrome
	for(int i=0;i<n;i++){
		dp[i][i]=1;
	}

	int max_length=1;

	for(int len=2;len<=n;len++){
		// outer loop tells the length of the substring
		for(int strt=0;strt<=n-len;strt++){
			int last_ind=strt+len-1;
			// cout<<strt<<space<<last_ind<<space<<len<<nextline;

			if(len==2){
				// this is a special case as there are only two characters
				// they should be equal
				// cout<<"length is 2"<<nextline;
				if(s[strt]==s[last_ind]){
					// cout<<"strt equals send"<<nextline;
					dp[strt][last_ind]=1;
					max_length=len;
				}
			}
			else{
				// last and first character should be same and the middle substring should be pallindrome
				if(s[strt]==s[last_ind] and dp[strt+1][last_ind-1]){
					// cout<<strt<<space<<last_ind<<nextline;
					// cout<<s[strt]<<space<<s[last_ind]<<nextline;
					dp[strt][last_ind]=1;
					max_length=len;
				}
			}
		}
	}

	/*// printing the dp 
	for(auto x:dp){
		for(auto p:x){
			cout<<p<<space;
		}
		cout<<nextline;
	}*/

	// now printing all the pallindromic substring of max_length
	for(int i=0;i+max_length-1<n;i++){
		// if dp[i][i+max_length-1] is true it implies that
		// substring is a pallindrome
		if(dp[i][i+max_length-1]==1){
			// cout<<i<<space<<max_length-1<<nextline;
			// print the substring 
			cout<<s.substr(i,max_length)<<nextline;
		}
	}

}


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    test{
    	solve();
    }
return 0;
}