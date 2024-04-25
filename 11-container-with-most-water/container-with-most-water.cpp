class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (1) {
            if (left >= right) break;

            int cur = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, cur);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};