// program to print power set for a string

#include<bits/stdc++.h>
using namespace std;
#define vs vector<string>

bool my_compare(string a, string b)
{
    // Check if a string is present as
    // prefix in another string, then
    // compare the size of the string
    // and return the larger size
    if (a.compare(0, b.size(), b) == 0
        || b.compare(0, a.size(), a) == 0)
  
        return a.size() > b.size();
  
    // Else return lexicographically
    // smallest string
    else
        return a < b;
}

class Solution
{
public:
	vector<string> AllPossibleStrings(string s){
		int n=s.length();
		vector<string> ans;
		for(int i=1;i<(1<<(n));i++){
			int pos=0;
			int p=1;
			string temp="";
			while(p<(1<<(n))){
				if(p&i){
					// pos bit is active
					temp+=s[pos];
				}
				p<<=1;
				pos+=1;
			}
			ans.push_back(temp);
		}
		sort(ans.begin(),ans.end());
		return ans;
	} 
};

int main(){
	int tc;
	cin>>tc;
	while(tc--){
		string s;
		cin>>s;
		Solution ob;
		vs res=ob.AllPossibleStrings(s);
		for(auto x:res){
			cout<<x<<endl;
		}
	}
}