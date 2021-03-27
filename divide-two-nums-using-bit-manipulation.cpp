// program to divide two numbers using bit manipulation

#include <bits/stdc++.h>
using namespace std;

int divideutil(int a,int b){
	// cout<<a<<" "<<b<<endl;
	if(a<b)return 0;
	int p=1;
	while(b*p<=a){
		p=p<<1;
	}
	p=p>>1;
	return (p+divideutil(a-p*b,b));
}

int divide(int a,int b){
	if(a<0 && b<0){
		return divideutil(abs(a),abs(b));
	}
	if(a<0 or b<0){
		return -divideutil(abs(a),abs(b));
	}
	return divideutil(abs(a),abs(b));
}

int main(){
	int a,b;
	cin>>a>>b;
	cout<<divide(a,b)<<endl;
	return 0;
}