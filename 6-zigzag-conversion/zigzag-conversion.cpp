class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        string res = "";

        for (int i=0;i<numRows;i++) {
            int hop1 = 2 * (numRows - i - 1);
            int hop2 = 2 * i;

            if (hop1 == 0) hop1 = hop2;
            if (hop2 == 0) hop2 = hop1;

            int idx = i;
            bool isHop1 = true;
            while (1) {
                if (idx >= s.length()) {
                    break;
                }
                res += s[idx];

                int hop = isHop1 ? hop1 : hop2;
                isHop1 = !isHop1;
                idx += hop;
            }
        }

        return res;
    }
};