class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int length = nums.size();
        
        for (int i=1;i<length;i++) {
            nums[0] = nums[0] ^ nums[i]; 
        }
        return nums[0];
    }
};