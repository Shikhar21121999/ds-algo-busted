// program to determine if its possible to
// survive on the island and if yes 
// min no of days to buy food from the shop for survival

#include <bits/stdc++.h>
using namespace std;

bool survival_possible(int S,int hunger,int food_buy){
	if(hunger>food_buy)return false;
	if(S>6 and (6*S-7*hunger)>=0){
		return true;
	}
	if(S<=6 and hunger<=food_buy)return true;
	return false; 
		
}

void solve(){
	// no of days to survive, food required for each day
	// max food that can be bought each day from shop
	int sur_days,hunger,food_buy;
	cin>>sur_days>>hunger>>food_buy;
	
	if(!survival_possible(sur_days,hunger,food_buy)){
		cout<<"No\n";
	}
	else{
		// calculate min_days to buy food
		int min_days=(sur_days*hunger)/food_buy;
		if((sur_days*hunger)%food_buy!=0)min_days++;
		cout<<"Yes "<<min_days<<"\n";
	}
}
	


int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
