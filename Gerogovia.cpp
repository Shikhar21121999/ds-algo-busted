// program to solve georgovia problem
// link:https://www.spoj.com/problems/GERGOVIA/

#include <bits/stdc++.h>
using namespace std;

int abs_diff(long long a,long long b){
	// function to calculate abs difference
	long long diff=a-b;
	if(diff<0){
		return -1*diff;
	}
	return diff;
}

void solve(int n){
	// create a vector of size n
	vector <pair <long,long> >buyer,seller;
	buyer.reserve(n/2+10);
	seller.reserve(n/2+10);
	long long inhab=0;
	for(int i=1;i<=n;i++){
		cin>>inhab;
		if(inhab>0){
			// means he is a buyer
			buyer.push_back(make_pair(i,inhab));
		}
		else if(inhab<0){
			// means he is a seller
			seller.push_back(make_pair(i,-1*(inhab)));
		}
	}
	
	int i=0,j=0;
	long long work_done=0;
	while(i<buyer.size() and j<seller.size()){
		// make the transaction of as much wine 
		// as possible between current buyer and seller
		
		int wine_transac=min(buyer[i].second,seller[j].second);
		work_done+=wine_transac*abs_diff(buyer[i].first,seller[j].first);
		
		
		// make changes into the stock of buyer and seller
		buyer[i].second-=wine_transac;
		seller[j].second-=wine_transac;
		
		// increment the counter for the buyer or seller
		// if they get required wine or stock is over respecitvely
		if(buyer[i].second==0){
			i+=1;
		}
		else if(seller[j].second==0){
			j+=1;
		}
	}
	
	// as buyer requirement and seller stock are equal
	// at the end all have zero and no wine will be left
	
	cout<<work_done<<"\n";
}
		
	

int main(){
	while(true){
		int n;
		cin>>n;
		if(n==0)break;
		solve(n);
	}
	return 0;
}
