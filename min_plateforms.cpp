// program to print min plateforms
// needed to station all the incoming trains

#include <bits/stdc++.h>
using namespace std;


// method 1
int findPlateform(int arr[],int dep[],int n){
	
	// sort arr and dep arr
	sort(arr,arr+n);
	sort(dep,dep+n);
	
	// first train will always be from arr array
	// and we will need a plateform for this train
	int plat_count=1,i=1,j=0;
	int req=1;
	
	while(i<n and j<n){
		// select if at this instance train is arriving or departure
		
		if(arr[i]<=dep[i]){
			// train arrived need an extra plateform
			plat_count+=1;
			i+=1;
		}
		else if(dep[i]<arr[i]){
			// train departed so need 1 less plateform ryt now
			plat_count-=1;
			j+=1;
		}
		// get the max plateform count needed at any instant
		req=max(req,plat_count);
	}
	return req;
}


// method2
int findPlateform1(int arr[],int dep[],int n){
	
	// create an auxilary vector array which keeps count
	// of plateform needed at any instant
	// basically we increement or decrement the plateform at an
	// instant when train arrives or departs
	
	vector <int> plat_inst(2361,0);
	
	for(int i=0;i<n;i++){
		// increment the plateform count on arrival of train
		plat_inst[arr[i]]+=1;
		// increment the plateform count on departure of train
		plat_inst[dep[i]]-=1;
	}
	
	int req=1;
	// run a loop to find the plateform_required at an instant
	for(int i=1;i<2361;i++){
		plat_inst[i]+=plat_inst[i-1];
		
		// find the max
		req=max(req,plat_inst[i]);
	}
	return req;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		int dep[n];
		
		// input arrival array
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		// input dep array
		for(int i=0;i<n;i++){
			cin>>dep[i];
		}
		findPlateform(arr,dep,n);
	}
}
		
	
