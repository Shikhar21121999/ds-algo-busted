// program to build a heap in array representation
#include<bits/stdc++.h>
using namespace std;

void heapify(int a[],int n,int i){
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<n and a[left]>a[largest]){
		largest=left;
	}
	if(right<n and a[right]>a[largest]){
		largest=right;
	}
	if(largest!=i){
		swap(a[i],a[largest]);
		heapify(a,n,largest);
	}
	return;
}

void buildheap(int arr[],int n){
	// for building a heap we heapify the tree using recurison bottom up approach
	// we don't need to heapify leaf nodes

	int lastleafind=(n/2)-1;
	for(int i=lastleafind;i>=0;i--){
		heapify(arr,n,i);
	}
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	buildheap(arr,n);

	// print the heapified array
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

}