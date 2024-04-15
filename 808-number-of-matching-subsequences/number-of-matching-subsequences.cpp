class Solution {
private:
    map<string, int> mp;
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int sum = 0;
        for (auto word: words) {
            if (mp.count(word) > 0) {
                sum += mp[word];
                continue;
            }

            int idxS = 0;
            int idxW = 0;
            while (1) {
                if (idxS >= s.length() || idxW >= word.length()) {
                    break;
                }

                if (s[idxS] == word[idxW]) {
                    idxW++;
                }
                idxS++;
            }
            int added = idxW == word.length() ? 1 : 0;
            sum += added;
            mp[word] = added;
        }

        return sum;
    }
};