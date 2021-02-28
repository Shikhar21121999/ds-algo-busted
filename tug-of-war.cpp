

#include <bits/stdc++.h>
using namespace std;
# define vb vector<bool>

void backtrack(int* arr,int curr_ind,vb curr_ele,vb &sol,int curr_selected,int* min_diff,int t_sum,int curr_sum,int n){
	// base case
	// we reach the end
	if(curr_ind==n){
		return;
	}
	// base case
	// number of elements left uptill now are greater than
	// what we should have left
	if((n/2-curr_selected)>(n-curr_ind)){
		return;
	}
	
	// if selected elements become greater than n/2
	// if(curr_selected>n/2){
	// 	return;
	//}
	
	// check if we have found a valid solution
	// if a valid solution is found then it is not possible
	// to find any other solution with these elements
	if(curr_selected==n/2 and abs(t_sum/2-curr_sum)<*min_diff){
		// update min_diff
		*min_diff=abs(t_sum/2-curr_sum);
		// update solution
		for(int i=0;i<n;i++){
			sol[i]=curr_ele[i];
		}
		return;
	}
	
	// recursive case
	// don't include the current element
	backtrack(arr,curr_ind+1,curr_ele,sol,curr_selected,min_diff,t_sum,curr_sum,n);
	
	// include the current element
	//do
	curr_ele[curr_ind]=true;
	curr_selected+=1;
	curr_sum+=arr[curr_ind];
	// recur
	backtrack(arr,curr_ind+1,curr_ele,sol,curr_selected,min_diff,t_sum,curr_sum,n);
	// redo
	curr_ele[curr_ind]=false;
}


// function to call backtrack and generate answer
// after recursion
void tugOfWar(int* arr, int n){
	// to store current elements in the array
	vector <bool> curr_ele(n,false),sol(n,false);
	int t_sum=0;
	int min_diff=INT_MAX;
	for(int i=0;i<n;i++){
		t_sum+=arr[i];
	}
	// int* arr,int curr_ind,vb curr_ele,vb &sol,int selected_ele,int &min_diff,int t_sum,int curr_sum
	backtrack(arr,0,curr_ele,sol,0,&min_diff,t_sum,0,n);
	
	// print the solution
	cout<<"first subset is:\n";
	for(int i=0;i<n;i++){
		if(sol[i])cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<"second subset is:\n";
	for(int i=0;i<n;i++){
		if(!sol[i])cout<<arr[i]<<" ";
	}
	cout<<endl;
	 
} 

void print_arr(int* arr){
	for(int i=0;i<11;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    tugOfWar(arr, n);
    return 0; 
}
