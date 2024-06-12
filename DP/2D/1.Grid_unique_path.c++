/*
    Q. Grid Unique Paths : DP on Grids (DP8)
    Practice : https://leetcode.com/problems/unique-paths/description/
    There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

    Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

    The test cases are generated so that the answer will be less than or equal to 2 * 109.

    Example 1:

    Input: m = 3, n = 7
    Output: 28
    Example 2:

    Input: m = 3, n = 2
    Output: 3
    Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
    1. Right -> Down -> Down
    2. Down -> Down -> Right
    3. Down -> Right -> Down
*/
// MEMORIZATION

#include <bits/stdc++.h>
using namespace std;
// Recursive function to count the number of ways to reach (i, j) from (0, 0)
// in a grid of size m x n
int solve(int i, int j, vector<vector<int>> &dp)
{
    // Base case: If we reach the top-left corner (0, 0), there is one way.
    if (i == 0 && j == 0)
        return 1;
    // If we go out of bounds or reach a blocked cell, there are no ways.
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    // Calculate the number of ways by moving up and left recursively.
    int up = solve(i - 1, j, dp);
    int left = solve(i, j - 1, dp);
    // Store the result in the dp table and return it.
    return dp[i][j] = up + left;
}
// Function to count the number of ways to reach the bottom-right cell (m-1, n-1)
// from the top-left cell (0, 0) in a grid of size m x n
int countWays(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(m - 1, n - 1, dp);
}
int main()
{
    int m = 3;
    int n = 2;
    // Call the countWays function and print the result.
    cout << "Number of ways to reach (" << m - 1 << ", " << n - 1 << "): " << countWays(m, n) << endl;
    return 0;
}
// Time Complexity: O(M*N)
// Reason: At max, there will be M*N calls of recursion.
// Space Complexity: O((N-1)+(M-1)) + O(M*N)


// TABULATION
int countWays(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            int down = 0, right = 0;
            if (i > 0)
                down = dp[i - 1][j];
            if (j > 0)
                right = dp[i][j - 1];
            dp[i][j] = down + right;
        }
    }
    return dp[m - 1][n - 1];
}
// Time Complexity: O(M*N)
// Reason: There are two nested loops
// Space Complexity: O(M*N)
// Reason: We are using an external array of size ‘M*N’’.
