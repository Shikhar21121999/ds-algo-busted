// median in a row wise sorted matrix
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


int binary_median(int matr[][10000],int n,int m,int desired){
	// first we find the max and min_ele in the matrix

	// min will be the first index of some row and max_ele will be the last element of some row
	int max_ele=0,min_ele=1000;
	for(int i=0;i<n;i++){

		// max
		max_ele=max(max_ele,matr[i][m-1]);

		// min
		min_ele=min(min_ele,matr[i][0]);

	}

	// we have to find the element before which there are desired number of elements present

	// we use binary search to check for the element that may have such "desired" number of elements before it
	// we use upper_bound() function to count number of elements before the "mid" number

	cout<<"while loop starts"<<nextline;
	int cnt=0;
	while(min_ele<max_ele and cnt<15){
		cnt++;
		// compute mid
		int mid=min_ele+(max_ele-min_ele)/2;
		// initialize places
		int places=0;
		cout<<min_ele<<space<<max_ele<<space<<mid<<nextline;
		// for loop to count number of places before mid row wise
		for(int i=0;i<n;i++){
			places+=upper_bound(matr[i],matr[i]+m,mid)-matr[i];
		}
		cout<<places<<space<<desired<<nextline;
		if(places==desired){
			return mid;
		}
		if(places<desired)min_ele=mid+1;
		else if(places>=desired)max_ele=mid;

	}
	cout<<"naa chala"<<nextline;
	return 1;

}


void solve(){
	// input the matrix
	int n,m;
	cin>>n>>m;
	int matr[n][10000];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>matr[i][j];
		}
	}

	// output check the matrix
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<matr[i][j]<<space;
		}
		cout<<nextline;
	}

	// check for odd and even
	if(n*m%2!=0){
		// odd
		// we print the mid rescieved
		int des=((n*m)+1)/2;
		cout<<binary_median(matr,n,m,des)<<nextline;
	}
	else{
		// we call the function two times and take the average of both the values rescieved
		float ans=0;
		ans+=binary_median(matr,n,m,((n*m)+1)/2);
		ans+=binary_median(matr,n,m,((n*m)+2)/2);
		printf("%.3f \n",ans/2 );
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