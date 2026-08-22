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
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        traverse(pq, root);

        for(int i = 1; i < k; i++) {
            pq.pop();
        }

        return pq.top();
     }

    void traverse(priority_queue<int, vector<int>, greater<int>>& pq, TreeNode* root) {
        if(!root) {
            return;
        }

        pq.push(root->val);
        traverse(pq, root->left);
        traverse(pq, root->right);
    }
};
