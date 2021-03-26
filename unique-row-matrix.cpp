// program to print unique rows in a binary matrix
// using trie data structure

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
const int CHAR_SIZE=2;

class Trie
{
public:
	Trie* children[CHAR_SIZE];
	bool isEnd;

	// constructor
	Trie ()
	{
		for(int i=0;i<CHAR_SIZE;i++){
			this->children[i]=nullptr;
		}
		this->isEnd=false;
	}
	void insert(vector<int>);
	vvi getRows(Trie*&);
};

// iterative function to insert a row vector<int>
void Trie:: insert(vi a){
	int n=a.size();
	Trie *curr=this;
	for(int i=0;i<n;i++){
		if(curr->children[a[i]]==nullptr){
			curr->children[a[i]]=new Trie();
		}
		curr=curr->children[a[i]];
	}
	curr->isEnd=true;
}


// iterative+recursive function to get all the rows
// in the trie
vvi Trie:: getRows(Trie*& head){
	vvi ans;

	Trie *curr=head;
	// base case
	if(curr->isEnd){
		// return an empty vector int
		vi temp;
		ans.push_back(temp);
		return ans;
	}

	// recursive case
	for(int i=0;i<CHAR_SIZE;i++){
		if(curr->children[i]!=nullptr){
			vvi temp=getRows(curr->children[i]);

			// add the current number to all of the vectors
			for(auto x:temp){
				x.push_back(i);
				ans.push_back(x);
			}
		}
	}
	return ans;
}

int main()
{
	Trie* head=new Trie();
	vi a{1,0,0,1};
	vi b{0,0,1,1};
	head->insert(a);
	head->insert(b);
	head->insert(a);
	vvi ans=head->getRows(head);
	for(auto x:ans){
		reverse(x.begin(),x.end());
		for(auto y:x){
			cout<<y<<" ";
		}
		cout<<endl;
	}

}
