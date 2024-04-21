class Solution {
public:
    void dfs(int n, int k, int cur, vector<int>& out) {
        if (cur > n) return;
        if (out.size() >= k) return;

        out.push_back(cur);
        cur *= 10;
        dfs(n, k, cur, out);
        for (int i=1;i<=9;i++) {
            if (cur+i > n) break;

            // out.push_back(cur+i);
            dfs(n, k, cur+i, out);
        }
    }

    // int findKthNumber(int n, int k) {
    //     vector<int> res;
    //     // dfs(n, 0, res);
    //     for (int i=1;i<=9;i++) {
    //         dfs(n, k, i, res);
    //     }
    //     return res[k-1];
    // }

    long long calcGap(long long n, long long a, long long b) {
        long long gap = 0;
        while (a <= n) {
            gap += min(n+1, b) - a;
            a *= 10;
            b *= 10;
        }
        return gap;
    } 

    int findKthNumber(int n, int k) {
        long long curNum = 1;

        int i=1;
        while (1) {
            if (i >= k) break;

            long long gap = this->calcGap(n, curNum, curNum+1);
            if (i + gap <= k) {
                i += gap;
                ++curNum;
            } else {
                i++;
                curNum *= 10;
            }
        }

        return curNum;
    }

};
