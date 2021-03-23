// program to implement trie data structure
// along with its basic functions from scratch
// here we are using trie with array

#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE=26;

//Trie node
struct  TrieNode
{
	// to store address to child node linked to a particular alphabet
	struct  TrieNode *children[ALPHABET_SIZE];
	bool isEndOfWord;
};

//Returns new trie node initialized to null
struct TrieNode *getNode(void)
{
	// initialize a new trie node
	struct TrieNode *newNode=new TrieNode;

	newNode->isEndOfWord=false;

	// mark all the child nodes for alphabets as null initially
	for(int i=0;i<ALPHABET_SIZE;i++){
		newNode->children[i]=NULL;
	}
	return newNode;
};

// function to search a key or string in the trie
bool search(struct TrieNode *root,string key){

	// get the address of the root node
	// which can then be used to traverse the trie
	struct TrieNode *pcrawl=root;
	for(int i=0;i<key.length();i++){
		// get the index corrosponding to the character of the key
		int ind=key[i]-'a';
		if(pcrawl->children[ind]==NULL){
			return false;
		}
		// go to the next index
		pcrawl=pcrawl->children[ind];
	}
	return (pcrawl!=NULL && pcrawl->isEndOfWord);
}

// function to insert a key into the trie
void insert(struct TrieNode *root,string key){
	// for insertion we first traverse in the trie
	// till we get the prefix same
	struct TrieNode *pcrawl=root;
	for(int i=0;i<key.length();i++){
		int ind=key[i]-'a';
		if(!pcrawl->children[ind]){
			pcrawl->children[ind]=getNode();
		}
		pcrawl=pcrawl->children[ind];
	}

	// mark the last node as leaf
	pcrawl->isEndOfWord=true;
}

int main(){
	// Input keys (use only 'a' through 'z'
    // and lower case)
    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);
  
    struct TrieNode *root = getNode();
  
    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);
  
    // Search for different keys
    search(root, "the")? cout << "Yes\n" :
                         cout << "No\n";
    search(root, "these")? cout << "Yes\n" :
                           cout << "No\n";
    return 0;
}