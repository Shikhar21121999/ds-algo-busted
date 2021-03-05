// program to clone a graph
// link:https://leetcode.com/problems/clone-graph/

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*.>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    void dfs(Node* orig_curr,Node* copy_curr,vector<Node*> &visited){
        visited[copy_curr->val]=copy_curr;
        // visit all the neighbours of curr node
        for(auto x:orig_curr->neighbors){
            if(visited[x->val]==NULL){
                Node* newnode=new Node(x->val);
                copy_curr->neighbors.push_back(newnode);
                dfs(x,newnode,visited);
            }
            else{
                copy_curr->neighbors.push_back(visited[x->val]);
            }
        }
    }
    Node* cloneGraph(Node* node){
        vector<Node*> visited(1000,NULL);
        if(node==NULL){
            return NULL;
        }
        Node* copy=new Node(node->val);
        visited[node->val]=copy;

        // iterate for all neighbours
        for(auto x:node->neighbors){
            if(visited[x->val]==NULL){
                // create a new node
                Node* newnode=new Node(x->val);
                copy->neighbors.push_back(newnode);
                // perform dfs to develop the edges that are linked to this node
                dfs(x,newnode,visited);
            }
            else{
                copy->neighbors.push_back(visited[x->val]);
            }
        }
    }
};


// first we try to create a simple graph using these nodes
int main(){
    Node* graph_st=new Node(1);
    Node* two=new Node(2);
    Node* three=new Node(3);
    Node* four=new Node(4);
    graph_st->neighbors.push_back(two);
    graph_st->neighbors.push_back(three);
    two->neighbors.push_back(four);
    four->neighbors.push_back(three);


}
