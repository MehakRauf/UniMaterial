#include <iostream>
#include <vector>
using namespace std;

// ✅ Function to print the chessboard
void printBoard(vector<vector<int>>& board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (board[i][j] ? "Q " : ". ");  // Print 'Q' for queen, '.' for empty
        }
        cout << endl;
    }
    cout << endl;
}

// ✅ Check if placing a queen at board[row][col] is safe
bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // Check column above
    for (int i = 0; i < row; i++) {
        if (board[i][col]) return false;
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return false;
    }

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j]) return false;
    }

    return true; // Safe position found
}

// ✅ Recursive backtracking function
bool solveNQueens(vector<vector<int>>& board, int row, int n) {
    // Base case: all queens are placed
    if (row == n) {
        printBoard(board, n);
        return true; // You can return false here if you want all solutions
    }

    // Try placing queen in each column of current row
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;       // Place queen
            solveNQueens(board, row + 1, n); // Move to next row
            board[row][col] = 0;       // Backtrack (remove queen)
        }
    }

    return false;
}

int main() {
    int n = 4; // You can change this value to test for other N
    vector<vector<int>> board(n, vector<int>(n, 0)); // Create N×N chessboard

    cout << "Solutions for " << n << "-Queens problem:\n";
    solveNQueens(board, 0, n);

    return 0;
}
