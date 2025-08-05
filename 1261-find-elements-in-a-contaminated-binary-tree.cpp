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
class FindElements {
public:
    unordered_set<int> ust;

    void func(TreeNode* root, int x){
        if(!root)
            return;

        root->val = x;
        ust.insert(x);
        
        func(root->left, 2*x + 1);
        func(root->right, 2*x + 2);
    }

    FindElements(TreeNode* root) {
        func(root, 0);
    }

    bool find(int target) {
        return ust.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */