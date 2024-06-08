// FIXED STARTING POINT AND VARIABLE ENDING POINT QNS.

//  Q. Minimum path sum in Triangular Grid (DP 11)
//     Practice : https://leetcode.com/problems/triangle/description/
//     Given a triangle array, return the minimum path sum from top to bottom.

//     For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

//     Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
//     Output: 11
//     Explanation: The triangle looks like:
//        2
//       3 4
//      6 5 7
//     4 1 8 3
//     The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
// MEMORIZATION

#include <bits/stdc++.h>
using namespace std;
// i=0 and j=0
int solve(int i, int j, vector<vector<int>> &triangle, int n,
          vector<vector<int>> &dp)
{
    // If the result for this cell is already calculated, return it
    if (dp[i][j] != -1)
        return dp[i][j];
    // If we're at the bottom row that is at variable ending point, return the value of the current cell
    if (i == n - 1)
        return triangle[i][j];
    // Calculate the sum of two possible paths: going down and going diagonally
    int down = triangle[i][j] + solve(i + 1, j, triangle, n, dp);
    int diagonal = triangle[i][j] + solve(i + 1, j + 1, triangle, n, dp);

    // Store the minimum of the two paths in the dp table and return it
    return dp[i][j] = min(down, diagonal);
}

// Function to find the minimum path sum in the given triangle
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(0, 0, triangle, n, dp);
}
int main()
{
    // Define the triangle as a 2D vector
    vector<vector<int>> triangle{{1},
                                 {2, 3},
                                 {3, 6, 7},
                                 {8, 9, 6, 10}};
    int n = triangle.size();
    cout << minimumPathSum(triangle, n);
    return 0;
}
// Time Complexity: O(N*N)
// Reason: There are two nested loops
// Space Complexity: O(N*N)
// Reason: We are using an external array of size ‘N*N’. The stack space will be eliminated.

// TABULATION

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // BASE CASE-> Initialize the bottom row of dp with the values from the triangle
    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    // Iterate through the triangle rows in reverse order FROM BOTTOM TO TOP
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        { // AS J==i for a triangle
            // Calculate the minimum path sum for the current cell
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];
            // Store the minimum of the two possible paths in dp
            dp[i][j] = min(down, diagonal);
        }
    }
    // The top-left cell of dp now contains the minimum path sum
    return dp[0][0];
}