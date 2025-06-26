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

node* buildFromLevelOrderTraversal(){
    node* root;
    cout<<"Enter the data for root node:";
    int dat;
    cin>>dat;
    root = new node(dat);
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* tmp = q.front();
        q.pop();

        cout<<"Enter the data for left of "<<tmp->data;
        int lft;
        cin>>lft;
        if(lft!=-1){
            tmp->left = new node(lft);
            q.push(tmp->left);
        }
        cout<<"Enter the data for right of "<<tmp->data;
        int rght;
        cin>>rght;
        if(rght!=-1){
            tmp->right = new node(rght);
            q.push(tmp->right);
        }
    }
    return root;
}

int main()
{
    node *root;
    // root = buildTree(root);
    root = buildFromLevelOrderTraversal();
    levelOrderTraversal(root);
    // 1 3 7 -1 -1 8 -1 -1 4 9 -1 -1 -1
    return 0;
}