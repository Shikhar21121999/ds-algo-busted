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
	// input the matrix
	int n,m;
	cin>>n>>m;
	int matr[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>matr[i][j];
		}
	}
	int t_val;
	cin>>t_val;
	// test the input array
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<matr[i][j]<<space;
		}
		cout<<nextline;
	}
	int top=0,bottom=n-1,mid=0;
	while(top<=bottom){
		mid=top+(bottom-top)/2;
		// base case
		if(t_val>=matr[mid][0] and t_val<=matr[mid][m-1]){
			// t_val exist in the row matr[row]
			break;
		}
		else if(t_val<matr[mid][0]){
			// t_val not present in the row mid...n-1
			bottom=mid-1;
		}
		else if(t_val>matr[mid][n-1]){
			// t_val not present in the row 0...mid
			top=mid+1;
		}
	}
	cout<<"Row in which t_val possibly exist is : "<<mid<<nextline;
	cout<<"First and last element of the row is : "<<matr[mid][0]<<space<<matr[mid][m-1]<<nextline;
	int row=mid;
	// row in which element possibly exists
	int left=0,rigt=m-1;
	while(left<=rigt){
		mid=left+(rigt-left)/2;

		// base case
		if(matr[row][mid]==t_val){
			// value found
			cout<<"true"<<nextline;
			cout<<"coordinates are : "<<row<<space<<mid<<nextline;
			return;
		}
		if(t_val<matr[row][mid]){
			// target value not present in the elements matr[row][mid]....matr[row][m-1]
			rigt=mid-1;
		}
		else if(t_val>matr[row][mid]){
			// target value not present in the elements matr[row][0]......matr[row][mid]
			left=mid+1;
		}
	}
	// if the control reaches here it means element not found
	cout<<"false"<<nextline;
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