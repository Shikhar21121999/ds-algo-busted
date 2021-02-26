// program to solve word break problem
// and print all its solution
// Link:https://practice.geeksforgeeks.org/problems/word-break-part-2/0

#include <bits/stdc++.h>
using namespace std;

string add_string(string prev,string nword){
	if(prev.size()==0){
		return nword;
	}
	string ans=prev+" ";
	ans.append(nword);
	return ans;
}

void print_ans(vector <string> &ans){
	if(ans.size()==0){
		cout<<"Empty"<<endl;
		return;
	}
	sort(ans.begin(),ans.end());
	for(auto x:ans){
		cout<<"("<<x<<")";
	}
	cout<<endl;
}

void backtrack(int st,string S,unordered_map <string,int> &dic_words,
		vector<string> &ans,string prev_sent){
			// base case
			int n=S.length();
			if(st==n){
				// we got the strgin
				ans.push_back(prev_sent);
				return;				
			}
			
			// recur case
			for(int j=1;j+st<=n;j++){
				// get the substring
				string temp_str=S.substr(st,j);
				// cout<<temp_str<<endl;
				if(dic_words[temp_str]>0){
					// cout<<prev_sent<<" "<<temp_str<<" "<<st<<" "<<j<<endl;
					// this word exist in the dictionary
					
					// do
					temp_str=add_string(prev_sent,temp_str);
					// recur
					backtrack(j+st,S,dic_words,ans,temp_str);
					// no need to undo anything
				}
			}
		}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string dic_str;
		unordered_map <string,int> dic_words;
		for(int i=0;i<n;i++){
			cin>>dic_str;
			dic_words[dic_str]++;
		}
		string S;
		cin>>S;
		vector <string> ans;
		ans.reserve(n);
		backtrack(0,S,dic_words,ans,"");
		print_ans(ans);
	}
}
