/*
    https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1
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

int findHeight(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = findHeight(root->left);
    int right = findHeight(root->right);
    int ans = max(left, right) + 1;
    return ans;
}
int findDiameter(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int op1 = findDiameter(root->left);
    int op2 = findDiameter(root->right);
    int op3 = findHeight(root->left) + findHeight(root->right) + 1;

    int ans = max(op1, max(op2, op3));
    return ans;
}
pair<int, int> fastDiameter(node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = fastDiameter(root->left);
    pair<int, int> right = fastDiameter(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}
int main()
{
    node *root;
    root = buildTree(root);
    // 1 3 7 -1 -1 8 -1 -1 4 9 -1 -1 -1
    levelOrderTraversal(root);
    return 0;
}