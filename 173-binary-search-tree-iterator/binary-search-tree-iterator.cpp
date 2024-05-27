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
class BSTIterator {
private:
    stack<TreeNode*> st;

    void cache(TreeNode* node) {
        while (1) {
            if (node == nullptr) return;

            this->st.push(node);
            node = node->left;
        }
    } 

public:
    BSTIterator(TreeNode* root) {
        this->cache(root);
    }
    
    int next() {
        auto top = this->st.top();
        this->st.pop();
        this->cache(top->right);

        return top->val;
    }
    
    bool hasNext() {
        return !this->st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */