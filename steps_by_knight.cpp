// program to sove steps_by_knight problem
// link:https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1

#include <bits/stdc++.h>
using namespace std;

vector < vector <int> > dp(1008,vector<int>(1108,-1));
int movex[8]={ 2, 2, -2, -2, +1, -1, +1, -1 };
int movey[8]={ 1, -1, 1, -1, 2, 2, -2, -2 };
class Solution{
	public:
		int minStepToReachTarget(vector <int> &KnightPos,vector <int> &TargetPos,int N){
			// base case invalid coords
			int i=KnightPos[0];
			int j=KnightPos[1];
			cout<<i<<" "<<j<<endl;
			if(i<=0 or j<=0 or i>N or j>N){
				cout<<"shit got real"<<endl;
			}
			// base case answer already computed
			if(dp[i][j]!=-1)return dp[i][j];
			
			// base case answer found
			if(i==TargetPos[0] and j==TargetPos[1])return 0;
			
			// recursive case
			int nextx;
			int nexty;
			int min_dis=INT_MAX;
			for(int k=0;k<8;k++){
				nextx=i+movex[k];
				nexty=j+movey[k];
				// check and recurse for these coords
				if(nextx>0 and nexty>0 and nextx<=N and nexty<=N){
					// perform recursion and find the min path
					// do
					KnightPos[0]=nextx;
					KnightPos[1]=nexty;
					// recur
					min_dis=min(min_dis,minStepToReachTarget(KnightPos,TargetPos,N));
					// redo
					KnightPos[0]=i;
					KnightPos[1]=j;
				}
			}
			return dp[i][j]=min_dis;
					
		}
}; 


int main(){
	int tc;
	cin>>tc;
	while(tc--){
		vector<int> KnightPos(2);
		vector<int> TargetPos(2);
		int N;
		cin>>N;
		cin>>KnightPos[0]>>KnightPos[1];
		cin>>TargetPos[0]>>TargetPos[1];
		 Solution obj;
		 int ans=obj.minStepToReachTarget(KnightPos,TargetPos,N);
		 cout<<ans<<"\n";
	}
	return 0;
}
