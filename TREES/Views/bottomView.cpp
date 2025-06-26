/*
    https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
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
vector<int> bottomView(node *root) {
        // Your Code Here
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        map<int,int> m;
        queue<pair<node*, int> > q;
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<node*, int> temp = q.front();
            q.pop();
            node* frontnode = temp.first;
            int hd = temp.second;
            
            m[hd] = frontnode->data;
            if(frontnode->left){
                q.push(make_pair(frontnode->left,hd-1));
            }
            if(frontnode->right){
                q.push(make_pair(frontnode->right,hd+1));
            }
        }
        for(auto el:m){
            ans.push_back(el.second);
        }
        return ans;
    }
