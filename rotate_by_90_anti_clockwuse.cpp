// rotate anticlockwise 
// using only constant extra space (1 variable)
// time complexity O(n2)
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
	// input the square matrix
	int n;
	cin>>n;
	int arr[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}

	// now we define the total cycles
	int cycles=n/2;

	// we also need to define the total length of the row to traverse inner loop on
	int length=n-1;
	// this length decreases by two for each cycle

	// we also define corner points

	pair <int , int > top_left = make_pair(0,0);
	pair <int , int > top_right = make_pair(0,n-1);
	pair <int , int > botton_right = make_pair(n-1,n-1);
	pair <int , int > botton_left = make_pair(n-1,0);

	// cout<<"printing the corner points"<<nextline;
	// cout<<arr[top_left.first][top_left.second]<<tab;
	// cout<<arr[top_right.first][top_right.second]<<nextline;
	// cout<<arr[botton_left.first][botton_left.second]<<tab;
	// cout<<arr[botton_right.first][botton_right.second]<<nextline;
	// cout<<cycles<<nextline;



	for(int i=0;i<cycles;i++){
		// this loop is used to iterate for the number of concetric cycles
		
		// first we need to define the current corner points
		// that will be used to perform swapping
		pair <int , int > curr_top_left = top_left;
		pair <int , int > curr_top_right = top_right;
		pair <int , int > curr_botton_right = botton_right;
		pair <int , int > curr_botton_left = botton_left;
		int temp;

		// cout<<"printing the corner points"<<nextline;
		// cout<<arr[curr_top_left.first][curr_top_left.second]<<tab;
		// cout<<arr[curr_top_right.first][curr_top_right.second]<<nextline;
		// cout<<arr[curr_botton_left.first][curr_botton_left.second]<<tab;
		// cout<<arr[curr_botton_right.first][curr_botton_right.second]<<nextline;
		// cout<<cycles<<nextline;
		
		for(int i=0;i<length;i++){
			// inner loop to perform swapping

			// we perform swapping of elements
			swap(temp,arr[curr_top_left.first][curr_top_left.second]);
			swap(temp,arr[curr_botton_left.first][curr_botton_left.second]);
			swap(temp,arr[curr_botton_right.first][curr_botton_right.second]);
			swap(temp,arr[curr_top_right.first][curr_top_right.second]);
			swap(temp,arr[curr_top_left.first][curr_top_left.second]);

			// now we need to make changes to the current elements so that they
			// represent and can be used to swap other elements in the array
			// cout<<"inside inner loop"<<nextline;
			// cout<<arr[curr_top_left.first][curr_top_left.second]<<tab;
			// cout<<arr[curr_top_right.first][curr_top_right.second]<<nextline;
			// cout<<arr[curr_botton_left.first][curr_botton_left.second]<<tab;
			// cout<<arr[curr_botton_right.first][curr_botton_right.second]<<nextline;

			// cout<<curr_top_left.first<<space<<curr_top_left.second<<tab;
			// cout<<curr_top_right.first<<space<<curr_top_right.second<<nextline;
			// cout<<curr_botton_left.first<<space<<curr_botton_left.second<<tab;
			// cout<<curr_botton_right.first<<space<<curr_botton_right.second<<nextline;
			
			curr_top_left.second++;
			curr_top_right.first++;
			curr_botton_right.second--;
			curr_botton_left.first--;

			




		}
		// here we need to make changes to the outer elements so they represent the next circle

		top_left.first++;
		top_left.second++;
		top_right.first++;
		top_right.second--;
		botton_right.first--;
		botton_right.second--;
		botton_left.first--;
		botton_left.second++;

		// next length equals length-2;
		length-=2;

	}
	// print the matrix
	cout<<"answer matrix"<<nextline;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
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