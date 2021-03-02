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

template <class BI>


bool next_permut(BI bg,BI en){

	// now her BI becomes the type of Biderectional Iterator to the type of container passed

	// first step is to find the largest index k for which arr[k]<arr[l]
	BI trav=bg;
	BI k=en;
	while(trav<en-1){
		if(*trav<*(trav+1)){
			k=trav;
		}
		trav++;
	}
	if(k==en)return false;
	else{
		// next permutation exist
		// we transform the current sequence to the next permutation
		trav=bg;
		BI l=k;
		// iterate from k+1 till en
		while(trav<en){
			if(*k<*trav){
				l=trav;
			}
			trav++;
		}
		swap(*k,*l);
		reverse(k+1,en);
		return true;
	}

}

void print_v(vi a){
	for(auto x:a)cout<<x<<space;
	cout<<nextline;
}

void solve(){
	// a testing program that prints all the next permutation
	// so that we can check and make our approach
	int n;
	cin>>n;
	vector <int> arr(n,0);
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}

	print_v(arr);
	
	while(next_permut(arr.begin(),arr.end())){
		print_v(arr);
	}
	print_v(arr);
}


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
    test{
    	solve();
    }
return 0;
}
