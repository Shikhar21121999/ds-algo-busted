// programto solve largest independent subset sum problem
// basically we find the length of maximum number of nodes in a binary tree
// such that there is no edges between any two nodes of binary tree

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	int liss;
	Node *left,*right;

	// constructor
	Node(int data){
		this->data=data;
		this->left=this->right=nullptr;
		this->liss=-2;
	}
};

int LISS(Node *root){

	// base case root is null
	if(root==nullptr){
		return 0;
	}

	// base case leaf node
	if(root->left==nullptr && root->right==nullptr){
		return 1;
	}

	// already calcluated
	if(root->liss!=-2){
		return root->liss;
	}

	// recursive case including the current one
	int incl=1;
	if(root->left!=nullptr){
		incl+=LISS(root->left->left)+LISS(root->left->right);
	}
	if(root->right!=nullptr){
		incl+=LISS(root->right->left)+LISS(root->right->right);
	}

	// recursive case not including the current one
	int excl=LISS(root->left)+LISS(root->right);

	return root->liss=max(incl,excl);
}

int main(){
	Node *root=new Node(20);
	root->left=new Node(8);
	root->left->left=new Node(4);
	root->left->right=new Node(12);
	root->left->right->left= new Node(10);
	root->left->right->right= new Node(14);
	root->right=new Node(22);
	root->right->right= new Node(25);

	cout<<LISS(root)<<endl;
	return 0;
}