/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool solve(TreeNode *root, int totalNodes, int idx)
    {
        if (!root)
            return true;

        if (idx > totalNodes)
            return false;

        return solve(root->left, totalNodes, 2 * idx) && solve(root->right, totalNodes, 2 * idx + 1);
    }

    bool isCompleteTree(TreeNode *root)
    {
        int totalNodes = countNodes(root);
        return solve(root, totalNodes, 1);
    }
};