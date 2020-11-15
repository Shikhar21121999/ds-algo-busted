// max_profit_on_two_stocks_dp
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
	int n;
	cin>>n;
	int arr[n];
	loop(0,n){
		cin>>arr[i];
	}
	// loop(0,n)cout<<arr[i]<<space;
	int dp[n]={0};
	// dp[i] represent the max profit achievable
	// if the transaction is made btw days i to n
	int max_till_now=arr[n-1];
	// cout<<nextline;
	for(int i=n-1;i>=0;i--){
		dp[i]=max(dp[i],max_till_now-arr[i]);
		max_till_now=max(max_till_now,arr[i]);
	}
	// loop(0,n)cout<<dp[i]<<space;
	// now we need to find max profit in two transaction
	// for this we make first transaction in btw 0 to i
	// second in i+1 to n
	// cout<<nextline;
	int min_tll_now=arr[0];
	int max_prof_for=0;
	int total_max_prof=dp[0];
	// cout<<nextline;
	for(int i=1;i<n-2;i++){
		// cout<<min_tll_now<<space<<arr[i]<<space<<max_prof_for<<space<<dp[i+1]<<space<<total_max_prof<<nextline;
		min_tll_now=min(min_tll_now,arr[i]);
		max_prof_for=max(max_prof_for,arr[i]-min_tll_now);
		total_max_prof=max(total_max_prof,max_prof_for+dp[i+1]);
		// cout<<min_tll_now<<space<<arr[i]<<space<<max_prof_for<<space<<dp[i+1]<<space<<total_max_prof<<nextline;
	}
	cout<<total_max_prof<<nextline;

}


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endi  
  	int t;
    cin>>t;
    loop(0,t){
    	solve();
    }
return 0;
}