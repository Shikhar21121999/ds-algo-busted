// program to find shortest unique prefix
// for every word of array of string

#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE=26;

class Trie
{
public:
	Trie *children[ALPHABET_SIZE];
	int freq;

	// constructor to initialize a trie node
	Trie(){
		for(int i=0;i<ALPHABET_SIZE;i++){
			this->children[i]=nullptr;
		}
		this->freq=1;
	}
	void insert(string);
	string shortestUniquePrefix(string);
};

// Iterative function to insert a string into the trie
void Trie::insert(string key){
	Trie *curr=this;
	for(int i=0;i<key.length();i++){
		if(curr->children[key[i]-'a']==nullptr){
			curr->children[key[i]-'a']=new Trie();
		}
		else{
			curr->children[key[i]-'a']->freq++;
		}
		// move forward in the trie
		curr=curr->children[key[i]-'a'];
	}
}

// iterative function to find shortest unique prefix for the string
string Trie::shortestUniquePrefix(string key){
	Trie *curr=this;
	string ans="";
	for(int i=0;i<key.length();i++){
		if(curr->children[key[i]-'a']->freq==1){
			ans+=key[i];
			break;
		}
		ans+=key[i];
		curr=curr->children[key[i]-'a'];
	}
	return ans;
}

int main(){
	// number of string in the array
	int n;
	cin>>n;

	// initialize a trie
	Trie *head=new Trie();

	vector <string> inp(n);
	for(int i=0;i<n;i++){
		cin>>inp[i];
		head->insert(inp[i]);
	}

	// print shortest unique prefix for all the strings
	for(int i=0;i<n;i++){
		cout<<head->shortestUniquePrefix(inp[i])<<endl;
	}
}