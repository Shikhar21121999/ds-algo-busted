// program to solve word wrap problem
// link:https://www.geeksforgeeks.org/word-wrap-problem-dp-19/

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>


int printSolution (int p[], int n) 
{ 
    int k; 
    if (p[n] == 1) 
        k = 1; 
    else
        k = printSolution (p, p[n]-1) + 1; 
    cout<<"Line number "<<k<<": From word no. "<<p[n]<<" to "<<n<<endl; 
    return k; 
} 

// function to solve word wrap problem
// using iterative dp
void solveWordWrap1(vi a,int n,int k){
	// to compute and store extra space left
	// after putting subarray i to j in a line
	int extraSpace[n+1][n+1];
	for(int i=1;i<=n;i++){
		extraSpace[i][i]=k-a[i-1];
		for(int j=i+1;j<=n;j++){
			extraSpace[i][j]=k-extraSpace[i][j-1]-1-a[j-1];
		}
	}
	cout<<"calculated extraSpace\n";


	// to store the cost of filling the words from i to j
	// in a single line
	int cost[n+1][n+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cost[i][j]=INT_MAX;
			if(extraSpace[i][j]<0){
				cost[i][j]=INT_MAX;
			}
			// cost for last word sequence is 0
			else if(j==n and extraSpace[i][j]>=0){
				cost[i][j]=0;
			}
			else{
				cost[i][j]=extraSpace[i][j]*extraSpace[i][j];
			}
		}
	}
	cout<<"calculated cost\n";

	int p[n+1];
	int c[n+1];

	c[0]=0;
	for(int j=1;j<=n;j++){
		c[j]=INT_MAX;
		for(int i=1;i<=j;i++){
			if(c[i-1]!=INT_MAX && cost[i][j]!=INT_MAX && (c[i-1]+cost[i][j]<c[j])){
				c[j]=c[j-1]+cost[i][j];
				p[j]=i;
			}
		}
	}
	cout<<"calculated till now\n";
	printSolution(p,n);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vi a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int k;
		cin>>k;
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
		cout<<k<<endl;
		solveWordWrap1(a,n,k);
	}
	return 0;
}