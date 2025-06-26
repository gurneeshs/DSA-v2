/*
    https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1
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
vector<int> zigZagTraversal(node* root) {
        // Code here
        vector<int> result;
        if(root==NULL){
            return result;
        }
        queue<node*> q;
        q.push(root);
        bool leftToRight = true;
        
        while(!q.empty()){
            int siz = q.size();
            vector<int> temp(siz);
            for(int i=0;i<siz;i++){
                node* frontnode = q.front();
                q.pop();
                int index = leftToRight ? i : siz-i-1;
                temp[index] = frontnode->data;
                
                if(frontnode->left){
                    q.push(frontnode->left);
                }
                if(frontnode->right){
                    q.push(frontnode->right);
                }
            }
            for(auto el:temp){
                result.push_back(el);
            }
            leftToRight = !leftToRight;
        }
        return result;
    }