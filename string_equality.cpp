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

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}


long long binpowmod(long long a, long long b, long long m) {
    // function to find a^b modulo m
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}



void solve(){
    int n,k;
    cin>>n>>k;

    string str1,str2;
    cin>>str1>>str2;

    vector <int> hash1(123,0);
    vector <int> hash2(123,0);

    // fill the hash table 1
    for(int i=0;i<n;i++){
        int ind=int(str1[i]);
        hash1[ind]++;
    }

    // fill the hash table 2
    for(int i=0;i<n;i++){
        int ind=int(str2[i]);
        hash2[ind]++;
    }

    // traverse the hash table and see if it is possbible to maintain equality

    for(int i=97;i<=122;i++){
        // cout<<char(i)<<space<<hash1[i]<<space<<hash2[i]<<nextline;
        if(hash1[i]>hash2[i] and hash1[i]>=k){
            // move 1 is required and can happen

            if((hash1[i]-hash2[i])%k==0){
                // suitable no of move 1 equals the occurences of current character

                hash1[i+1]+=hash1[i]-hash2[i];
                hash1[i]=hash2[i];               
            }
        }

        // check if after all this character occurences become equal
        // cout<<char(i)<<space<<hash1[i]<<space<<hash2[i]<<nextline;
        if(hash1[i]!=hash2[i]){
            cout<<"No"<<nextline;
            return;
        }

    }

    // control reaches here only if all the occurences are equal
    // in this case suitable no of operation one can be applied to make both string equal
    cout<<"Yes"<<nextline;
    return;

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