// program to solve remove invalid parenthesis problem
// link:https://leetcode.com/problems/remove-invalid-parentheses/

#include <bits/stdc++.h>
using namespace std;

bool is_balanced(string s){
	int open_cnt=0,close_cnt=0;
	int n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]=='('){
			open_cnt+=1;
		}
		else if(s[i]==')'){
			// no of open brackets encountered till now
			// should be greater than or equal to no of close bracket
			// including it
			close_cnt+=1;
			if(close_cnt>open_cnt){
				return false;
			}
		}
	}
	if(open_cnt!=close_cnt)return false;
	return true;
}

string without_char(string a,int pos){
	// function to return a string which has all character except
	// the character at postion pos
	a.erase(pos,1);
	return a;
}

void backtrack(string str,unordered_map <string,int> &ans,int &max_length){
	// base case
	// we get an emty string
	int n=str.length();
	
	//first we check if the current string is balanced
	//if it is and its length is 
	if(is_balanced(str)){
		if(n<max_length){
			return;
		}
		ans[str]+=1;
		max_length=max(max_length,n);
		return;
	}
	
	// as the string is not balanced we try to make it balanced
	// by removing a character from it
	// recursive case
	for(int i=0;i<n;i++){
		// create a string which has all the characters
		// except this character
		// do
		string new_str=without_char(str,i);
		// recur
		backtrack(new_str,ans,max_length);
		// no undo as we used an additional string
	}
}
	

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		unordered_map <string,int> ans;
		int max_length=0;
		backtrack(s,ans,max_length);
		vector <string> fans;
        for(auto x:ans){
            if(max_length==x.first.length()){
                fans.push_back(x.first);
            }
        }
        for(auto x:fans){
			cout<<x<<endl;
		}
		
	}
}
