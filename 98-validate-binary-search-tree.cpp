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
class Solution {
public:
    bool solve(TreeNode* root, long long mn, long long mx){
        if(!root)
            return true;
        
        int left_check = solve(root->left, mn, root->val - 1.0);
        int right_check = solve(root->right, root->val + 1.0 , mx);

        if(root->val < mn || root->val > mx)
            return false;
        return left_check && right_check;
    }

    bool isValidBST(TreeNode* root) {
       return solve(root, INT_MIN, INT_MAX); 
    }
};