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
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int count = 0;
        int mx = root->val;
        traverse(root, mx, count);
        return count;
    }

    void traverse(TreeNode* root, int mx, int& count) {
        if(!root) {
            return;
        }

        if(root->val >= mx) {
            mx = max(mx, root->val);
            count++;
        }

        traverse(root->left, mx, count);
        traverse(root->right, mx, count);     
    }
};
