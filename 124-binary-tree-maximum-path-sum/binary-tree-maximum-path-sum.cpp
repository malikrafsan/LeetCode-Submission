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
    long solve(TreeNode* root, long& res) {
        if (!root) return INT_MIN;

        long left = solve(root->left, res);
        long right = solve(root->right, res);
        long curVal = root->val;
        long maxLeftRight = max(left, right);

        res = max({res, curVal, curVal+left+right, maxLeftRight+curVal});

        return max(curVal, curVal + maxLeftRight);
    }

    int maxPathSum(TreeNode* root) {
        long res = INT_MIN;
        solve(root, res);
        return res;
    }
};