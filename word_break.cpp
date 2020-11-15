// standard dp problem
// word-break-problem dp iterative bottom up
#include <bits/stdc++.h>
 
# define C continue;
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
# define test int t;cin >> t;while(t--)
# define nextline "\n"
# define tab "\t"
# define space " "
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
const int two_pow_fiv=200008;
const int IINF=1e8+5;
using namespace std;



void solve(){
    // input format
    // first line is an integer n denoting the number of strings in dictionary
    // next n lines are strings to be present in the dictionary
    // last line contains string s : the string to see if it can be broken into words that are present in dictionary
    
    int n_words;
    int n;
    cin>>n_words;
    string inp;
    unordered_map<string,int> dict;
    for(auto x:dict){
    	cout<<x.first<<space<<x.second<<nextline;
    }
    loop(0,n_words){
        cin>>inp;
        dict[inp]=1;
    }
    dict[""]=1;
    string s;
    cin>>s;
    n=s.length();
    if(n==0){
        cout<<1<<nextline;
        return;
    }
    vector <vector <int> > dp(n+1,vector <int>(n+1,0));
    // we make dp so that dp[i][j] represent wether string with first index i and length be j
    // first index will have range between 0 and n-1
    // second index will have range between 1 and n
    for(int len=1;len<=n;len++){
    	for(int fir_ind=0;fir_ind+len<=n;fir_ind++){

    		// current string under consideration
    		string curr_str=s.substr(fir_ind,len);
    		// cout<<"current string is: "<<curr_str<<nextline;
    		// first we check if this string is a part of dictionary
    		if(dict[curr_str]==1){
    			dp[fir_ind][len]=1;
    		}
    		else{
    			// either this string can be broken into smaller parts or not
    			for(int inner_len=1;inner_len<len;inner_len++){

				// first string is from first ind to this inner len
				// second string is from first_in+inner_len to len-inner_len
				// cout<<s.substr(fir_ind,inner_len)<<tab<<s.substr(fir_ind+inner_len,len-inner_len)<<nextline;
				if(dp[fir_ind][inner_len]==1 and dp[fir_ind+inner_len][len-inner_len]==1){
					dp[fir_ind][len]=1;
				}

				}
    		}

    	}
    }

    /*// we print the dp along with words
    for(int len=1;len<=n;len++){
    	for(int fir_ind=0;fir_ind+len<=n;fir_ind++){
    		// first we print the word followed by wether it can be broken into smaller dictionary words or not
    		cout<<s.substr(fir_ind,len)<<tab<<dp[fir_ind][len]<<nextline;
    	}
    }*/
    if(dp[0][n]==1){
    	cout<<1<<nextline;
    	return;
    }
    cout<<0<<nextline;

    
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