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
    bool isValidBST(TreeNode* root) {
        int mn = INT_MIN;
        int mx = INT_MAX;
        return traverse(root, mn, mx);
    }

    bool traverse(TreeNode* root, int mn, int mx) {
        if(!root) return true;

        if(!(root->val > mn && root->val < mx)) {
            return false;
        }

        return traverse(root->left, mn, root->val) && traverse(root->right, root->val, mx);
    }
};
