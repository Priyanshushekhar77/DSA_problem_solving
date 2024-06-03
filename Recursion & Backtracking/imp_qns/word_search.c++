// LINK->https://leetcode.com/problems/word-search/description/?envType=daily-question&envId=2024-04-03

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int m, n;

    bool solve(vector<vector<char>> &board, int i, int j, string &word, int ind)
    {
        // Base case: if all characters are matched
        if (ind == word.size())
            return true;

        // Check boundaries and if the current cell matches the word character
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$' || board[i][j] != word[ind])
            return false;

        // Do the task: mark the cell as visited
        char temp = board[i][j];
        board[i][j] = '$';

        // Explore the neighbors recursively in all 4 directions
        if (solve(board, i + 1, j, word, ind + 1) ||
            solve(board, i, j + 1, word, ind + 1) ||
            solve(board, i - 1, j, word, ind + 1) ||
            solve(board, i, j - 1, word, ind + 1))
            return true; // If any neighbor leads to finding the word, return true

        // Undo the previous task, backtrack: restore the original character in the current cell
        board[i][j] = temp;

        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        m = board.size();
        n = board[0].size();

        // Iterate through each cell of the board
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // If the current cell matches the first character of the word, start DFS from here
                if (board[i][j] == word[0])
                {
                    if (solve(board, i, j, word, 0))
                        return true;
                }
            }
        }

        // If no cell leads to finding the word, return false
        return false;
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";

    bool result = solution.exist(board, word);
    cout << (result ? "true" : "false") << endl;

    return 0;
}
// Time Complexity: O(3^L * MN), where L is the length of the word, M is the number of rows, and N is the number of columns. Each cell has up to 3 unvisited neighbors to explore for each character in the word.
// Space Complexity: O(L), where L is the length of the word, for the recursion stack. In the worst case, the depth of the recursion tree is equal to the length of the word.