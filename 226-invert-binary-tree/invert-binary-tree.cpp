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
    void swap(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return;

        auto tmp = root->right;
        root->right=root->left;
        root->left=tmp;
        swap(root->left);
        swap(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        // if (!root || (!root->left && !root->right)) return root;
        this->swap(root);
        return root;         
    }
};