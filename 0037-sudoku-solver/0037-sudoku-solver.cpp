class Solution {
public:

    bool is_safe(vector<vector<char>>& board, int row, int col, int n, char val) {

        for (int i = 0; i < n; i++) {
            if (board[row][i] == val)
                return false;
        }

        for (int i = 0; i < n; i++) {
            if (board[i][col] == val)
                return false;
        }

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == val)
                    return false;
            }
        }
        return true;
    }

    bool sudoku(vector<vector<char>>& board, int n) {
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (board[row][col] == '.') {
                    for (char val = '1'; val <= '9'; val++) {
                        if (is_safe(board, row, col, n, val)) {
                            board[row][col] = val;
                            if (sudoku(board, n))
                                return true;
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        int n = 9;
        sudoku(board, n);
    }
};