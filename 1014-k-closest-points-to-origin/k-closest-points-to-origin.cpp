class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;

        for (int i=0;i<points.size();i++) {
            pq.push({
                points[i][0] * points[i][0] + points[i][1] * points[i][1],
                {points[i][0], points[i][1]}
            });
        }

        for (int i=0;i<points.size()-k;i++) {
            pq.pop();
        }

        vector<vector<int>> res; 
        for (int i=0;i<k;i++) {
            pair<int, pair<int, int>> p = pq.top();
            res.push_back(vector<int>{p.second.first, p.second.second});
            pq.pop();
        }
        return res;
    }
};