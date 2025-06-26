/*
    https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1
*/
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter the data" << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }
    root = new node(data);
    cout << "Enter the data for inserting in left of " << data << ": ";
    root->left = buildTree(root->left);

    cout << "Enter the data for inserting in right of " << data << ": ";
    root->right = buildTree(root->right);
}

vector<int> diagonal(node *root)
{
   // your code here
   vector<int> ans;
   if(root==NULL){
       return ans;
   }
   
   queue<node*> curr, next;
   curr.push(root);
   
   while(!curr.empty()){
       node* temp = curr.front();
       curr.pop();
       
       ans.push_back(temp->data);
       
       if(temp->left){
           next.push(temp->left);
       }
       if(temp->right){
           curr.push(temp->right);
       }
       
       if(curr.empty() && !next.empty()){
           curr.push(next.front());
           next.pop();
       }
   }
   return ans;
}