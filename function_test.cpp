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

void solve(){
	set<int> s;
	for(int i=5;i>0;i--){
		s.insert(i);
	}
	for(auto itr=s.begin();itr!=s.end();itr++){
		cout<<*itr;
	}
	cout<<endl;
	auto itr=s.begin();
	cout<<*itr;
	advance(itr,3);
	cout<<*itr;
	s.erase(*itr);
	for(auto itr=s.begin();itr!=s.end();itr++){
		cout<<*itr;
	}
}

bool is_reg(string a){
	int op_brac_cnt=0;
	int clo_brac_cnt=0;
	for(int i=0;i<a.length();i++){
		if(clo_brac_cnt>op_brac_cnt)return false;
		if(a[i]=='('){
			op_brac_cnt++;
		}
		else if(a[i]==')'){
			clo_brac_cnt++;
		}
	}
	if(op_brac_cnt!=clo_brac_cnt)return false;
	return true;
}

int main(){
	string inp;
	cin>>inp;
	cout<<is_reg(inp);
	
	
	
}
