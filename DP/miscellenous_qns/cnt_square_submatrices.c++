/*
    Q. Count Square Submatrices with All 1s | DP on Rectangles : DP 56

    Practice : https://leetcode.com/problems/count-square-submatrices-with-all-ones/

    Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

    Example 1:

    Input: matrix =
    [
      [0,1,1,1],
      [1,1,1,1],
      [0,1,1,1]
    ]
    Output: 15
    Explanation:
    There are 10 squares of side 1.
    There are 4 squares of side 2.
    There is  1 square of side 3.
    Total number of squares = 10 + 4 + 1 = 15.
    Example 2:

    Input: matrix =
    [
      [1,0,1],
      [1,1,0],
      [1,1,0]
    ]
    Output: 7
    Explanation:
    There are 6 squares of side 1.
    There is 1 square of side 2.
    Total number of squares = 6 + 1 = 7.

    Approach:

The algorithm steps are as follows:

1. First, we need to create a dp array of the same size as the matrix.
2. Then, we will copy the values of the first row and first column of the matrix as it is to the dp array by for loop.
3. Then, we will start iterating over the rest of the cells and we will observe two cases:
     A) If the cell (i, j) contains 0, we will set the value 0 to the cell dp[i][j].
     B) If the cell (i, j) contains 1, we will first find the minimum value among the adjacent three cells i.e. min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]). And with that minimum value, we will add 1 and set it to the cell dp[i][j]. The formula will look like the following:
     dp[i][j] = min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) +1
4. After filling all the cells in this way, we will just add all the values of the dp array to get the total sum. And this total sum will be the final answer.
*/

#include <bits/stdc++.h>
using namespace std;
int countSquares(int n, int m, vector<vector<int>> &arr)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));
    // set the first row and first col
    for (int j = 0; j < m; j++)
        dp[0][j] = arr[0][j];
    for (int i = 0; i < n; i++)
        dp[i][0] = arr[i][0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (arr[i][j] == 0)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j],
                                   min(dp[i - 1][j - 1], dp[i][j - 1]));
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sum += dp[i][j];
        }
    }
    return sum;
}

int main()
{
    vector<vector<int>> arr = {
        {0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}};
    int n = 3, m = 4;
    int squares = countSquares(n, m, arr);
    cout << "The number of squares: " << squares << "\n";
    return 0;
}
// output is 15