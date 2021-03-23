// program to implement trie data structure
// along with its basic functions from scratch
// here we are using trie with array
// using classes

#include <bits/stdc++.h>
using namespace std;

const int CHAR_SIZE=26;

class Trie
{
public:
	bool isEndOfWord;
	Trie* children[CHAR_SIZE];

	// constructor
	Trie()
	{
		this->isEndOfWord=false;
		for(int i=0;i<n;i++){
			this->children[i]=nullptr;
		}
	}
	// function on a trie object
	void insert(string);
	bool search(string);
	bool deletion(Trie*&,string);
	bool haveChildren(Trie const*);
}

//Iterative function to insert a string to a trie
void Trie::insert(string key){
	// start from root node
	Trie *curr=this;
	for(int i=0;i<key.length();i++){
		if(curr->children[key[i]]==nullptr){
			curr->children[key[i]]=new Trie();
		}

		// go to the next node
		curr=curr->children[key[i]];
	}
	curr->isEndOfWord=true;
}

//Iterative function to search a string in a trie
void Trie::search(string key){
	// start from root node
	Trie *curr=this;
	for(int i=0;i<key.length();i++){
		if(curr->children[key[i]]==nullptr){
			return false;
		}
		curr=curr->children[key[i]];
	}
	return (curr!=nullptr && curr->isEndOfWord);
}

//Returns true if given node has any children
bool Trie::haveChildren(Trie const* curr){
	for(int i=0;i<CHAR_SIZE;i++){
		if(curr->children[i]!=nullptr){
			return true;
		}
	}
	return false;
}