/*
    https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1
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

pair<bool,int> isHeightBalanced(node* root){
        if(root==NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        pair<bool,int> leftAns = isHeightBalanced(root->left);
        pair<bool,int> rightAns = isHeightBalanced(root->right);
        int height = max(leftAns.second,rightAns.second) + 1;
        
        pair<bool,int> ans;
        bool diff ;
        if(leftAns.second>rightAns.second){
            diff = ((leftAns.second-rightAns.second)<=1);
        }
        else{
            diff = ((rightAns.second-leftAns.second)<=1);
        }
        if(diff && (leftAns.first && rightAns.first)){
            ans.first = true;
        }
        else{
            ans.first = false;
        }
        ans.second = height;
        
        return ans;
        
    }
    bool isBalanced(node* root) {
        // Code here
        return isHeightBalanced(root).first;
    }