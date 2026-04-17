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
    bool isValidBST(TreeNode* root, int mn = INT_MIN, int mx = INT_MAX) {
        if (!root) {
            return true;
        }

        if (mx <= root->val || root->val <= mn) {
            return false;
        }

        return isValidBST(root->left, mn, root->val) && isValidBST(root->right, root->val, mx);
    }
};
