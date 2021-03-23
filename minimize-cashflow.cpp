// program to minimize cashflow among a given set of friends

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
#define minpq priority_queue<int,vi,greater<int>>
#define space " "

pii minMax(vi &netMoney){
	// utility function to return index of min
	// and max value in the netMoney
	int mini=-1;
	int maxi=-1;
	int curr_min=INT_MAX;
	int curr_max=-INT_MAX;
	for(int i=0;i<netMoney.size();i++){
		if(netMoney[i]<curr_min){
			curr_min=netMoney[i];
			mini=i;
		}
		if(netMoney[i]>curr_max){
			curr_max=netMoney[i];
			maxi=i;
		}
	}
	return make_pair(mini,maxi);
}

void minimizeCashFlow(vvi &adj,int n){

	// first we find and store the net value
	// each friend or node has to rescieved
	// perform bfs
	vi netMoney(n,0);
	for(auto x:adj){
		netMoney[x[0]]-=x[2];
		netMoney[x[1]]+=x[2];
	}

	// print the net money array
	for(int i=0;i<n;i++){
		cout<<netMoney[i]<<" ";
	}
	cout<<endl;
	// to store transaction
	// ans.first.first friend 1
	// ans.first.second friend 2
	// ans.second amount
	vector <pair<pii,int>> ans;

	pii min_max=minMax(netMoney);
	while(netMoney[min_max.first]!=0 and netMoney[min_max.second]!=0){
		// make a transaction from node min_max.first to min_max.second
		int transAmt=min(abs(netMoney[min_max.first]),netMoney[min_max.second]);
		cout<<min_max.first<<" "<<min_max.second<<" "<<netMoney[min_max.first]<<" "<<netMoney[min_max.second]<<" "<<transAmt<<endl;
		netMoney[min_max.first]+=transAmt;
		netMoney[min_max.second]-=transAmt;
		ans.push_back(make_pair(make_pair(min_max.first,min_max.second),transAmt));
		min_max=minMax(netMoney);
	}
	// cout<<"prinitng edges\n";

	// printing equivalent transactions
	for(auto x:ans){
		cout<<"prinitng"<<endl;
		cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<endl;
	}

}

int main(){
	int n,m,u,v,w;
	cin>>n>>m;

	vvi adj;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		vi vect{u,v,w};
		adj.push_back(vect);
	}

	for(auto x:adj){
		cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
	}

	minimizeCashFlow(adj,n);
}
