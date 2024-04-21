class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        int n = height.size();

        int curIdx1 = 0;
        int curIdx2 = 1;
        while (1) {
            if (curIdx2 >= n) break;

            if (height[curIdx1] > height[curIdx2]) {
                sum += (height[curIdx1] - height[curIdx2]);
                curIdx2++;
            } else {
                curIdx1 = curIdx2;
                curIdx2++;
            }

            cout << "idx" << curIdx1 << " sum " << sum << "\n";
        }

        height.push_back(0);

        int curIdx11 = n;
        int curIdx22 = n-1;
        while (1) {
            if (curIdx22 == curIdx1) break;

            if (height[curIdx22] >= height[curIdx11]) {
                curIdx11 = curIdx22;
            }

            sum -= (height[curIdx1] - height[curIdx11]);
            curIdx22--;
        }

        return sum;
    }
};