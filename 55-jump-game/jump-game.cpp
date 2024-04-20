class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() > 1 && nums[0] == 0) return false;

        int n = nums.size();
        for (int i=1;i<n-1;i++) {
            nums[i] = max(nums[i], nums[i-1]-1);
            if (nums[i] == 0) return false;
        }

        return true;
    }
};