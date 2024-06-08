//   Q. Grid Unique Paths 2 (DP 9)
//     Practice : https://leetcode.com/problems/unique-paths-ii/description/
//     You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
//     An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

//     Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

//     The testcases are generated so that the answer will be less than or equal to 2 * 109.
//     Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
//     Output: 2
//     Explanation: There is one obstacle in the middle of the 3x3 grid above.
//     There are two ways to reach the bottom-right corner:
//     1. Right -> Right -> Down -> Down
//     2. Down -> Down -> Right -> Right

// MEMORIZATION

#include <bits/stdc++.h>
using namespace std;
// Helper function to count the number of paths from (i, j) to (0, 0)
int mazeObstaclesUtil(int i, int j, vector<vector<int>> &maze, vector<vector<int>> &dp)
{
    // Base cases
    if (i > 0 && j > 0 && maze[i][j] == -1)
        return 0; // If there's an obstacle at (i, j), return 0
    if (i == 0 && j == 0)
        return 1; // If we reach the destination (0, 0), return 1
    if (i < 0 || j < 0)
        return 0; // If we go out of bounds, return 0
    if (dp[i][j] != -1)
        return dp[i][j];
    // Recursive calls to explore paths from (i, j) to (0, 0)
    int up = mazeObstaclesUtil(i - 1, j, maze, dp);
    int left = mazeObstaclesUtil(i, j - 1, maze, dp);
    // Store the result in the DP table and return it
    return dp[i][j] = up + left;
}
// Main function to count paths with obstacles in a maze
int mazeObstacles(int n, int m, vector<vector<int>> &maze)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));    // DP table to memoize results
    return mazeObstaclesUtil(n - 1, m - 1, maze, dp); // Start from the bottom-right corner
}
int main()
{
    vector<vector<int>> maze{
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0}};
    int n = maze.size();
    int m = maze[0].size();
    cout << "Number of paths with obstacles: " << mazeObstacles(n, m, maze) << endl;
    return 0;
}
// Time Complexity: O(N*M)
// Reason: At max, there will be N*M calls of recursion.
// Space Complexity: O((M-1)+(N-1)) + O(N*M)
// Reason: We are using a recursion stack space:O((M-1)+(N-1)), here (M-1)+(N-1) is the path length and an external DP Array of size ‘N*M’.

// TABULATION
int mazeObstaclesUtil(int n, int m, vector<vector<int>> &maze)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // Base conditions
            if (i > 0 && j > 0 && maze[i][j] == -1)
            {
                dp[i][j] = 0; // If there's an obstacle at (i, j), no paths can pass through it
                continue;
            }
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1; // If we are at the starting point, there is one path to it
                continue;
            }
            int up = 0;
            int left = 0;
            // Check if we can move up and left (if not at the edge of the maze)
            if (i > 0)
                up = dp[i - 1][j];
            if (j > 0)
                left = dp[i][j - 1];
            dp[i][j] = up + left;
        }
    }
    // The final result is stored in dp[n-1][m-1], which represents the destination
    return dp[n - 1][m - 1];
}
