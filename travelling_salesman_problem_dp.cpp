// program to solve travelling salesman problem using recursion
// and hash map

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define gi greater<int>
#define vvi vector<vi>

int VISITED_ALL;
vector<vector<int>> adj;
vvi dp;
int n;

int tsp(int mask,int pos){
   if(mask==VISITED_ALL){
      // means a hamiltonian path is found
      // so we return the path from curr node to the starting node
      return adj[pos][0];
   }

   // lookup
   if(dp[mask][pos]!=-1){
      return dp[mask][pos];
   }

   // now we try to go from current node to all the node
   // and store the min ans 
   int ans=INT_MAX;
   for(int i=0;i<n;i++){
      // check if current node is already visited or not
      if((mask&(1<<i))==0){
         int new_ans=tsp((mask|(1<<i)),i)+adj[pos][i];
         ans=min(new_ans,ans);
      }
   }

   return dp[mask][pos]=ans;
}

int main(){
   int tc;
   cin>>tc;
   while(tc--){
      // int n;
      cin>>n;
      adj.resize(n,vi(n,-1));
      dp.resize(1<<n,vi(n,-1));
      for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
            cin>>adj[i][j];
         }
      }

      for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
            cout<<adj[i][j]<<" ";
         }
         cout<<endl;
      }

      VISITED_ALL=(1<<n)-1;
      cout<<VISITED_ALL<<endl;

      cout<<tsp(1,0);
   }
}