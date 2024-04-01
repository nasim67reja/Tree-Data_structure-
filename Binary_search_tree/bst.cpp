#include <iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode *BSTree(TreeNode *root)
{
    cout << "Enter data: ";
    int data;
    cin >> data;
    TreeNode *temp = root;
    root = new TreeNode(data);
    if (data == -1)
        return NULL;

    if (data < temp->data)
        root->left = BSTree(root->left);
    else
        root->right = BSTree(root->right);

    // if (data < temp->data)
}

int main()
{
    TreeNode *root = new TreeNode(10);

    cout << root->data << endl;
    // create BST
    // TreeNode(root);

    return 1;
}