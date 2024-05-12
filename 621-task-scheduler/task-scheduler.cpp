class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> mp;
        for (auto task: tasks) {
            if (mp.find(task) != mp.end()) {
                mp[task]++;
            } else {
                mp[task] = 1;
            }
        }

        vector<int> arr;
        for (auto& keyval: mp) {
            cout << keyval.second << endl;
            arr.push_back(keyval.second);
        }

        priority_queue<int> pq(begin(arr),end(arr));
        queue<pair<int, int>> q;
        int time = 0;
        while (1) {
            if (pq.size() == 0 && q.size() == 0) {
                break;
            }

            time++;
            if (pq.size() != 0) {
                cout << pq.top() << endl;
                int cnt = pq.top() - 1;
                pq.pop();
                if (cnt != 0) {
                    q.push({cnt, time+n});
                }
            }

            if (q.size() != 0 && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};