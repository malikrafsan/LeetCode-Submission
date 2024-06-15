class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> mp = {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"},
        };

        vector<string> res;

        for (auto& digit: digits) {
            if (res.size() == 0) {
                for (auto& ch: mp[digit]) {
                    res.push_back(string(1,ch));
                }
                continue;
            }

            auto arr = mp[digit];
            vector<string> newres;
            for (auto& x:res) {
                for (auto& y:arr) {
                    newres.push_back(x+y);
                }
            }

            res = newres;
        }

        return res;
    }
};