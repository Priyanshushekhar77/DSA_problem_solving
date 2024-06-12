// VARIABLE STARTING POINT AND VARIABLE ENDING POINTS QNS.

// Q. Minimum/Maximum Falling Path Sum (DP-12)
//     Practice : https://leetcode.com/problems/minimum-falling-path-sum/description/
//     Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

//     A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

//     Example 1:

//     Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
//     Output: 13
//     Explanation: There are two falling paths with a minimum sum as shown.

// MEMORIZATION

#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    // Base Conditions
    if (j < 0 || j >= m)
        return -1e9; // A very large negative value to represent an invalid path
    if (i == 0)      // if we reach to the first row than base case will be
        return matrix[0][j];
    if (dp[i][j] != -1)
        return dp[i][j];

    // Calculate the maximum path sum by considering three possible directions: up, left diagonal, and right diagonal
    int up = matrix[i][j] + solve(i - 1, j, m, matrix, dp);
    int leftDiagonal = matrix[i][j] + solve(i - 1, j - 1, m, matrix, dp);
    int rightDiagonal = matrix[i][j] + solve(i - 1, j + 1, m, matrix, dp);
    // Store the maximum of the three paths in dp
    return dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
}
// Function to find the maximum path sum in the given matrix
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxi = INT_MIN;
    // Iterate through each cell in the last row to find the maximum path sum starting from each of them
    for (int j = 0; j < m; j++)
    {
        int ans = solve(n - 1, j, m, matrix, dp);
        maxi = max(maxi, ans); // Update the maximum path sum if a larger one is found on a starting from last row of any variable column
    }
    return maxi; // Return the maximum path sum
}
int main()
{
    vector<vector<int>> matrix{{1, 2, 10, 4},
                               {100, 3, 2, 1},
                               {1, 1, 20, 2},
                               {1, 2, 2, 1}};
    cout << getMaxPathSum(matrix);
    return 0;
}
// Time Complexity: O(N*N)
// Reason: At max, there will be M*N calls of recursion to solve a new problem,
// Space Complexity: O(N) + O(N*M)
// Reason: We are using a recursion stack space: O(N), where N is the path length and an external DP Array of size ‘N*M’.

// TABULATION

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    // Initialize the first row of dp with values from the matrix (base condition)//bottom to top approach
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = matrix[0][j];
    }
    // Iterate through the matrix rows starting from the second row
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // Calculate the maximum path sum for the current cell considering three possible directions: up, left diagonal, and right diagonal
            // Up direction
            int up = matrix[i][j] + dp[i - 1][j];
            // Left diagonal direction (if it's a valid move)
            int leftDiagonal = matrix[i][j];
            if (j > 0)
            {
                leftDiagonal += dp[i - 1][j - 1];
            }
            else
            {
                leftDiagonal += -1e9;
            }
            // Right diagonal direction (if it's a valid move)
            int rightDiagonal = matrix[i][j];
            if (j < m - 1)
            {
                rightDiagonal += dp[i - 1][j + 1];
            }
            else
            {
                rightDiagonal += -1e9;
            }
            // Store the maximum of the three paths in dp
            dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
        }
    }
    // Find the maximum value in the last row of dp, which represents the maximum path sums ending at each cell
    int maxi = INT_MIN;
    for (int j = 0; j < m; j++)
    {
        maxi = max(maxi, dp[n - 1][j]);
    }
    // The maximum path sum is the maximum value in the last row
    return maxi;
}

// Time Complexity: O(N*M)
// Reason: There are two nested loops
// Space Complexity: O(N*M)
// Reason: We are using an external array of size ‘N*M’. The stack space will be eliminated.