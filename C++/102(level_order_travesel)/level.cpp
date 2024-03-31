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
    TreeNode *buildTree(TreeNode *root)
    {
        cout << "Enter data: ";
        int data;
        cin >> data;

        root = new TreeNode(data);

        if (data == -1)
            return NULL;

        cout << "Enter data for inserting in the left of " << data << endl;
        root->left = buildTree(root->left);

        cout << "Enter data for inserting in right of " << data << endl;
        root->right = buildTree(root->right);

        return root;
    };

    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> vv;

        if (root == NULL)
            return vv;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            // create the size and vector
            int size = q.size();
            vector<int> tmp;
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = q.front();
                q.pop();

                tmp.push_back(temp->data);

                if (temp->left)
                    q.push(temp->left);

                if (temp->right)
                    q.push(temp->right);
            }
            vv.push_back(tmp);
        }
    }
};

int main()
{
    Solution ins = Solution();

    TreeNode *root = NULL;
    // creating a tree  // 3 9 -1 -1 20 15 -1 -1 7 -1 -1
    root = ins.buildTree(root);

    vector<vector<int>> out;
    out = ins.levelOrder(root);

    cout << "The Vector is" << endl;

    for (auto val : out)
    {
        for (int val1 : val)
            cout << val1 << " ";
        cout << endl;
    }

    return -1;
}