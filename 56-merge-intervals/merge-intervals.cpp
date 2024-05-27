class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // [[1,3],[2,6],[8,10],[15,18]]
        // sort by first element
        // store pair<lastBigElmt, idx>

        vector<vector<int>> res;
        int start = -1;
        int lastBigElmt = -1;

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        for (auto& elmt: intervals) {
            int first = elmt[0];
            int second = elmt[1];

            if (first > lastBigElmt) {
                res.push_back({first, second});
                start = first;
            } else {
                int ln = res.size();
                res[ln-1][1] = max(second, lastBigElmt);
            }  
            lastBigElmt = max(second, lastBigElmt);
        }

        return res;
    }
};