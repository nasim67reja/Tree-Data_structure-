#include <iostream>
#include <vector>
#include <queue>
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

class Solution
{
public:
    // Build the tree
    TreeNode *buildTree(TreeNode *root)
    {
        cout << "Enter data: ";
        int data;
        cin >> data;
        if (data == -1)
            return NULL;

        root = new TreeNode(data);

        cout << "Enter data for inserting in the left of " << data << endl;
        root->left = buildTree(root->left);

        cout << "Enter data for inserting in right of " << data << endl;
        root->right = buildTree(root->right);

        return root;
    };

    void levelOrderTraversal(TreeNode *root)

    {
        if (!root)
            return;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = q.front();
                q.pop();

                cout << temp->data << " ";

                if (temp->left)
                    q.push(temp->left);

                if (temp->right)
                    q.push(temp->right);
            }
            cout << endl;
        }
    }
    // Invert Tree
    TreeNode *invertTree(TreeNode *root)
    {
        if (root->left == NULL && root->right == NULL)
            return root;
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

int main()
{
    Solution ins = Solution();

    TreeNode *root = NULL;
    // creating a tree   3 9 -1 -1 20 15 -1 -1 7 -1 -1
    root = ins.buildTree(root);
    cout << "Before invert" << endl;
    ins.levelOrderTraversal(root);
    root = ins.invertTree(root);
    cout << "After invert" << endl;
    ins.levelOrderTraversal(root);

    return 0;
}