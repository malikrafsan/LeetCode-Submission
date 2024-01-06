class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int len = score.size();
        
        vector<pair<int, int>> vec;
        vector<string> answer(len);

        for (int i=0;i<len;i++) {
            vec.push_back({score[i], i});
        }
        sort(vec.rbegin(), vec.rend());

        for (int i=0;i<len;i++) {
            switch (i) {
                case 0:
                    answer[vec[i].second] = "Gold Medal";
                    break;
                case 1:
                    answer[vec[i].second] = "Silver Medal";
                    break;
                case 2:
                    answer[vec[i].second] = "Bronze Medal";
                    break;
                default:
                    answer[vec[i].second] = to_string(i+1);
                    break;
            }
        }

        return answer;
    }
};