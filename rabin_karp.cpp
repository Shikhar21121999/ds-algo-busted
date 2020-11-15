// Pattern matching using rabin karp
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

int hash_val(string s){
	// hash function or formula
	// that returns the hash value for the string

	int val=0;
	int pow_val=1;
	int pri_no=5717;
	int n=s.length();
	for(int i=0;i<n;i++){
		val+=(s[i]-'a')*pow_val;
		val%=pri_no;
		pow_val*=26;
	}
	cout<<val;
	return val;

}


void solve(){
	string sentence;
	getline(cin,sentence);
	int n=sentence.length();

	cout<<sentence<<nextline;
	string pattern;
	cin>>pattern;

	int m=pattern.length();
	// we store the hash value for both pattern string
	// and for the first substr of same length as that of the pattern

	// we create hash value such that first character has power 256^m-1
	// and last character has power 0

	int d=256;		// number of characters in the input alpahabet
	int pr=101;	// a prime number
	int h=1;		// value of constant to be multiplied to last character

	// eventually our hash function takes gives the value as
	// ans=p[i]*1+p[i+1]*d+p[i+2]*d^2+p[i+3]*d^3+.....p[i+m-1]*d^m-1

	// finding initial hash value for the pattern and first m character of sentence


	for(int i=0;i<m-1;i++){
		h=(h*d)%pr;
	}

	int ptr_hsh=0;
	int sen_hsh=0;
	for(int i=0;i<m;i++){
		ptr_hsh=(ptr_hsh*d+pattern[i])%pr;
		sen_hsh=(sen_hsh*d+sentence[i])%pr;
	}

	// slide the pattern over text in the sentence one by one to compare

	for(int i=0;i<=n-m;i++){
		cout<<i<<nextline;

		// first we check if the tow hash_values are same
		if(ptr_hsh==sen_hsh){
			cout<<"hash matches"<<nextline;
			// in this case we check the strings character wise if they are equal or not
			int j=0;
			for(j=0;j<m;j++){
				if(sentence[i+j]!=pattern[j])
					break;
			}
			if(j==m)cout<<"pattern found at index "<<i<<nextline;

		}

		// now we have to make sure that the comparison occurs for i=n-m
		// but when i=n-m next other character cannot be included

		if(i<n-m){
			// we make new changes so as to create new hash value as according to the next
			// pattern
			sen_hsh=(d*(sen_hsh-sentence[i]*h)+sentence[i+m])%pr;
			if(sen_hsh<0)sen_hsh=sen_hsh+pr;
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
    solve();
return 0;
}