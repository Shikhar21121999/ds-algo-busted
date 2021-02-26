// program to test string functions in C++

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


int main(){
	string inp;
	int ind;
	cin>>inp>>ind;
	cout<<without_char(inp,ind);
}
