/*
    https://www.geeksforgeeks.org/problems/sum-tree/1
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
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

pair<bool,int> sumTree(node* root){
        if(root==NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        if(root->left==NULL && root->right==NULL){
            pair<bool,int> p = make_pair(true,root->data);
            return p;
        }

        pair<bool,int> left = sumTree(root->left);
        pair<bool,int> right = sumTree(root->right);
        pair<bool,int> ans;
        
        if((root->data == (left.second + right.second)) && left.first && right.first){
            ans.first = true;
        }
        else{
            ans.first = false;
        }
        ans.second = root->data + left.second + right.second;
        return ans;
    }
    bool isSumTree(node* root) {
        // Your code here
        return sumTree(root).first;
        
    }