class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int mod = 1e9+7;
        sort(nums.begin(), nums.end());

        int n=nums.size();
        vector<int> power(n+1, 1);
        for (int i=1;i<=n;i++) power[i] = (power[i-1]*2) % mod;

        int l=0;
        int r=n-1;

        int sum = 0;
        while (l<=r) {
            if (nums[l]+nums[r] <= target) {
                int diff = r-l;
                sum = (sum + (power[diff] % mod)) % mod;
                l++;
            } else {
                r--;
            }
        }

        return sum;
    }
};