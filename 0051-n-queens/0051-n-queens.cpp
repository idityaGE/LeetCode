class Solution {
public:
    void solve_hash(vector<vector<string>>& ans, vector<string>& board,
                    vector<int> leftRow, vector<int> lowerDia,
                    vector<int> upperDia, int col = 0) {
        if (col == board.size()) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < board.size(); row++) {
            if (leftRow[row] == 0 && lowerDia[col + row] == 0 &&
                upperDia[board.size() - 1 + col - row] == 0) {
                leftRow[row] = 1;
                lowerDia[col + row] = 1;
                upperDia[board.size() - 1 + col - row] = 1;
                board[row][col] = 'Q';
                solve_hash(ans, board, leftRow, lowerDia, upperDia, col + 1);
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDia[col + row] = 0;
                upperDia[board.size() - 1 + col - row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
            board[i] = s;
        vector<int> leftRow(n, 0);
        vector<int> lowerDia((2 * n - 1), 0);
        vector<int> upperDia((2 * n - 1), 0);
        solve_hash(ans, board, leftRow, lowerDia, upperDia);
        return ans;
    }
};