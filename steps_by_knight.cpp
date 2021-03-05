// program to sove steps_by_knight problem
// link:https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1

#include <bits/stdc++.h>
using namespace std;
# define vi vector<int>
# define vvi vector<vi>
# define pii pair<int,int>
# define ppii pair<pii,int>
// first second

vector < vector <int> > dp(1008,vector<int>(1108,-1));
int movex[8]={ 2, 2, -2, -2, +1, -1, +1, -1 };
int movey[8]={ 1, -1, 1, -1, 2, 2, -2, -2 };
class Solution{
	public:
		int minStepToReachTarget(vector <int> &KnightPos,vector <int> &TargetPos,int N){
			// base case invalid coords
			vvi vis(N,vi(N+1));
			ppii cell=make_pair(make_pair(KnightPos[0],KnightPos[1]),0);
			queue<ppii> q;
			q.push(cell);
			while(!q.empty()){
				cell=q.front();
				q.pop();

				// if this is a target cell
				if(cell.first.first==TargetPos[0] && cell.first.second==TargetPos[1]){
					return cell.second;
				}

				// if some other cell
				// perform further traversal only if unvisited
				if(!vis[cell.first.first][cell.first.second]){
					vis[cell.first.first][cell.first.second]=1;
					// push all other valid steps into the queue
					int curr_x=cell.first.first;
					int curr_y=cell.first.second;
					for(int i=0;i<N;i++){
						int next_x=curr_x+movex[i];
						int next_y=curr_y+movey[i];
						// valid check
						if(next_x>0 && next_y>0 && next_x<=N && next_y<=N){
							// push in the queue
							q.push(make_pair(make_pair(next_x,next_y),cell.second+1));
						}
					}
				}
			}
			return 6969;
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
