class Solution {

public:
    // pair<int, bool> getDP(int key) {
    //     return dp[key] != INT_MAX ? make_pair(dp[key], true) : make_pair(INT_MAX, false);  //dp.count(key) > 0 ? make_pair(dp[key], true) : make_pair(-1, false); 
    // }
    // void setDP(int key, int val) {
    //     dp[key] = val;
    // }

    // int solve(vector<int>& coins, int amount) {
    //     auto cache = this->getDP(amount);
    //     if (cache.second) return cache.first;

    //     int res = INT_MAX;
    //     for (auto c:coins) {
    //         int idx = amount-c;
    //         res = min(res, this->solve(coins,idx));
    //     }
    //     setDP(amount, res);
    //     return res;
    // }

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());

        vector<int> dp;// = vector<int>(amount+1, INT_MAX);
        dp.assign(amount+1, INT_MAX);
        // for (auto c: coins) {
        //     dp[c] = 1;
        // }
        dp[0] = 0;

        for (int i=1;i<=amount;i++) {
            for (auto c:coins) {
                if (i-c < 0) break;

                if (dp[i-c] != INT_MAX) dp[i] = min(dp[i], dp[i-c]+1);

                // if (i-c >= 0) {
                //     dp[i] = min(dp[i-c]+1, dp[i]);
                // } else break;
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];

        // auto res = this->solve(coins, amount);
        // return res == INT_MAX ? -1 : res;
    }
};