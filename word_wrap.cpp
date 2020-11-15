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
int n;
vector <int> arr;
vector <vector <pair < int,int > > > dp;
// vector <vector pair< <int,int> > > dp;
int line_width;

int raise_pow_three(int a){
	return a*a*a;
}

void print_ans(){
	// a function to print the answer

	// now we know solution always starts from 0,1
	// that  is the 0th index is in the first line
	// cout<<0<<space<<1<<nextline;
	pair <int , int > curr=make_pair(0,1);
	pair <int , int > next_coor=dp[curr.first][curr.second];

	int p=0;
	while(curr.first<n){
		cout<<curr.first+1<<space<<next_coor.first<<space;
		curr=next_coor;
		next_coor=dp[curr.first][curr.second];
	}
	cout<<nextline;

}


int recur(int k,int p){
	// recursive function that returns the min cost for filling line p with words
	// starting from index k inclusive

	// base case
	if(k>=n)return 0;

	// recursive case
	int overall_cost=IINF;
	int curr_cost;
	int sum_char=-1; // to account for the first space
	int words_opt=0;
	for(int i=0;i+k<n;i++){
		sum_char+=arr[i+k];
		sum_char++; // adding the space for current word

		// terminating case
		if(sum_char>line_width)break;

		// calculate the cost and try to minimize the overall cost
		curr_cost=raise_pow_three(line_width-sum_char)+recur(i+k+1,p+1);
		if(curr_cost<overall_cost){
			// update the current cost and the number of words in the current line
			overall_cost=curr_cost;
			dp[k][p]=make_pair(i+k+1,p+1);

			// whenever we get the better cost we store the words_opt
			// that is the number of words in current line for optimality
			words_opt=i+1;
		}
	}
	// cout<<k<<space<<p<<nextline;
	// cout<<"values computed are : "<<space;
	// cout<<overall_cost<<space<<words_opt<<nextline;
	return overall_cost;
}

void solve(){
	cin>>n;
	arr.resize(n,0);
	// dp.resize(n+1,vector <int>(n+1,make_pair(-1,-1)) );
	dp.resize(n+1,vector <pair <int,int> >(n+1,make_pair(-1,-1)) ); 
	// next element to reach after current one
	loop(0,n)cin>>arr[i];
	cin>>line_width;
	int cost=recur(0,1);
	// cout<<"overall optimal cost is : "<<cost<<nextline;
	
	// for(auto x:dp){
	// 	for(auto y:x){
	// 		cout<<y.first<<space<<y.second<<tab<<tab;
	// 	}
	// 	cout<<nextline;
	// }

	// calling the print function to print the words in line for the optimal solution
	print_ans();

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