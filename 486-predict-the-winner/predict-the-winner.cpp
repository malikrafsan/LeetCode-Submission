class Solution {
public:
    pair<int, int> best(vector<int>& nums, bool isPlayer1Turn, int lBound, int rBound) {
        if (lBound >= rBound) return isPlayer1Turn ? make_pair(nums[rBound], 0) : make_pair(0, nums[rBound]);
        if (rBound - lBound == 1) {
            bool greaterLeft = nums[lBound] > nums[rBound];
            int maxPick = greaterLeft ? nums[lBound] : nums[rBound];
            int minPick = greaterLeft ? nums[rBound] : nums[lBound];
            return isPlayer1Turn ? make_pair(maxPick, minPick) : make_pair(minPick, maxPick);
            // int picked = nums[rBound] > nums[lBound] ? nums[rBound] : nums[lBound];
            // int picked = std::max(nums[rBound], )
        }
        auto scoresWhenPickLeft = this->best(nums, !isPlayer1Turn, lBound+1, rBound);
        auto scoresWhenPickRight = this->best(nums, !isPlayer1Turn, lBound, rBound-1);
        int idx = isPlayer1Turn ? 0 : 1;
        if (isPlayer1Turn) {
            scoresWhenPickLeft.first += nums[lBound];
            scoresWhenPickRight.first += nums[rBound];

            return scoresWhenPickLeft.first > scoresWhenPickRight.first ? scoresWhenPickLeft : scoresWhenPickRight;
        } else {
            scoresWhenPickLeft.second += nums[lBound];
            scoresWhenPickRight.second += nums[rBound];

            return scoresWhenPickLeft.second > scoresWhenPickRight.second ? scoresWhenPickLeft : scoresWhenPickRight;
        }
    }

    bool predictTheWinner(vector<int>& nums) {
        auto scores = this->best(nums, true, 0, nums.size()-1);
        return scores.first >= scores.second;   
    }
};