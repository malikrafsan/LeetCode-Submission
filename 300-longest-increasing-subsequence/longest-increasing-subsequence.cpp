class Solution {
private:
    vector<vector<int>> mat;

public:
    int dp(vector<int>& nums, int i, int idxMax) {
        if (i >= nums.size()) return 0;

        if (idxMax == -1) {
            int res = max(
                1 + dp(nums, i+1, i),
                dp(nums, i+1, -1)
            );
            return res;
        }

        if (mat[i][idxMax] != -1) return mat[i][idxMax];

        if (nums[i] <= nums[idxMax]) {
            int res = dp(nums, i+1, idxMax);
            mat[i][idxMax] = res;
            return res;
        }

        int res = max(
            dp(nums, i+1, idxMax),
            1 + dp(nums, i+1, i)
        );
        mat[i][idxMax] = res;
        return res;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        mat = vector<vector<int>>(n, vector<int>(n, -1));

        return dp(nums, 0, -1);
    }
};