// spiral traversal of the array
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

void print_pair(pii a){
	cout<<a.first<<space<<a.second<<nextline;
}

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
	// test the input array
	/*for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<matr[i][j]<<space;
		}
		cout<<nextline;
	}*/
	// cout<<"output complete"<<nextline;
	pair <int , int > top_left=make_pair(0,0),top_right=make_pair(0,m-1),bottom_rigt=make_pair(n-1,m-1),bottom_left=make_pair(n-1,0);
	// print_pair(top_left);
	// print_pair(top_right);
	// print_pair(bottom_rigt);
	// print_pair(bottom_left);
	while(true){
		// checking if horizontal row -> direction is printable
		if(top_left.second>top_right.second){
			// not printable
			// in this case other rows too wont be printable too
			break;
		}
		else if(top_left.second<=top_right.second){
			for(int i=top_left.second;i<=top_right.second;i++){
				if(matr[top_left.first][i]==-1)continue;
				cout<<matr[top_left.first][i]<<space;
				matr[top_left.first][i]=-1;
			}
		}
		if(top_right.first>bottom_rigt.first){
			break;
		}
		else if(top_right.first<=bottom_rigt.first){
			for(int i=top_right.first;i<=bottom_rigt.first;i++){
				if(matr[i][top_right.second]==-1)continue;
				cout<<matr[i][top_right.second]<<space;
				matr[i][top_right.second]=-1;
			}
		}
		if(bottom_rigt.second<bottom_left.second){
			break;
		}
		else if(bottom_rigt.second>=bottom_left.second){
			for(int i=bottom_rigt.second;i>=bottom_left.second;i--){
				if(matr[bottom_rigt.first][i]==-1)continue;
				cout<<matr[bottom_rigt.first][i]<<space;
				matr[bottom_rigt.first][i]=-1;
			}
		}
		if(bottom_rigt.first<top_left.first){
			// cout<<"last one not executed"<<nextline;
			break;
		}
		else if(bottom_left.first>=top_left.first){
			for(int i=bottom_left.first;i>=top_left.first;i--){
				if(matr[i][bottom_left.second]==-1)continue;
				cout<<matr[i][bottom_left.second]<<space;
				matr[i][bottom_left.second]=-1;
			}
		}
		//make appropriate changes in the corner points
		top_left.first+=1;
		top_left.second+=1;
		top_right.first+=1;
		top_right.second-=1;
		bottom_rigt.first-=1;
		bottom_rigt.second-=1;
		bottom_left.first-=1;
		bottom_left.second+=1;
		// cout<<"\n first traversal complete \n";
		// cout<<"value of next paris \n";
		// print_pair(top_left);
		// print_pair(top_right);
		// print_pair(bottom_rigt);
		// print_pair(bottom_left);

	}
	// cout<<"test case complet ";
	cout<<nextline;
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