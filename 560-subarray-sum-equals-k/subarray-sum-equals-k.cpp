class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int curSum = 0;
        map<int, int> mp;
        mp[0] = 1;

        for (auto num: nums) {
            curSum += num;
            int diff = curSum - k;

            if (mp.find(diff) != mp.end()) {
                res += mp[diff];
            }
            if (mp.find(curSum) != mp.end()) {
                mp[curSum]++;
            } else {
                mp[curSum] = 1;
            }
        }

        return res;
    }
};