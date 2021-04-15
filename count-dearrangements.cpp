// program to count number of dearrangements

#include<bits/stdc++.h>
using namespace std;

int dearrangementCnt(int n){
	if(n==0 || n==1)return 0;
	if(n<=3)return n-1;
	int minus1=2;
	int minus2=1;
	int curr=0;
	for(int i=4;i<=n;i++){
		curr=(i-1)*(minus1+minus2);
		minus2=minus1;
		minus1=curr;
	}
	return curr;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<dearrangementCnt(n)<<endl;
	}

}