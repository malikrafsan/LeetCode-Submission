class Solution {
public:


    int minDistance(string word1, string word2) {
        int ln1 = word1.length();
        int ln2 = word2.length();

        vector<vector<int>> mat = vector<vector<int>>(ln1+1, vector<int>(ln2+1));

        for (int i=1;i<=ln1;i++) {
            mat[i][0] = i;
        }
        for (int j=1;j<=ln2;j++) {
            mat[0][j] = j;
        }

        for (int i=1;i<=ln1;i++) {
            for (int j=1;j<=ln2;j++) {
                if (word1[i-1] == word2[j-1]) {
                    mat[i][j] = mat[i-1][j-1];
                    continue;
                }

                mat[i][j] = min({mat[i-1][j-1], mat[i-1][j], mat[i][j-1]})+1;
            }
        }

        return mat[ln1][ln2];
    }
};