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
private:
    int answer;

public:
    int solve(TreeNode* root) {
        if (!root) return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        this->answer = max(this->answer, left+right+1);
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        answer = 0;
        solve(root);
        return answer-1;
    }
};