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
    int dfs(TreeNode* root, int num) {
        int val = root->val;
        if (root->left == nullptr && root->right == nullptr) return num * 10 + val;

        int sum = 0;
        if (root->left != nullptr) sum += this->dfs(root->left, num*10+val);
        if (root->right != nullptr) sum += this->dfs(root->right, num*10+val);

        return sum;
    }

    int sumNumbers(TreeNode* root) {
        return this->dfs(root, 0);
    }
};