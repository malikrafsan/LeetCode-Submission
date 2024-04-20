class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j) {
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int, int>> q;
        q.push({i,j});
        grid[i][j] = '0';

        vector<pair<int,int>> dirs = {
            {-1, 0}, {1, 0}, {0,-1}, {0,1}
        };

        while (1) {
            if (q.empty()) break;

            auto p = q.front();
            q.pop();
            i = p.first;
            j = p.second;

            for (auto dir: dirs) {
                int newI = i+dir.first;
                int newJ = j+dir.second;
                if (newI < 0 || newI >= row || newJ < 0 || newJ >= col) continue;

                if (grid[newI][newJ] == '1') {
                    grid[newI][newJ] = '0';
                    q.push({newI, newJ});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int sum = 0;
        int row = grid.size();
        int col = grid[0].size();

        for (int i=0;i<row;i++) {
            for (int j=0;j<col;j++) {
                if (grid[i][j] == '1') {
                    sum += 1;
                    this->bfs(grid, i, j);
                } 
            }
        }

        return sum;
    }
};