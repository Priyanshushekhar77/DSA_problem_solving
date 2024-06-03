// link->https://leetcode.com/problems/n-queens/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<vector<string>> result;
    bool isValid(vector<string> &board, int row, int col)
    {
        // Check if there is a queen in the same column
        for (int i = row; i >= 0; i--)
        {
            if (board[i][col] == 'Q')
                return false;
        }

        // Check upper left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }

        // Check upper right diagonal
        for (int i = row, j = col; i >= 0 && j < board.size(); i--, j++)
        {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void solve(vector<string> &board, int row)
    {
        if (row == board.size())
        {
            result.push_back(board);
            return;
        }

        for (int i = 0; i < board.size(); i++)
        {
            if (isValid(board, row, i))
            {
                board[row][i] = 'Q';   // Place queen
                solve(board, row + 1); // Recur for next row
                board[row][i] = '.';   // Backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        if (n <= 0)
            return {};
        vector<string> board(n, string(n, '.')); // Create empty board
        solve(board, 0);                         // Start with row 0
        return result;
    }
};

// Function to print the board
void printBoard(vector<vector<string>> &board)
{
    for (auto &row : board)
    {
        for (auto &cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int main()
{
    Solution sol;
    int n = 4;
    vector<vector<string>> result = sol.solveNQueens(n);
    for (auto &board : result)
    {
        printBoard(board);
        cout << endl;
    }
    return 0;
}

// The time complexity of the N-Queens problem using the DFS approach is O(N!), where N is the number of queens (and the size of the board). This complexity arises from the fact that for each row, we have N choices for placing the queen, and we recurse for the remaining rows, reducing the number of choices each time.

// Space Complexity:
// The space complexity of the algorithm is O(N^2), where N is the number of queens (and the size of the board). This space is used to store the chessboard configuration and the result.