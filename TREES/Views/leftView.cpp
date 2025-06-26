/*
    https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1
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
void left(node* root, int levl, vector<int>& ans){
        if(root==NULL){
            return;
        }
        if(levl==ans.size()){
            // new level
            ans.push_back(root->data);
        }
        if(root->left){
            left(root->left,levl+1,ans);
        }
        if(root->right){
            left(root->right,levl+1,ans);
        }
        return;
    }
    vector<int> leftView(node *root) {
        // code here
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        left(root,0,ans);
        return ans;
    }