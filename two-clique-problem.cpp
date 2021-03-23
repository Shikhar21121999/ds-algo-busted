// program to solve two clique problem

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector <vpii>
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define si stack<int>
#define ll long long
#define vll vector<ll>
#define qi queue<int>
#define minpq priority_queue<int,vi,greater<int>>
#define space " "

bool isBipartiteUtil(vvi &G, int src, int colorArr[]) 
{ 
	int V=G.size();
    colorArr[src] = 1; 
  
    // Create a queue (FIFO) of vertex numbers and enqueue 
    // source vertex for BFS traversal 
    queue <int> q; 
    q.push(src); 
  
    // Run while there are vertices in queue (Similar to BFS) 
    while (!q.empty()) 
    { 
        // Dequeue a vertex from queue 
        int u = q.front(); 
        q.pop(); 
  
        // Find all non-colored adjacent vertices 
        for (int v = 0; v < V; ++v) 
        { 
            // An edge from u to v exists and destination 
            // v is not colored 
            if (G[u][v] && colorArr[v] == -1) 
            { 
                // Assign alternate color to this adjacent 
                // v of u 
                colorArr[v] = 1 - colorArr[u]; 
                q.push(v); 
            } 
  
            // An edge from u to v exists and destination 
            // v is colored with same color as u 
            else if (G[u][v] && colorArr[v] == colorArr[u]) 
                return false; 
        } 
    } 
  
    // If we reach here, then all adjacent vertices can 
    // be colored with alternate color 
    return true; 
} 
  
// Returns true if a Graph G[][] is Bipartite or not. Note 
// that G may not be connected. 
bool isBipartite(vvi &G) 
{ 
    // Create a color array to store colors assigned 
    // to all veritces. Vertex number is used as index in 
    // this array. The value '-1' of  colorArr[i] 
    // is used to indicate that no color is assigned to 
    // vertex 'i'.  The value 1 is used to indicate first 
    // color is assigned and value 0 indicates 
    // second color is assigned. 
    int V=G.size();
    int colorArr[V]; 
    for (int i = 0; i < V; ++i) 
        colorArr[i] = -1; 
  
    // One by one check all not yet colored vertices. 
    for (int i = 0; i < V; i++) 
        if (colorArr[i] == -1) 
            if (isBipartiteUtil(G, i, colorArr) == false) 
                return false; 
  
    return true; 
} 

bool is_bipartite(vvi &adj){
	int n=adj.size();
	vi color(n,-1);
	qi q;
	for(int i=0;i<n;i++){
		if(color[i]==-1){
			color[i]=1;
			q.push(i);
			while(!q.empty()){
				int curr_node=q.front();
				q.pop();
				// color the adjacent node with different color
				for(int j=0;j<n;j++){
					if(adj[curr_node][j] and color[j]!=-1 and color[j]==color[curr_node]){
						return false;
					}
					if(adj[i][j] and color[j]==-1){
						color[j]=!color[curr_node];
						q.push(j);
					}
				}
			}
		}
	}
	return true;
}

bool isTwoClique(vvi &adj){
	// first we find the complement of the graph
	int n=adj.size();

	cout<<"original graph\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<adj[i][j]<<" "; 
		}
		cout<<endl;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			adj[i][j] = (i != j)?  !adj[i][j] : 0; 
		}
	}
	cout<<"modified graph\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<adj[i][j]<<" "; 
		}
		cout<<endl;
	}

	// checking if complement is bipartite graph
	return is_bipartite(adj);
}

int main(){
	int n;
	cin>>n;

	vvi adj(n,vi(n,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>adj[i][j];
		}
	}

	cout<<isTwoClique(adj);
}