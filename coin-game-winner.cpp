// program to solve coing game winner
// link:https://www.geeksforgeeks.org/coin-game-winner-every-player-three-choices/

#include<bits/stdc++.h>
using namespace std;
#define vb vector<bool>

bool winnerA(int n,int x,int y){
	vb dp(n+1,false);

	dp[0]=false;
	dp[1]=true;
	
	for(int i=2;i<=n;i++){
		if(i-1>=0 and !dp[i-1]){
			dp[i]=true;
		}
		else if(i-x>=0 and !dp[i-x]){
			dp[i]=true;
		}
		else if(i-y>=0 and !dp[i-y]){
			dp[i]=true;
		}
		else{
			dp[i]=false;
		}
	}

	return dp[n];


}

int main(){
	int n,x,y;
	cin>>n>>x>>y;
	cout<<winnerA(n,x,y)<<endl;
}