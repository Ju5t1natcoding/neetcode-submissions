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
    bool valid(TreeNode* root, TreeNode* mn, TreeNode* mx) {
        if (!root) {
            return true;
        }

        if (mn && root->val <= mn->val) {
            return false;
        }

        if (mx && root->val >= mx->val) {
            return false;
        }

        return valid(root->left, mn, root) && valid(root->right, root, mx);
    }

public:
    bool isValidBST(TreeNode* root) {
        return valid(root, nullptr, nullptr);
    }
};
