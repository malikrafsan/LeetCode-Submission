class Solution {
public:
    int reverse(int x) {
        int res = 0;
        bool isNeg = x < 0;
        while (x) {
            int mod = x%10;
            if (!isNeg && res > ((INT_MAX-mod)/10)) return 0;
            if (isNeg && res < (INT_MIN-mod)/10) return 0;

            res = res*10 + mod;
            x /= 10;
        }
        return res;
    }
};