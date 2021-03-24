// program to implement trie data structure
// along with its basic functions from scratch
// here we are using trie with array
// using classes

#include <bits/stdc++.h>
using namespace std;

const int CHAR_SIZE=128;

class Trie
{
public:
	bool isEndOfWord;
	Trie* children[CHAR_SIZE];

	// constructor
	Trie()
	{
		this->isEndOfWord=false;
		for(int i=0;i<CHAR_SIZE;i++){
			this->children[i]=nullptr;
		}
	}
	// function on a trie object
	void insert(string);
	bool search(string);
	bool deletion(Trie*&,string);
	bool haveChildren(Trie const*);
};

//Iterative function to insert a string to a trie
void Trie::insert(string key){
	// start from root node
	// cout<<"inserting key\n";
	Trie *curr=this;
	// cout<<curr<<endl;
	for(int i=0;i<key.length();i++){
		// cout<<"curr character "<<key[i]<<endl;
		if(curr->children[key[i]]==nullptr){
			// cout<<"adding character ";
			curr->children[key[i]]=new Trie();
			// cout<<curr->children[key[i]]<<endl;
		}

		// go to the next node
		curr=curr->children[key[i]];
	}
	curr->isEndOfWord=true;
}

//Iterative function to search a string in a trie
bool Trie::search(string key){
	// return falsse if trie is empty
	if(this==nullptr){
		return false;
	}
	// start from root node
	Trie *curr=this;
	// cout<<"searcing "<<key<<endl;
	for(int i=0;i<key.length();i++){
		// cout<<key[i]-'a'<<" "<<curr<<" "<<curr->children[key[i]]<<endl;
		if(curr->children[key[i]]==nullptr){
			// cout<<"maamla atak gya\n";
			return false;
		}
		curr=curr->children[key[i]];
	}
	return (curr!=nullptr && curr->isEndOfWord);
	// for (int i = 0; i < key.length(); i++)
 //    {
 //        // go to the next node
 //        curr = curr->children[key[i]];
 //        cout<<key[i]<<" "<<curr->children[key[i]]<<endl;
 
 //        // if the string is invalid (reached end of a path in the Trie)
 //        if (curr == nullptr) {
 //            return false;
 //        }
 //    }
 
    // // return true if the current node is a leaf and the
    // // end of the string is reached
    // return curr->isEndOfWord;
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

//Recursive function to delete a key in the trie4
// here true false represents wether parent node of trie
// has to be deleted or not
bool Trie::deletion(Trie*& curr,string key){

	// if trie is empty
	if(curr==nullptr){
		return false;
	}

	// if end of the word is not reached
	if(key.length()){
		// recurse for the node corrosponding to the next character
		// in the string
		// and if it returns true delete the current node if it is not and end of word
		if(curr!=nullptr and 
			curr->children[key[0]]!=nullptr and 
			deletion(curr->children[key[0]],key.substr(1)) and 
			!curr->isEndOfWord){
			if(!haveChildren(curr)){
				// delete the curr node
				delete curr;
				curr=nullptr;

				// inform to delete the parent node also
				return true;
			}
			else{
				return false;
			}
		}
	}

	// if end of the key is reached
	if(key.length()==0 && curr->isEndOfWord){
		// here there will be two conditions
		// 1. if this trie node is the leaf node and does not have any other children
		if(!haveChildren(curr)){
			// delete the current node
			delete curr;
			curr=nullptr;

			// inform to delete parent node in the recursive call
			// as parent effectively does not have current node as children
			// but may have other children
			return true;
		}
		// 2. current node is a leaf node but also has some other children
		else{
			curr->isEndOfWord=false;

			// don't delete the parent node as curr has some children
			return false;
		}

	}

	return false;

}

int main()
{
	// cout<<"hello"<<endl;
    Trie* head = new Trie();
 
    head->insert("hello");
    // cout<<"searching for hello\n";
    cout << head->search("hello") << " ";      // print 1
 
    head->insert("helloworld");
    // cout<<"searching for helloworld\n";
    cout << head->search("helloworld") << " "; // print 1
 
    cout << head->search("helll") << " ";      // print 0 (Not found)
 
    head->insert("hell");
    cout << head->search("hell") << " ";       // print 1
 
    head->insert("h");
    cout << head->search("h");                 // print 1
 
    cout << endl;
 
    head->deletion(head, "hello");
    cout << head->search("hello") << " ";      // print 0
 
    cout << head->search("helloworld") << " "; // print 1
    cout << head->search("hell");              // print 1
 
    cout << endl;
 
    head->deletion(head, "h");
    cout << head->search("h") << " ";          // print 0
    cout << head->search("hell") << " ";       // print 1
    cout << head->search("helloworld");        // print 1
 
    cout << endl;
 
    head->deletion(head, "helloworld");
    cout << head->search("helloworld") << " "; // print 0
    cout << head->search("hell") << " ";       // print 1
 
    head->deletion(head, "hell");
    cout << head->search("hell");              // print 0
 
    cout << endl;
 
    if (head == nullptr) {
        cout << "Trie empty!!\n";              // Trie is empty now
    }
 
    cout << head->search("hell");              // print 0
 
    return 0;
}
