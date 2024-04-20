class Solution {
private:
    vector<vector<pair<int,int>>> dp1;
    vector<vector<pair<int,int>>> dp2;
public:
    pair<int, int> solve(vector<int>& piles, int score1, int score2, int curPlayer, int l, int r) {
        if (curPlayer == 0 && dp1[l][r].first != -1 && dp1[l][r].second != -1) return dp1[l][r];
        if (curPlayer == 1 && dp2[l][r].first != -1 && dp2[l][r].second != -1) return dp2[l][r];

        if (l > r) return {score1, score2};
        if (l == r) {
            if (curPlayer == 0) {
                pair<int, int> res = {score1+piles[l], score2};
                dp1[l][r] = res;
                return res;
            } else {
                pair<int, int> res = {score1, score2+piles[l]};
                dp2[l][r] = res;
                return res;
            } 
        }

        if (curPlayer == 0) {
            auto takeLeft = this->solve(piles, score1+piles[l], score2, (curPlayer+1) % 2, l+1, r);
            auto takeRight = this->solve(piles, score1+piles[r], score2, (curPlayer+1) % 2, l, r-1); 
            auto res = (takeLeft.first >= takeRight.first) ? takeLeft : takeRight;
            dp1[l][r] = res;
            return res;
        } else {
            auto takeLeft = this->solve(piles, score1, score2+piles[l], (curPlayer+1) % 2, l+1, r);
            auto takeRight = this->solve(piles, score1, score2+piles[r], (curPlayer+1) % 2, l, r-1); 
            auto res = (takeLeft.first >= takeRight.first) ? takeLeft : takeRight;      
            dp2[l][r] = res;
            return res;
        }
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        this->dp1 = vector<vector<pair<int,int>>>();
        this->dp2 = vector<vector<pair<int,int>>>();
        for (int i=0;i<n;i++) {
            this->dp1.push_back(vector<pair<int,int>>(n, {-1,-1}));
            this->dp2.push_back(vector<pair<int,int>>(n, {-1,-1}));
        }

        auto res = this->solve(piles, 0, 0, 0, 0, piles.size()-1);
        return res.first >= res.second;
    }
};