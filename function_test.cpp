// program to test various paramter passing
// in functions for different types of ds

#include <bits/stdc++.h>
using namespace std;
# define vi vector <int>
# define vvi vector <vi>


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
	
	// p[3]=true;
}

// print the vector
void print_vvi(vvi a){
	for(auto x:a){
		for(auto y:x){
			cout<<y<<" ";
		}
		cout<<endl;
	}
}

void print_vi(vi a){
	for(auto x:a){
		cout<<x<<" ";
	}
	cout<<endl;
}

// conclusion vector gets modified if a refrence is passed
void func1(vvi &a){
	a[0][0]=1;
} 

// this does not lead to changes in array
void func2(const vvi a){
	// a[0][0]=1;
}


int main(){
	vi a={4,5,8,6,9};
	vi b;
	for(auto x:a){
		b.push_back(x);
	}
	sort(b.begin(),b.end());
	print_vi(a);
	print_vi(b);
	
	
	
}
