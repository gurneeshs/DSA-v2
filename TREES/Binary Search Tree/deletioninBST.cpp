

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
        int data = root->data;
        // delete root;
        return data;
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
    int data = root->data;
    // delete temp;
    return data;
}

int maxInBST(node* root){
    if(root==NULL){
        return -1;
    }
    if(root->left==NULL && root->right==NULL){
        int data = root->data;
        // delete root;
        return data;
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
    int data = root->data;
    // delete temp;
    return data;
}

node* deleteFromBST(node* root, int x){
    if(root==NULL){
        return root;
    }
    if(root->data==x){
       if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
       } 
       else if(root->left && root->right==NULL){
            node* temp = root->left;
            delete root;
            return temp;
       }
       else if(root->right && root->left==NULL){
            node* temp = root->right;
            delete root;
            return temp;
       }
       else{
            if(root->left){
                int maxi = maxInBST(root->left);
                root->data = maxi;
                root->left = deleteFromBST(root->left,maxi);
                return root;
            }
            else{
                int mini = minInBST(root->right);
                root->data = mini;
                root->right = deleteFromBST(root->right,mini);
                return root;
            }
       }
    }
    else if(root->data<x){
        root->right = deleteFromBST(root->right,x);
    }
    else{
        root->left = deleteFromBST(root->left,x);
    }
    return root;
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
    cout<<"Enter Data To Delete"<<endl;
    cin>>dat;
    root = deleteFromBST(root,dat);
    levelOrderTraversal(root);
    cout<<endl;
    
    return 0;
}