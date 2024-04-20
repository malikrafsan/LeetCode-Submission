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
    bool isValidBST(TreeNode* root, long minVal, long maxVal) {
        if (!root) return true;
        if (root->val <= minVal || root->val >= maxVal) return false;
        return isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal);

        // if (!root || (!root->left && !root->right)) return true;

        // if (root->left && root->left->val >= minVal) return false;
        // if (root->right && root->right->val <= maxVal) return false;

        // return (!root->left || isValidBST(root->left, root->left->val, maxVal)) && (!root->right || isValidBST(root->right, minVal, root->right->val));
    }

    bool isValidBST(TreeNode* root) {
        return this->isValidBST(root, LONG_MIN, LONG_MAX);
    }
};