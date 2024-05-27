class Solution {
public:
    vector<string> splitStr(string str, char del) {
        vector<string> res;
        string tmp = "";

        for (char c: str) {
            if (c == del) {
                res.push_back(tmp);
                tmp = "";
            } else {
                tmp += c;
            }
        }
        res.push_back(tmp);

        return res;
    }

    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<int> st;
        int prevTime = 0;

        for (auto& log: logs) {
            vector<string> splitted = this->splitStr(log, ':');

            int fn = stoi(splitted[0]);
            string typ = splitted[1];
            int stamp = stoi(splitted[2]);

            if (typ == "start") {
                if (!st.empty()) {
                    res[st.top()] += stamp - prevTime;
                }

                st.push(fn);
                prevTime = stamp;
            } else {
                int top = st.top();
                st.pop();

                res[top] += stamp - prevTime + 1;
                prevTime = stamp + 1;
            }
        }

        return res;
    }
};