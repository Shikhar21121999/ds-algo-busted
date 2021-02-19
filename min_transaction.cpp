// program to minimize the number of transactions
// between friends

#include <bits/stdc++.h>
using namespace std;
vector <int> amt_balance;
vector <vector <int> > G;
int n;

int getMax(){
	int a=INT_MIN;
	int ind=-1;
	for(int i=0;i<=n;i++){
		if(amt_balance[i]>a){
			ind=i;
			a=amt_balance[i];
		}
	}
	return ind;
}

int getMin(){
	int a=INT_MAX;
	int ind=-1;
	for(int i=0;i<=n;i++){
		if(amt_balance[i]<a){
			ind=i;
			a=amt_balance[i];
		}
	}
	return ind;
}

void print_transaction(){
	// first we get a min and max in the amt_balannce
	// which represent a person with max borrowing
	// and a person which deserves the max amount
	
	// person who has to return max
	int max_ret=getMax();
	int max_resc=getMin();
	
	if(amt_balance[max_ret]==0 and amt_balance[max_resc]==0){
		// implies all the dues have been cleared
		return;
	}
	
	// now we clear one of the two dues
	int min_of_two=min(amt_balance[max_ret],amt_balance[max_resc]);
	amt_balance[max_ret]-=min_of_two;
	amt_balance[max_resc]+=min_of_two;
	
	cout<<"Person"<<max_ret<<"pays"<<min_of_two<<"to Person"
	<<max_resc<<"\n";
}
	
	
	

void get_Amtbalance(){
	
	amt_balance.resize(n+1,0);
	
	// iterate over the graph to get
	// balance amt for each and every person
	for(int i=1;i<n;i++){
		for(int j=1;j<=n;j++){
			amt_balance[i]+=G[i][j];
			amt_balance[j]-=G[i][j];
		}
	}
}


int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		G.resize(n+1,vector <int>(n+1,0));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>G[i][j];
			}
		}
		get_Amtbalance();		
		
	}
}
