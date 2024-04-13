class Solution {
public:
    int myAtoi(string s) {
        int idx= 0;
        int multiplier = 1;
        long long ans = 0;

        while (idx < s.length() && s[idx] == ' ') idx++;
        if (s[idx] == '-') {
            multiplier = -1;
            idx++;
        } else if (s[idx] == '+') idx++;

        while (idx<s.length()) {
            if (s[idx] < '0' || s[idx] > '9') {
                return ans;
            } 

            int added = multiplier * (s[idx] - '0');
            ans = ans == 0 ? added : ans * 10 + added;
            if (ans > INT_MAX) return INT_MAX;
            else if (ans < INT_MIN) return INT_MIN;

            idx++;
        }
        return ans;
    }
};