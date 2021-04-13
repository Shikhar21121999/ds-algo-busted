// program to solve word break problem using trie and iterative dp
// this is bottom up approach

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
const int ALPH_SIZE=26;
class Trie{
public:
	Trie* children[ALPH_SIZE];
	bool isEnd;

	Trie(){
		this->isEnd=false;
		for(int i=0;i<ALPH_SIZE;i++){
			this->children[i]=nullptr;
		}
	}
	void insert(string);
};

void Trie::insert(string key){
	Trie *curr=this;
	int n=key.length();

	for(int i=0;i<n;i++){
		if(curr->children[key[i]-'a']==nullptr){
			curr->children[key[i]-'a']=new Trie();
		}
		curr=curr->children[key[i]-'a'];
	}
	curr->isEnd=true;
}


int wordBreak(string line,vector<string> dict){
	int n=line.length();

	Trie *head=new Trie();
	for(auto x:dict){
		head->insert(x);
	}

	// word break solution starts here
	vi good(n+1,0);

	// good[i] represent wether substring of line starting from 0
	// of length i can be partitioned into words of the dictionary
	good[0]=1;


	for(int i=0;i<n;i++){
		if(good[i]){
			Trie *curr=head;
			for(int j=i;j<n;j++){
				if(curr==nullptr){
					break;
				}
				curr=curr->children[line[j]-'a'];
				if(curr!=nullptr && curr->isEnd){
					good[j+1]=true;
				}
			}
		}
	}
	return good[n];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<string> dict;
		for(int i=0;i<n;i++){
			string inp;
			cin>>inp;
			dict.push_back(inp);
		}

		string line;
		cin>>line;
		cout<<wordBreak(line,dict);
	}
}