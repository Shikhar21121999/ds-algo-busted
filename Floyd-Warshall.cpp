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
		for(int k=0;k<v;k++){
			for(int i=0;i<v;i++){
				for(int j=0;j<v;j++){
					if (matrix[i][k] + matrix[k][j] < matrix[i][j]) 
                    matrix[i][j] = matrix[i][k] + matrix[k][j]; 
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
