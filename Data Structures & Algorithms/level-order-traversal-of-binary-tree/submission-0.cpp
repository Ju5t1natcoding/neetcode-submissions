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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }

        vector<vector<int>> ans;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        ans.push_back({root->val});

        while (!q.empty()) {
            auto [rad, adc] = q.front();
            q.pop();

            if (rad->left) {
                if (static_cast<int>(ans.size()) == adc + 1) {
                    ans.emplace_back();
                }

                ans[adc + 1].push_back(rad->left->val);
                q.push({rad->left, adc + 1});
            }

            if (rad->right) {
                if (static_cast<int>(ans.size()) == adc + 1) {
                    ans.emplace_back();
                }

                ans[adc + 1].push_back(rad->right->val);
                q.push({rad->right, adc + 1});
            }
        }

        return ans;
    }
};
