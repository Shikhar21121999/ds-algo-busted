// program to solve phone directory
// problem

#include<bits/stdc++.h>
using namespace std;
#define vs vector<string>

const int CHAR_SIZE=28;

class Trie
{
public:
	Trie* children[CHAR_SIZE];
	bool isEndOfWord;

	// constructor
	Trie(){
		this->isEndOfWord=false;
		for(int i=0;i<CHAR_SIZE;i++){
			this->children[i]=nullptr;
		}
	}

	void insert(string);
	void printPrefixDirectory(Trie*&,string);
	vs getString(Trie*&);
	bool hasChildren(Trie*&);
};

// iterative function to see if the trie node has a children or not
// bool Trie::hasChildren(Trie*& curr){
// 	for(int i=0;i<CHAR_SIZE;i++){
// 		if(curr->children[i]!=nullptr){
// 			return true;
// 		}
// 		return false;
// 	}
// }

// iterative function to insert a string in the trie
void Trie::insert(string key){
	Trie *curr=this;
	for(int i=0;i<key.length();i++){
		if(curr->children[key[i]-'a']==nullptr){
			curr->children[key[i]-'a']=new Trie();
		}
		curr=curr->children[key[i]-'a'];
	}
	curr->isEndOfWord=true;
}

// iterative recursive function
// to return a vector of string
vs Trie::getString(Trie*& head){
	vs ans;
	
	Trie* curr=head;
	// base case
	if(curr->isEndOfWord){
		// return an empty string as vector of string
		ans.push_back("");
	}
	for(int i=0;i<CHAR_SIZE;i++){
		if(curr->children[i]!=nullptr){
			// there will be one or more string coming from recursion
			// of this trie
			vs temp=getString(curr->children[i]);

			// add the current character as prefix to all the string
			// and push them into the ans
			for(auto x:temp){
				char p=i+'a';
				x.insert(0,1,p);
				ans.push_back(x);
			}
		}
	}
	return ans;
}

// utility function to print all the string in the trie
// with a particular prefix (query)
void Trie::printPrefixDirectory(Trie*& head,string query){
	Trie* curr=head;
	for(int i=0;i<query.length();i++){
		string prefix=query.substr(0,i+1);
		if(curr->children[query[i]-'a']==nullptr){
			while(i<query.length()){
				cout<<0<<endl;
				i++;
			}
		}
		else{
			vs temp=curr->getString(curr->children[query[i]-'a']);
			for(auto x:temp){
				cout<<prefix<<x<<" ";
			}
			cout<<endl;
			curr=curr->children[query[i]-'a'];
		}
	}
	
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		Trie* head=new Trie();
		string inp;
		vs ans;
		for(int i=0;i<n;i++){
			cin>>inp;
			head->insert(inp);
		}

		string qer;
		cin>>qer;
		head->printPrefixDirectory(head,qer);	
	}
	
}
