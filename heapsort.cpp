// program to implement heap sort

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

void heapify(int a[],int n,int i){
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<n and a[largest]<a[left]){
		largest=left;
	}
	if(right<n and a[largest]<a[right]){
		largest=right;
	}
	if(largest!=i){
		swap(a[largest],a[i]);
		heapify(a,n,largest);
	}
}

void buildHeap(int a[],int n){
	int lastLeafIndex=(n/2)-1;
	for(int i=lastLeafIndex;i>=0;i--){
		heapify(a,n,i);
	}
}

void heapsort(int a[],int n){

	// first we have to ensure that the array is a heap
	// perform build heap on the array to get the heap
	for(int i=n/2-1;i>=0;i--){
		heapify(a,n,i);
	}

	// one by one extract an element from heap
	for(int i=n-1;i>0;i--){
		swap(a[0],a[i]);
		heapify(a,i,0);
	}

}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	heapsort(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}