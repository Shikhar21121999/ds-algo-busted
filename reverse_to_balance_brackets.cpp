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
	string inp;
	cin>>inp;

	// cout<<inp<<nextline;
	int n=inp.length();
	if(n%2!=0){
		cout<<-1<<nextline;
		return;
	}
	
	// remove the intermediate balanced brackets

	stack <char> s;
	

	for(int i=0;i<n;i++){
		if(s.empty()){
			// cout<<inp[i]<<" stack is empty filling with current"<<nextline;
			s.push(inp[i]);
			continue;
		}
		// cout<<s.top()<<space<<inp[i]<<nextline;
		// good case only possible when stack is not empty
		if(s.top()=='{' and inp[i]=='}'){
			// cout<<"cndn1"<<nextline;
			s.pop();
		}

		else{
			// cout<<"cndn2"<<nextline;
			s.push(inp[i]);
		}
	}
	/*if(s.empty()){
		cout<<0<<nextline;
		return;
	}*/

	string refined="";

	while(!s.empty()){
		refined+=s.top();
		s.pop();
	}
	// cout<<"before reversal refined string is : "<<refined<<nextline;
	// reverse the string
	reverse(refined.begin(),refined.end());

	// cout<<"refined string is :"<<refined<<nextline;

	int m=refined.length();
	int prev_open_brac=0;
	int open_brack_tally=0;
	int reversal=0;

	for(int i=0;i<m;i++){

		char curr=refined[i];
		// cout<<refined[i]<<space;

		// curr char is an open bracket and total open brackets tally<allowed open bracket
		if(curr=='{' and open_brack_tally<m/2){
			prev_open_brac++;
			open_brack_tally++;
		}

		// curr chara is an open bracket but allowed open brackets are equal or greater than allowed
		else if(curr=='{' and open_brack_tally==m/2){
			// perform reversal to convert this into a closed bracket
			reversal++;
			prev_open_brac--;
		}

		// curr char is a closed bracket and it is allowed to be so
		else if(curr=='}' and prev_open_brac>0){
			// then we keep this as it is
			// also a pair gets compeleted
			prev_open_brac--;
		}
		// curr char is a closed bracket but it is not allowed to be so
		else if(curr=='}' and prev_open_brac==0){
			// we transform this into an open bracket
			reversal++;
			prev_open_brac++;
			open_brack_tally++;
		}

	}

	cout<<reversal<<nextline;

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