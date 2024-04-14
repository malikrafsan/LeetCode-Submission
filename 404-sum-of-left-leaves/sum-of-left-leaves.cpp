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
    int sumLeft(TreeNode* root, bool isLeft) {
        if (root == nullptr) return 0;

        bool isLeaf = root->left == nullptr && root->right == nullptr;
        if (isLeaf && isLeft) {
            return root->val;
        }
        return isLeaf ? 0 : sumLeft(root->left, true) + sumLeft(root->right, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        bool isLeaf = root->left == nullptr && root->right == nullptr;
        return isLeaf ? 0 : this->sumLeft(root->right, false) + this->sumLeft(root->left, true);
    }
};