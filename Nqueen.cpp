#include <vector>

class Solution {
public:
    bool isSafe(int row, int col, const vector<vector<int>>& board, int n) {
        // Check for same row
        for (int i = 0; i < col; i++) {
            if (board[row][i] == 1) {
                return false;
            }
        }

        // Check for upper diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1) {
                return false;
            }
        }

        // Check for lower diagonal
        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 1) {
                return false;
            }
        }

        return true;
    }

    vector<vector<string>> addSolution(const vector<vector<int>>& board, int n) {
        vector<string> solution;
        for (int i = 0; i < n; i++) {
            string row;
            for (int j = 0; j < n; j++) {
                row += (board[i][j] == 1) ? "Q" : ".";
            }
            solution.push_back(row);
        }
        return {solution}; // Return a single solution vector
    }

    void solve(int row, vector<vector<string>>& ans, vector<vector<int>>& board, int n) {
        if (row == n) {
            ans.push_back(addSolution(board, n)[0]); // Add a single solution
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 1;
                solve(row + 1, ans, board, n);
                board[row][col] = 0; // Backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<int>> board(n, vector<int>(n, 0));
        solve(0, ans, board, n);
        return ans;
    }
};