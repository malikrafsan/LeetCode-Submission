class Solution {
public:
    int reverse(int x) {
        int res = 0;
        bool isNeg = x < 0;
        while (x) {
            int mod = x%10;
            if (!isNeg && res > ((INT_MAX-mod)/10)) return 0;
            if (isNeg && res < (INT_MIN-mod)/10) return 0;
            // if (res > ((INT_MAX-mod)/10) || res < (INT_MIN+mod)/10) return 0;

            res = res*10 + mod;
            x /= 10;
        }
        return res;

        // int res = 0;
        // bool isNeg = x < 0;
        // x = isNeg ? -x : x;
        // while (1) {
        //     if (x == 0) break;

        //     int mod = x%10;
        //     if (res > (INT_MAX-mod)/10) return 0;

        //     res = res * 10 + mod;
        //     x /= 10;
        // }
        // if (isNeg) {
        //     return (-res < INT_MIN) ? 0 : -res;
        // }

        // return res;
    }
};