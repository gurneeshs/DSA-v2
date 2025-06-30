
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

node* insertInBST(node* root, int data){
    if(root==NULL){
        root = new node(data);
        return root;
    }
    if(data>root->data){
        root->right = insertInBST(root->right,data);
    }
    else{
        root->left = insertInBST(root->left,data);
    }
    return root;
}

int minInBST(node* root){
    if(root==NULL){
        return -1;
    }
    if(root->left==NULL && root->right==NULL){
        return root->data;
    }

    node* temp = root;
    while(temp!=NULL){
        if(temp->left){
            temp=temp->left;
        }
        else{
            break;
        }
    }
    return temp->data;
}

int maxInBST(node* root){
    // O(1) space complexity
    if(root==NULL){
        return -1;
    }
    if(root->left==NULL && root->right==NULL){
        return root->data;
    }

    node* temp = root;
    while(temp!=NULL){
        if(temp->right){
            temp=temp->right;
        }
        else{
            break;
        }
    }
    return temp->data;
}

int main(){
    node* root;
    root = NULL;
    int dat;
    cin>>dat;
    while(dat!=-1){
        root = insertInBST(root,dat);
        cin>>dat;
    }
    levelOrderTraversal(root);
    cout<<endl;
    cout<<minInBST(root)<<endl;
    return 0;
}