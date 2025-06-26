/*
    https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
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
vector<vector<int>> verticalOrder(node *root) {
        // Your code here
        map<int,map<int,vector<int> > > nodes;
        queue<pair<node*, pair<int,int> > > q;
        
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
            pair<node*, pair<int,int> > temp = q.front();
            q.pop();
            
            node* frontnode = temp.first;
            int hd = temp.second.first;
            int levl = temp.second.second;
            
            nodes[hd][levl].push_back(frontnode->data);
            
            if(frontnode->left){
                q.push(make_pair(frontnode->left, make_pair(hd-1,levl+1)));
            }
            if(frontnode->right){
                q.push(make_pair(frontnode->right, make_pair(hd+1,levl+1)));
            }
        }
        for(auto i:nodes){
            // i --> hd i.first--> hd, i.second--> pair
            vector<int> temp;

            for(auto j:i.second){
                // j--> <int,vector<int>>
                for(auto k:j.second){
                    temp.push_back(k);
                }
            }
            ans.push_back(temp);

        }
        return ans;
        
    }
