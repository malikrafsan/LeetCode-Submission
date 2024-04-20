class Solution {
public:
    void backtrack(int n, int open, int close, string curStr, vector<string>& out) {
        if (open == n && close == n) {
            out.push_back(curStr);
            return;
        }
        if (open > n || close > open) return;

        backtrack(n, open+1, close, curStr+"(", out);
        backtrack(n, open, close+1, curStr+")", out);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(n, 0, 0, "", res);
        return res;
    }
};