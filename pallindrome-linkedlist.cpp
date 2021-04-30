// program to identify wether a linked list is a pallindrome

#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
	ListNode* next;
	int val;

	// constructor
	ListNode(int data){
		this->next=nullptr;
		this->val=data;
	}
};

// function to find length of linked list
// that is the number of nodes in the linked list
int getLength(ListNode* head){
	// if length of linked list is 0
	if(head==nullptr)return 0;

	ListNode* curr=head;
	int cnt=1;
	while(curr->next!=nullptr){
		curr=curr->next;
		cnt+=1;
	}
	return cnt;
}	


// function to print linked list
void printList(ListNode* head){
	// list is empty
	if(head==nullptr){
		cout<<"Nothing to print\n";
	}

	ListNode* curr=head;
	while(curr!=nullptr){
		cout<<curr->val<<" ";
		curr=curr->next;
	}
	cout<<endl;
	return;
}

// function to reverse a linked list
// by changing connections
ListNode* revLinkList(ListNode *head){
	// if list has either 0 or 1 node
	// then reverse of linked list is same as current
	if(head==nullptr){
		return nullptr;
	}
	if(head->next==nullptr){
		return head;
	}

	ListNode *prevNode,*currNode,*nextNode;
	prevNode=head;
	currNode=head->next;
	nextNode=currNode->next;
	head->next=nullptr;
	while(nextNode!=nullptr){
		// reverse connections
		currNode->next=prevNode;

		// update previousNode,currNode,nextNode
		prevNode=currNode;
		currNode=nextNode;
		nextNode=nextNode->next;
	}
	// reversing connections for last node
	currNode->next=prevNode;
	head=currNode;
	// printList(head);
	return currNode;
}

// function to check for pallindrom list
bool isPalindrome(ListNode* head){
	// if list is empty or only has 1 node
	// it is always a pallindrom list
	if(head==nullptr or head->next==nullptr){
		return true;
	}

	// get the length of the list
	int lenlist=getLength(head);

	ListNode* curr=head;

	// now we take the half of list
	// and reverse it and then traverse them at the same time
	// and check if they are pallindrome

	// splitting the list into two list of equal length (even)
	ListNode* head2;
	int nodeNo=1;
	while(nodeNo<lenlist/2){
		curr=curr->next;
		nodeNo++;
	}

	// if even
	if(lenlist%2==0){
		head2=curr->next;
		curr->next=nullptr;
	}
	else{
		head2=curr->next->next;
		curr->next=nullptr;
	}
	// cout<<head->val;
	// cout<<head2->val;

	// reverse the first half of the linked list
	head=revLinkList(head);
	// cout<<head->val;

	// printing two parts
	printList(head);
	printList(head2);

	curr=head;
	ListNode *curr2=head2;
	// if(curr->val!=curr2->val)return false;
	while(curr!=nullptr and curr2!=nullptr){
		if(curr->val!=curr2->val){
			return false;
			
		}
		curr=curr->next;
		curr2=curr2->next;
	}
	return true;
}

// main function
int main(){
	ListNode* head=new ListNode(1);
	head->next=new ListNode(2);
	head->next->next= new ListNode(3);
	// head->next->next->next= new ListNode(1);
	// head->next->next->next->next= new ListNode(1);	
	printList(head);
	// cout<<getLength(head)<<endl;
	// head=revLinkList(head);
	// printList(head);
	cout<<isPalindrome(head);
}
