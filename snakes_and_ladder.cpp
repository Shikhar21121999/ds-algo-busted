#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define gi greater<int>
#define vvi vector<vi>

#define vb vector<bool>
class Solution {
public:
    int n;
    int snakesAndLadders(vector<vector<int>>& board) {
        // function to find the min number of steps to reach
        // n*n
        n=board.size();
        vb vis(n*n+1,false);
        queue <int> q;
        q.push(1);
        vis[1]=true;
        int steps=0;
        while(!q.empty()){
        	cout<<steps<<endl;
        	int s=q.size();
        	while(s--){
        		int curr=q.front();
        		cout<<"curr is :"<<curr<<endl;
        		q.pop();

        		// now we try all the values from curr
        		for(int i=1;i<=6;i++){
        			int next=curr+i;
        			cout<<"next initial :"<<next<<endl;

        			if(next>n*n)continue;

        			// now for recursion we need to check where this
        			// number leads on board
        			pii ncords=getCoor(next);
        			cout<<"corr cords "<<ncords.first<<" "<<ncords.second<<endl; 
        			// now if there is a snake or ladder then we need to go
        			// to the destination of snake or ladder
        			if(board[ncords.first][ncords.second]!=-1)next=board[ncords.first][ncords.second];

        			// now if this next is already present
        			if(vis[next])continue;
        			// in case ladder leads to final position
        			if(next==n*n)return steps+1;
        			cout<<"next final :"<<next<<endl;
        			vis[next]=true;
        			q.push(next);
        		}
        	}
        	steps++;
        }
        return -1;
    }
    
    // to get the coords of number in the grid
    pair<int,int> getCoor(int num) {
        int row=(n-1)-(num-1)/n;
        int col;
        if(row%2!=0){
        	// even n
        	col=(num-1)%n;
        }
        else{
        	// odd n
        	col=(n-1)-((num-1)%n);
        }
        return make_pair(row,col);
    }
};

int main(){
	int tc;
	cin>>tc;
	while(tc--){
		int v;
		cin>>v;
		vector<vector<int>> adj(v,vi(v,0));
		for(int i=0;i<v;i++){
			for(int j=0;j<v;j++){
				cin>>adj[i][j];
			}
		}

		for(int i=0;i<v;i++){
			for(int j=0;j<v;j++){
				cout<<adj[i][j]<<" ";
			}
			cout<<endl;
		}

		Solution obj;
		int ans=obj.snakesAndLadders(adj);
		cout<<ans<<endl;

	}
}