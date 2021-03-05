#include <bits/stdc++.h>
using namespace std;
# define pii pair<int,int>
int movex[4]={1,-1,0,0};
int movey[4]={0,0,+1,-1};
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // get initial color of the source cell
        int oldcolor=image[sr][sc];
        vector<vector<bool> > vis(55,vector<bool>(55,false));
        image[sr][sc]=newColor;
        pii cell=make_pair(sr,sc);
        vis[sr][sc]=true;
        queue <pii> q;
        q.push(cell);

        while(!q.empty()){
            cell=q.front();
            q.pop();

            // mark all of its adjacent cells that had the old color
            // be colored with new color and push them into the queue
            // so that there adjacent cells can also be colored
            for(int i=0;i<4;i++){
                int nextx=cell.first+movex[i];
                int nexty=cell.second+movey[i];
                if(nextx>=0 and nextx<image.size() and nexty>=0 and
                 nexty<image[0].size() and image[nextx][nexty]==oldcolor and !vis[nextx][nexty]){
                    // valid cell
                    vis[nextx][nexty]=true;
                    image[nextx][nexty]=newColor;
                    q.push(make_pair(nextx,nexty));
                }
            }
        }
        return image;
    }
};


int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<vector<int> > image(n,vector<int>(m));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>image[i][j];
			}
		}
		int sr,sc;
		cin>>sr>>sc;
		int new_color;
		cin>>new_color;
		Solution obj;
		vector<vector<int> > ans=obj.floodFill(image,sr,sc,new_color);
		for(auto x:ans){
			for(auto y:x){
				cout<<y<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
