class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int curNode) {
        int n = isConnected.size();
        visited[curNode] = true;

        for (int i=0;i<n;i++) {
            if (!visited[i] && isConnected[curNode][i]) {
                dfs(isConnected, visited, i);
            }
        }

        
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int sum = 0;

        vector<bool> visited = vector<bool>(n,false);
        for (int i=0;i<n;i++) {
            if (!visited[i]) {
                dfs(isConnected, visited, i);
                sum+=1;
            }
        }

        return sum;
    }
};