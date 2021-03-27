// program to copy set bits in a range
// link: https://www.geeksforgeeks.org/copy-set-bits-in-a-range/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int x,y,l,r;
	cin>>x>>y>>l>>r;

	int p=1<<(l-1);
	while(l<=r){
		// check if the bit is activated in y
		if(p&y){
			x=x|p;
		}
		p=p<<1;
		l++;
	}
	cout<<x<<endl;
}