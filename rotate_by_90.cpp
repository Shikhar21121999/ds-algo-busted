// template
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
	int n,m;
	cin>>n>>m;
	int arr[n+1][m+1];
	vector < vector <int > > dp(n+1,vector <int> (m+1,1) );
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>arr[i][j];
		}
	}
	// output the array
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<arr[i][j]<<space;
		}
		cout<<nextline;
	}
	// column wise swap
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n/2;j++){
			// i is column and j is row
			// swap the elements of the column with there pallindrome equivalent

			swap(arr[j][i],arr[n-j+1][i]);
		}
	}
	// output the array
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<arr[i][j]<<space;
		}
		cout<<nextline;
	}

	// diagonal swap
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(dp[i][j]==1){
				swap(arr[i][j],arr[j][i]);
				dp[i][j]=0;
				dp[j][i]=0;
			}
			
		}
	}



	// output the array final ans
	cout<<"ans"<<nextline;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<arr[i][j]<<space;
		}
		cout<<nextline;
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
    int t;
    cin>>t;
    loop(0,t){
    	solve();
    }
return 0;
}