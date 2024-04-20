/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* root, TreeNode* searched, vector<TreeNode*>& out) {
        if (root == nullptr) return false;
        if (root == searched) {
            out.push_back(root);
            return true;
        }

        if (dfs(root->left, searched, out)) {
            out.push_back(root);
            return true;
        }
        if (dfs(root->right, searched, out)) {
            out.push_back(root);
            return true;
        }
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> lst1;
        vector<TreeNode*> lst2;

        dfs(root, p, lst1);
        dfs(root, q, lst2);

        // auto walker = p;
        // while (1) {
        //     lst1.push_back(walker);
        //     if (walker == root) break;

        //     walker=walker->next;
        // }
        // auto walker = q;
        // while (1) {
        //     lst2.push_back(walker);
        //     if (walker == root) break;
        //     walker=walker->next;
        // }

        int idx1 = lst1.size()-1;
        int idx2 = lst2.size()-1;
        TreeNode* res = root;
        while (1) {
            if (idx1 < 0 || idx2 < 0) break;
            if (lst1[idx1] != lst2[idx2]) break;

            res = lst1[idx1];
            idx1--;
            idx2--;
        }

        return res;
    }
};