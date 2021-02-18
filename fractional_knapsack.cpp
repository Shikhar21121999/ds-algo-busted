// program to find max achievable amount
// in a given knapsack (factional)
// we cannot take multiple item of same type

#include <bits/stdc++.h>
using namespace std;
// class implemented
struct Item{
	int weight;
	int value;
};

bool comp(Item const &a,Item const &b){
	// can fail when both have same value
	// but remainder of one is greater
	double r1=(double)a.value/(double)a.weight;
	double r2=(double)b.value/(double)b.weight;
	return r1>r2;
}

// function to return functional wieghts
double fractionalKnapsack(int W,Item arr[], int n){
	
	// sort arr
	sort(arr,arr+n,comp);
	double profit=0.0;
	for(int i=0;i<n;i++){
		// if space to take full item
		if(arr[i].weight<W){
			profit+=arr[i].value;
			W-=arr[i].weight;
		}
		// space left for only partial item
		else if(arr[i].weight>W){
			profit+=((double)W/(double)arr[i].weight)*arr[i].value;
			W=0;
			break;
		}
	}
	return profit;
}

int main(){
	return 0;
}
