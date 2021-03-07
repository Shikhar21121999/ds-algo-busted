

#include <bits/stdc++.h>
using namespace std;

int movex[8]={ -1, -1, -1, 0, 0, +1, +1, +1 };
int movey[8]={ -1, 0, +1, -1, +1, -1, 0, +1 };

class Solution {
public:
	bool is_valid(int a,int b,vector<vector<char>>& grid){
		int n=grid.size();
		int m=grid[0].size();
		return (a>=0 && a<n && b>=0 && b<m && grid[a][b]=='1');
	}
	void dfs(int i,int j,vector<vector<char>>& grid,vector <vector <int>> &vis){
		// mark the current node as visited
		vis[i][j]=1;

		// perform dfs for all the 8 adjacent nodes
		int nxtx;
		int nxty;
		for(int k=0;k<8;k++){
			nxtx=i+movex[k];
			nxty=j+movey[k];

			// if these cordinates contain and unvisited land
			if(is_valid(nxtx,nxty,grid) && !vis[nxtx][nxty]){
				// push these cordinates into the stack
				// vis[nxtx][nxty]=1;
				dfs(nxtx,nxty,grid,vis);				
			}
		}
		return;
	}
	int numIslands(vector<vector<char>>& grid) {
        
        // every isolated '1' is an island in itself
		// so we just need to find the number of disconnected 1
		// two 1 are connected if they lie in one of the 8 directions to each other
		int n=grid.size();
		int m=grid[0].size();
		vector <vector <int>> vis(n,vector<int> (m,0));
		stack<pair <int,int> > s;
		// we perform bfs on all the linked edges
		int cnt=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(grid[i][j]=='1' && vis[i][j]==0){
					// this is seperate component
					cnt++;
					dfs(i,j,grid,vis);
					// s.push(make_pair(i,j));
					// vis[i][j]=1;
					// pair<int,int> curr_node;
					// while(!s.empty()){
					// 	curr_node=s.top();
					// 	s.pop();

					// 	// there are 8 possibilites for each cell
					// 	int nxtx;
					// 	int nxty;
					// 	for(int k=0;k<8;k++){
					// 		nxtx=curr_node.first+movex[k];
					// 		nxty=curr_node.second+movey[k];

					// 		// if these cordinates contain and unvisited land
					// 		if(is_valid(nxtx,nxty,grid) && !vis[nxtx][nxty]){
					// 			// push these cordinates into the stack
					// 			vis[nxtx][nxty]=1;
					// 			s.push(make_pair(nxtx,nxty));
					// 		}
					// 	}
					// }
				}
			}
		}
		return cnt;
    }
};

int main(){
	int tc;
	cin>>tc;
	while(tc--){
		int n,m;
		cin>>n>>m;
		vector<vector<char>>grid(n,vector <char> (m,'#'));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>grid[i][j];
			}
		}
		Solution obj;
		int ans=obj.numIslands(grid);
		cout<<ans<<'\n';
	}
	return 0;
}
