// program to solve word ladder problem
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool valid_edge(string a,string b){
		int cnt=0;
		for(int i=0;i<a.length();i++){
			if(a[i]!=b[i])cnt++;
			if(cnt>1)return false;
		}
		return true;
	}
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        // preliminary check
        // check if endWord is present in wordList
        int end_ind=-1;
        for(int i=0;i<wordList.size();i++){
        	if(endWord==wordList[i]){
        		end_ind=i;
        		break;
        	}
        }
        if(end_ind==-1)return 0;

        // now end word exist and we need to check if it is possible
        // to go from beginWord to endWord

        // push the beginWord into wordList and create a graph for it
        wordList.push_back(beginWord);
        int n=wordList.size();

        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++){
        	for(int j=i+1;j<n;j++){
        		if(valid_edge(wordList[i],wordList[j])){
        			graph[i].push_back(j);
        			graph[j].push_back(i);
        		}
        	}
        }

        // // print the graph
        // cout<<"begin word :"<<wordList[n-1]<<endl;
        // cout<<"end word : "<<wordList[end_ind]<<endl;

        // for(int i=0;i<n;i++){
        // 	for(auto x:graph[i]){
        // 		cout<<wordList[i]<<" "<<wordList[x]<<endl;
        // 	}
        // }

        // now we need to find the shortest distance between begin word index n-1
        // and end word index end_ind
        pair<int,int> node=make_pair(n-1,0);
        queue<pair<int,int>> q;
        vector<int> vis(n+1,0);

        q.push(node);
        vis[node.first]=1;

        while(!q.empty()){
        	node=q.front();
        	if(node.first==end_ind){
        		return node.second+1;
        	}
        	q.pop();

        	// perform bfs on all unvisited graph
        	for(auto x:graph[node.first]){
        		if(!vis[x]){
        			vis[x]=1;
        			q.push(make_pair(x,node.second+1));
        		}
        	}
        }

        // path between begin word and end word does not exist
        return 0;

    }
};

int  main(){
	string beginWord,endWord;
	cin>>beginWord>>endWord;
	int n;
	cin>>n;
	vector<string> wordList(n);
	string tempstr;
	for(int i=0;i<n;i++){
		cin>>wordList[i];
	}

	// make an object of the solution and call the function
	Solution obj;
	int ans=obj.ladderLength(beginWord,endWord,wordList);
	cout<<ans<<endl;
}