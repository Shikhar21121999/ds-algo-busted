// program to determine min. cost to a board of dim mXn
// into pieces of unit area

#include <bits/stdc++.h>
using namespace std;


void solve(){
	int m,n;
	cin>>m>>n;
	
	// Vertical cut
	vector <int> hor_cut(m),vert_cut(n);
	for(int i=0;i<m;i++){
		cin>>hor_cut[i];
	}
	for(int i=0;i<n;i++){
		cin>>vert_cut[i];
	}
	
	// sort both the arrarys
	sort(vert_cut.begin(),vert_cut.end(),greater<int>());
	sort(hor_cut.begin(),hor_cut.end(),greater<int>());
	
	// initially we have a whole block
	// which has 1 vert_col and 1 hor_row
	int vert_col=1,hor_row=1;
	int i=0,j=0;
	int total_cost=0;
	while(i<m and j<n){
		// greedily pickup the one which has the highest cost ryt
		// after the current cut the cost will increase further
		if(vert_col*hor_cut[i]>=hor_row*vert_cut[j]){
			total_cost+=vert_col*hor_cut[i];
			hor_row++;
			i++;
		}
		else{
			total_cost+=hor_row*vert_cut[j];
			vert_col++;
			j++;
		}
	}
	
	// remaining vert cuts
	// hor_rows will remain constant
	// so we get the total cost of vert_cuts and multiply it with hor_rows
	int total_cut_cost=0;
	while(j<n){
		total_cut_cost+=vert_cut[j];
		j++;
	}
	total_cost+=total_cut_cost*hor_row;
	
	// remaining hor cuts
	// vert_cols will remain costant
	// so we get the total cost of hor_cuts and multiply it with vert_cols
	total_cut_cost=0;
	while(i<m){
		total_cut_cost+=hor_cut[i];
		i++;
	}
	total_cost+=total_cut_cost*vert_col;
	cout<<total_cost;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
