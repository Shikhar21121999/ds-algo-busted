// test
#include <bits/stdc++.h>
using namespace std;
 
# define vi vector < int >
# define vc vector < char >
# define vs vector < string >
# define vb vector < bool >
# define vd vector < D >
# define vll vector < ll >
# define vull vector < ull >
# define vld vector < ld >
# define PQ priority_queue

# define ll long long
 
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
 
# define vvpii vector < vector < pii > >
# define vpipii vector< pipii >
 
 
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
//YES NO true false cout cin endl INT_MAX INT_MIN
 
const ll mod9=1e9+7;
const ll maxsize=2e9+1;
const ll mod2=1073741824;
const ll INF=1e18L+5;
const int IINF=1e9+5;
const int two_pow_fiv=200008;

// to get the coords of number in the grid
void getCoor(int num,int n) {
	cout<<num<<" "<<n<<endl;
    int row=(n-1)-(num-1)/n;
    cout<<row<<endl;
    int col;
    if(row%2==0){
    	// even n
    	col=(num-1)%n;
    }
    else{
    	// odd n
    	col=(n-1)-((num-1)%n);
    }
    return {row,col};
}


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
	int n;
	int num;
	cin>>num>>n;
	getCoor(num,n);
return 0;
}
