// program to multiply two numbers
// using bit manipulation

#include <bits/stdc++.h>
using namespace std;

int binmul(int a,int b){
	int res=0;
	while(b>0){
		if(b&1){
			res+=a;
		}
		a+=a;
		b>>=1;

	}
	return res;
}

int main(){
	int a,b;
	cin>>a>>b;
	cout<<binmul(a,b);
}