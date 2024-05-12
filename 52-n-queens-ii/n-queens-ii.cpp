class Solution {
private:
    int result;
    int n;
    set<int> col;
    set<int> posDiag;
    set<int> negDiag;

public:
    bool contain(int a, set<int>& s) {
        return s.find(a) != s.end();
    }

    void backtrack(int r) {
        if (r == this->n) {
            this->result += 1;
            return;
        }

        for (int c=0;c<this->n;c++) {
            if (
                contain(c, this->col) ||
                contain(r+c, this->posDiag) ||
                contain(r-c, this->negDiag)
            ) {
                continue;
            }

            this->col.insert(c);
            this->posDiag.insert(r+c);
            this->negDiag.insert(r-c);
            backtrack(r+1);
            this->col.erase(c);
            this->posDiag.erase(r+c);
            this->negDiag.erase(r-c);            
        }
    }

    int totalNQueens(int n) {
        this->result = 0;
        this->n = n;
        backtrack(0);
        return this->result;
    }
};