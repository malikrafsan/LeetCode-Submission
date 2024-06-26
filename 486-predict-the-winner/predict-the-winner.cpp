class Solution {
private:
    // map<string, pair<int, int>> mp;
    vector<vector<pair<int, int>>> dp1;
    vector<vector<pair<int, int>>> dp2;

public:
    // string stringify(bool isPlayer1Turn, int lBound, int rBound) {
    //     string key = "";
    //     key += to_string(isPlayer1Turn);
    //     key += to_string(lBound);
    //     key += to_string(rBound);

    //     return key;
    // }

    pair<int,int> getDP(bool isPlayer1Turn, int lBound, int rBound) {
        return (isPlayer1Turn ? dp1 : dp2)[lBound][rBound];
    }

    void setDP(bool isPlayer1Turn, int lBound, int rBound, pair<int,int> elmt) {
        (isPlayer1Turn ? dp1 : dp2)[lBound][rBound] = elmt;
    }

    pair<int, int> best(vector<int>& nums, bool isPlayer1Turn, int lBound, int rBound) {
        // auto key = stringify(isPlayer1Turn, lBound, rBound);
        // if (mp.count(key) != 0) return mp[key]; 
        auto dpElmt = (isPlayer1Turn ? dp1 : dp2)[lBound][rBound];
        if (dpElmt != make_pair(-1,-1)) return dpElmt;

        if (lBound >= rBound) {
            auto res = isPlayer1Turn ? make_pair(nums[rBound], 0) : make_pair(0, nums[rBound]);
            // mp[key] = res;
            setDP(isPlayer1Turn, lBound, rBound, res);
            return res;
        }
        if (rBound - lBound == 1) {
            bool greaterLeft = nums[lBound] > nums[rBound];
            int maxPick = greaterLeft ? nums[lBound] : nums[rBound];
            int minPick = greaterLeft ? nums[rBound] : nums[lBound];
            auto res = isPlayer1Turn ? make_pair(maxPick, minPick) : make_pair(minPick, maxPick);
            // mp[key] = res;
            setDP(isPlayer1Turn, lBound, rBound, res);
            return res;
        }
        auto scoresWhenPickLeft = this->best(nums, !isPlayer1Turn, lBound+1, rBound);
        auto scoresWhenPickRight = this->best(nums, !isPlayer1Turn, lBound, rBound-1);
        int idx = isPlayer1Turn ? 0 : 1;
        if (isPlayer1Turn) {
            scoresWhenPickLeft.first += nums[lBound];
            scoresWhenPickRight.first += nums[rBound];

            auto res = scoresWhenPickLeft.first > scoresWhenPickRight.first ? scoresWhenPickLeft : scoresWhenPickRight;
            // mp[key] = res;
            setDP(isPlayer1Turn, lBound, rBound, res);
            return res;
        } else {
            scoresWhenPickLeft.second += nums[lBound];
            scoresWhenPickRight.second += nums[rBound];

            auto res = scoresWhenPickLeft.second > scoresWhenPickRight.second ? scoresWhenPickLeft : scoresWhenPickRight;
            // mp[key] = res;
            setDP(isPlayer1Turn, lBound, rBound, res);
            return res;
        }
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        this->dp1 = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(n, make_pair(-1, -1)));
        this->dp2 = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(n, make_pair(-1, -1)));

        auto scores = this->best(nums, true, 0, nums.size()-1);
        return scores.first >= scores.second;   
    }
};