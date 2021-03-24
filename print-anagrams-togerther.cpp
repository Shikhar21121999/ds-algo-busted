// program to print all the anagrams 
// belonging to a particular group together

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector <vpii>
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define si stack<int>
#define ll long long
#define vll vector<ll>
#define qi queue<int>
#define vs vector<string>
#define vvs vector<vs>
#define minpq priority_queue<int,vi,greater<int>>
#define space " "

int main(){
	int n;
	cin>>n;
	vs inp(n);
	for(int i=0;i<n;i++){
		cin>>inp[i];
	}

	// now we try to store these
	// in an unordered map

	unordered_map <string,vs> recd;
	for(int i=0;i<n;i++){
		string sortCpy=inp[i];
		sort(sortCpy.begin(), sortCpy.end());
		recd[sortCpy].push_back(inp[i]);
	}

	vvs ans;
	for(auto x:recd){
		cout<<x.first<<" ";
		for(auto y:x.second){
			cout<<y<<" ";
		}
		ans.push_back(x.second);
		cout<<endl;
	}

	cout<<"printing ans\n";
	for(auto x:ans){
		for(auto y:x){
			cout<<y<<" ";
		}
		cout<<endl;
	}
}
