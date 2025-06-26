/*

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

void leftTraverse(node *root, vector<int> &ans)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    ans.push_back(root->data);
    if (root->left)
    {
        leftTraverse(root->left, ans);
    }
    else
    {
        leftTraverse(root->right, ans);
    }
    return;
}
void leafTraverse(node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    if (root->left)
    {
        leafTraverse(root->left, ans);
    }
    if (root->right)
    {
        leafTraverse(root->right, ans);
    }
    return;
}
void rightTraverse(node *root, vector<int> &ans)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    if (root->right)
    {
        rightTraverse(root->right, ans);
    }
    else
    {
        rightTraverse(root->left, ans);
    }
    ans.push_back(root->data);
    return;
}

vector<int> boundaryTraversal(node *root)
{
    // code here
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    ans.push_back(root->data);
    leftTraverse(root->left, ans);

    leafTraverse(root->left, ans);
    leafTraverse(root->right, ans);

    rightTraverse(root->right, ans);

    return ans;
}
