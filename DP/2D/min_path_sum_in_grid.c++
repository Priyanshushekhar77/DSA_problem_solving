/*
    Q. Minimum Path Sum In a Grid (DP 10)
    Practice : https://leetcode.com/problems/minimum-path-sum/description/
    Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

    Note: You can only move either down or right at any point in time.

    Example 1:

    Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
    Output: 7
    Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
    Example 2:

    Input: grid = [[1,2,3],[4,5,6]]
    Output: 12
*/
// MEMORIZATION

#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    // Base cases
    if (i == 0 && j == 0)
        return matrix[0][0];
    if (i < 0 || j < 0)
        return INT_MAX; // If we go out of bounds, return a large value to avoid considering this path
    if (dp[i][j] != -1)
        return dp[i][j];
    // Calculate the minimum sum path by considering moving up and moving left
    int up = matrix[i][j] + solve(i - 1, j, matrix, dp);
    int left = matrix[i][j] + solve(i, j - 1, matrix, dp);
    // Store the result in the DP table and return it
    return dp[i][j] = min(up, left);
}
int minSumPath(int n, int m, vector<vector<int>> &matrix)
{
    vector<vector<int>> dp(n, vector<int>(m, -1)); // DP table to memoize results
    return solve(n - 1, m - 1, matrix, dp);        // Start from the bottom-right corner
}
int main()
{
    vector<vector<int>> matrix{
        {5, 9, 6},
        {11, 5, 2}};
    int n = matrix.size();
    int m = matrix[0].size();
    cout << "Minimum sum path: " << minSumPath(n, m, matrix) << endl;
    return 0;
}
// Time Complexity: O(N*M)
// Reason: At max, there will be N*M calls of recursion.
// Space Complexity: O((M-1)+(N-1)) + O(N*M)
// Reason: We are using a recursion stack space: O((M-1)+(N-1)), here (M-1)+(N-1) is the path length and an external DP Array of size ‘N*M’.

// TABULATION
int minSumPath(int n, int m, vector<vector<int>> &matrix)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = matrix[0][0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            int up = matrix[i][j];
            if (i > 0)
                up += dp[i - 1][j];
            else
                up += 1e9;
            int left = matrix[i][j];
            if (j > 0)
                left += dp[i][j - 1];
            else
                left += 1e9;
            dp[i][j] = min(up, left);
        }
    }
    return dp[n - 1][m - 1];
}
