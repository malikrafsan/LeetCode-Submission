class Solution {
public:
    void dfs(int n, int cur, vector<int>& out) {
        if (cur > n) return;

        out.push_back(cur);
        cur *= 10;
        dfs(n, cur, out);
        for (int i=1;i<=9;i++) {
            if (cur+i > n) break;

            // out.push_back(cur+i);
            dfs(n, cur+i, out);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> res;
        // dfs(n, 0, res);
        for (int i=1;i<=9;i++) {
            dfs(n, i, res);
        }
        return res;
    }
};