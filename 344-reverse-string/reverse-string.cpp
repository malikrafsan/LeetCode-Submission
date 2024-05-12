class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int it = n / 2;

        for (int i=0;i<it;i++) {
            char tmp = s[i];
            s[i] = s[n-i-1];
            s[n-i-1] = tmp;
        }
    }
};