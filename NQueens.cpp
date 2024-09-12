//problem: N queens

#include <iostream>
#include <vector>

using namespace std;

//is safe function checks for bad conditions like queens hitting each other diagonally, or sideways, or vertically.
bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    for (int i = 0; i < col; i++) 
        if (board[row][i]) return false; //one line reduces bracket needs

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j]) return false;

    for (int i = row, j = col; i < N && j >= 0; i++, j--) 
        if (board[i][j]) return false;

    return true;
}

bool solveNQueensUtil(vector<vector<int>>& board, int col, int N) {
    if (col >= N) 
        return true; //base case

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;
            if (solveNQueensUtil(board, col + 1, N)) //recurse, increment column
                return true;
            board[i][col] = 0;  //backtrack to ensure accurate placemeent.
        }
    }
    return false;
}

void solveNQueens(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0)); //initialize board

    if (solveNQueensUtil(board, 0, N)) {
        for (const auto& row : board) {
            for (int cell : row) {
                cout << (cell ? "Q" : ".") << " "; //place queen otherwise resemble cell with a dot symbol
            }
            cout << endl;
        }
    } 
    else 
        cout << "No solution exists." << endl;
}

//test case, set N to 8
int main() {
    int N = 8;
    solveNQueens(N);
    return 0;
}