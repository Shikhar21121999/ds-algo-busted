// program to test various paramter passing
// in functions for different types of ds

#include <bits/stdc++.h>
using namespace std;


void print_vector (const vector <bool> p){
	for(auto x:p){
		cout<<x<<" ";
	}
	cout<<endl;
}



void const_pass(vector <bool> &p){
	p[0]=true;
	print_vector(p);
}

void pointer_pass(vector <bool>* p){
	p[3]=true;
}

int main(){
	int n;
	cin>>n;
	vector <bool> ans(n,false);
	print_vector(ans);
	const_pass(ans);
	pointer_pass(&ans);
	print_vector(ans);
}
