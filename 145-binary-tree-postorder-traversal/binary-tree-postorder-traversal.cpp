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
    void dfs(vector<int>& out, TreeNode* root) {
        if (root == nullptr) return;

        dfs(out, root->left);
        dfs(out, root->right);
        out.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        if (root==nullptr) return {};

        vector<int> res;
        vector<TreeNode*> stack;
        stack.push_back(root);
        while (1) {
            if (stack.empty()) break;

            auto cur = stack.back();

            if (cur->left == nullptr && cur->right == nullptr) {
                res.push_back(cur->val);
                stack.pop_back();
            }

            if (cur->right) {
                stack.push_back(cur->right);
                cur->right = nullptr;
            }
            if (cur->left) {
                stack.push_back(cur->left);
                cur->left = nullptr;
            }



            // if (stack.empty() && root == nullptr) break;

            // auto cur = stack.back();
            // stack.pop_back();

            // if (cur == nullptr) continue;

            // stack.push_back(cur->left);
            // stack.push_back(cur->right);
        }

        return res;
    }
};