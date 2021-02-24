// K-centeres problem

// Link:https://www.geeksforgeeks.org/k-centers-problem-set-1-greedy-approximate-algorithm/

// K-centeres problem is a NP-Hard problem
// Solution for it is a 2 approximate greedy algorithm

// first line of input contains a single integer n which denotes
// number of cities and number of atm to be placed
// next line contain an integer p denoting number of edges given
// each line has 3 integers which denote the distance between 2 cities


#include <bits/stdc++.h>
using namespace std;

vector <vector <int> > G;
vector <bool> is_atm;

void solve(){
	int n,k;
	cin>>n>>k;
	
	G.resize(n+1,vector <int> (n+1,0));
	is_atm.resize(n+1,false);
	
	int p;
	cin>>p;
	
	// input edges
	int cit1,cit2,dis;
	for(int i=0;i<p;i++){
		cin>>cit1>>cit2>>dis;
		G[cit1][cit2]=dis;
		G[cit2][cit1]=dis;
	}
	
	// mark first city as atm city
	is_atm[1]=true;
	
	vector <int> atm_city;
	atm_city.push_back(1);
	
	for(int i=1;i<k;i++){
		// selecting k-1 atms
		
		int max_dis=0;
		int city_max_dis=-1;
		for(auto x:atm_city){
			// find the  city that has max distance
			// from this atm city	
			for(int i=1;i<=n;i++){
				if(is_atm[i])continue;
				if(G[x][i]>max_dis){
					max_dis=G[x][i];
					city_max_dis=i;
				}
			}
		}
		// now we add an atm to this city
		is_atm[city_max_dis]=true;
		atm_city.push_back(city_max_dis);
	}
	
	// print all the cities that have an atm
	for(auto x:atm_city){
		cout<<x<<" ";
	}
	cout<<"\n";
	
}	

int main(){
	solve();
}
