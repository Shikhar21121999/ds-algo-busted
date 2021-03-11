// Floyd warshall algo
// use adjacency matrix representation here

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define gi greater<int>
#define vvi vector<vi>

class Solution{
public:
	void shortest_distance(vvi &matrix){
		int v=matrix.size();
		int INF=INT_MAX;
		// here we are considering both possibilities
		// that is if a cell has negative values
		// then that edge does not exist and it is impossible to go through that
		// also if distance to and edge is INf then that edge also does not exist
		for(int k=0;k<v;k++){
			for(int i=0;i<v;i++){
				for(int j=0;j<v;j++){
					if (matrix[i][k]<INF && matrix[k][j]<INF && matrix[i][k]+matrix[k][j]<INF and matrix[i][k]!=-1 and matrix[k][j]!=-1 and matrix[i][j]!=-1) 
                    matrix[i][j] = min(matrix[i][j],matrix[i][k] + matrix[k][j]); 
				}
			}
		}

		for(int i=0;i<v;i++){
			for(int j=0;j<v;j++){
				if(matrix[i][j]>=INF){
					matrix[i][j]=-1;
				}
			}
		}
	}
};

int main(){
	int tc;
	cin>>tc;
	while(tc--){
		int n;
		cin>>n;
		vvi matrix(n,vi(n,-1));
		int u,v,e;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<matrix[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
