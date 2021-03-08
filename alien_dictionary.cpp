// program to solve alien dictionary

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void topsort_util(int node,vector <int> adj[],stack <int> &ans,vector <int> &vis){
		// visit all the child nodes if possible
		for(auto x:adj[node]){
			if(!vis[x]){
				vis[x]=1;
				topsort_util(x,adj,ans,vis);
				ans.push(x);
			}
		}
	}
	string topoSort(int V,vector <int> adj[]){
		// perform a bfs and keep count of visited vertices

		// an outer loop to perform topological sort on all
		stack <int> ans;
		vector <int> vis(V,0);
		for(int i=0;i<V;i++){
			if(!vis[i]){
				vis[i]=1;
				topsort_util(i,adj,ans,vis);
				ans.push(i);
			}			
		}
		// vector <int> retans;
		
		// we need to make a string out of it
		// char c = (char)a;
		string fans="";
		while(!ans.empty()){
			int curr=ans.top();
			// cout<<curr<<" ";
			ans.pop();
			fans+=char(curr+int('a'));
			// retans.push_back(curr);
		}
		// cout<<fans;

		return fans;
	}
    int first_diff_char(string a,string b){
    	int i=0;
    	// cout<<a<<" "<<b<<endl;
    	while(i<a.length() && i<b.length()){
    		if(a[i]!=b[i]){
    			return i;
    		}
    		i++;
    	}
    	return -1;
    }
    string findOrder(string dict[], int N, int K) {
        
        // making an adjacency list graph
        vector<int> adj[K];
        vector<vector<int>> vis(K,vector<int>(K,0));

        for(int i=0;i<N;i++){
        	for(int j=i+1;j<N;j++){
        		if(dict[i]!=dict[j]){
        			// cout<<dict[i]<<" "<<dict[j]<<endl;
        			// find the index of first character that is different in both of them
        			int diff_char_ind=first_diff_char(dict[i],dict[j]);
        			if(diff_char_ind!=-1 && vis[dict[i][diff_char_ind]-'a'][dict[j][diff_char_ind]-'a']==0){
        				// create a directed edge from dict[i][diff_char_ind] to dict[j][diff_char_ind]
        				adj[dict[i][diff_char_ind]-'a'].push_back(dict[j][diff_char_ind]-'a');
        				vis[dict[i][diff_char_ind]-'a'][dict[j][diff_char_ind]-'a']=1;
        				// cout<<dict[i]<<" "<<dict[j]<<" "<<diff_char_ind<<" "<<dict[i][diff_char_ind]<<" "<<dict[j][diff_char_ind]<<endl;
        			}
        		}
        	}
        }

        // print the processed graph
        // for(int i=0;i<K;i++){
        // 	for(auto x:adj[i]){
        // 		cout<<i<<" "<<x<<"\n";
        // 	}
        // }

        // now we need to perform topological sort on this
        string ans=topoSort(K,adj);

        return ans;
    }
};

string order;
bool f(string a,string b){
	int p1=0;
	int p2=0;
	for(int i=0;i<min(a.size(),b.size()) and p1==p2;i++){
		p1=order.find(a[i]);
		p2=order.find(b[i]);
	}

	if(p1==p2 and a.size()!=b.size())return a.size() < b.size();

	return p1<p2;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int N,K;
		cin>>N>>K;
		string dict[N];
		for(int i=0;i<N;i++){
			cin>>dict[i];
		}
		Solution obj;
		string ans=obj.findOrder(dict,N,K);
		// order="";
		// for(int i=0;i<ans.size();i++){
		// 	order+=ans[i];
		// }
		// string temp[N];
		// copy(dict,dict+N,temp);
		// sort(temp,temp+N,f);

		// bool f=true;

		// for(int i=0;i<N;i++){
		// 	if(dict[i]!=temp[i])f=false;
		// }

		// if(f)cout<<1;
		// else cout<<0;
		// cout<<endl;
		cout<<ans<<endl;
	}
	return 0;
}
