// program to solve word break problem
// using trie data structure

#include<bits/stdc++.h>
using namespace std;

const int CHAR_SIZE=26;

class Trie
{
public:
	Trie *children[CHAR_SIZE];
	bool isEndOfWord;

	// constructor
	Trie(){
		this->isEndOfWord=false;
		for(int i=0;i<CHAR_SIZE;i++){
			this->children[i]=nullptr;
		}
	}
	bool search(string);
	void insert(string);
};

// Iterative function to search a key in the trie
bool Trie::search(string key){
	Trie* curr=this;
	for(int i=0;i<key.length();i++){
		if(curr->children[key[i]-'a']==nullptr){
			return false;
		}
		curr=curr->children[key[i]-'a'];
	}
	return (curr!=nullptr and curr->isEndOfWord);
}

// Iterative function to insert a key in the trei
void Trie::insert(string key){
	Trie* curr=this;
	for(int i=0;i<key.length();i++){
		if(curr->children[key[i]-'a']==nullptr){
			curr->children[key[i]-'a']=new Trie();
		}
		curr=curr->children[key[i]-'a'];
	}
	curr->isEndOfWord=true;
}

// Recursive function to solve the word break problem
bool wordBreak(Trie *curr,string word){

	int n=word.size();
	// base case
	if(n==0)return true;

	// recursive case
	// break the word into two words
	// first word should exist in the trie
	// second word should completely or should exist in the trie in pieces
	for(int i=1;i<=n;i++){
		if(curr->search(word.substr(0,i)) and wordBreak(curr,word.substr(i))){
			return true;
		}
	}
	return false;
}

int main()
{
    // number of string in the array
	int n;
	cin>>n;

	// initialize a trie
	Trie *head=new Trie();

	// insert dictionary words in the trie
	string ip;
	for(int i=0;i<n;i++){
		cin>>ip;
		head->insert(ip);
	}
	
	int m;
	cin>>m;
	vector <string> inp(m);
	for(int i=0;i<m;i++){
		cin>>inp[i];
	}

	// print word break for all the string
	for(int i=0;i<m;i++){
		cout<<wordBreak(head,inp[i])<<endl;
	}
}
