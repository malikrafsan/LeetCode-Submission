class Solution {
public:
    string expandFromCenter(string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);
    }

    string longestPalindrome(string s) {
        if (s.length() <= 1) {
            return s;
        }

        string res = s.substr(0, 1);

        for (int i=0; i<s.length() -1;i++) {
            string odd = this->expandFromCenter(s, i, i);
            string even = this->expandFromCenter(s, i, i+1);

            if (odd.length() > res.length()) {
                res = odd;
            }
            if (even.length() > res.length()) {
                res = even;
            }
        }

        return res;
    }
};
