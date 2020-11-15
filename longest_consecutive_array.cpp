#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(n==1){
        cout<<1<<endl;
        return;
    }
    sort(arr,arr+n);
    int curr_seq=1;
    int over_all_seq=0;
    for(int i=1;i<n;i++){
        if(arr[i]-arr[i-1]==1){
            curr_seq++;
        }
        else if(arr[i]==arr[i-1]){
            curr_seq=curr_seq;
        }
        else{
            curr_seq=1;
        }
        over_all_seq=max(over_all_seq,curr_seq);
    }
    cout<<over_all_seq<<endl;
}
int main() {
ios::sync_with_stdio(0);
cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
	int test;
	cin>>test;
	while(test--){
	    solve();
	}
	return 0;
}
