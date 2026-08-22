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
    int preorderCount = 0;
    unordered_map<int, int> mp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return traverse(preorder, 0, inorder.size()-1);
    }

    TreeNode* traverse(vector<int>& preorder, int left, int right) {
        if(left > right) {
            return nullptr;
        }

        int val = preorder[preorderCount++];
        TreeNode* root = new TreeNode(val);

        int mid = mp[val];

        root->left = traverse(preorder, left, mid-1);
        root->right = traverse(preorder, mid+1, right);

        return root;
    }
};
