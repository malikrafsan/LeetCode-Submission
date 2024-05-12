class Solution {
public:
    string defangIPaddr(string address) {
        string res = "";
        for (auto a: address) {
            if (a == '.') {
                res += "[.]";
            } else {
                res += a;
            }
        }
        return res;
    }
};