/*
    https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
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

vector<int> topView(node *root) {
        // code here
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
            
            node* front = temp.first;
            int hd = temp.second;
            
            if(m.find(hd) == m.end()){
                m[hd] = front->data;
            }
            if(front->left){
                q.push(make_pair(front->left,hd-1));
            }
            if(front->right){
                q.push(make_pair(front->right,hd+1));
            }
        }
        for(auto hd:m){
            // hd ---> <int,int>
            ans.push_back(hd.second);
        }
        return ans;
    }
