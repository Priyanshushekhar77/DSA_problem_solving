/*
    Q. Rod Cutting Problem | (DP – 24)

    Practice : https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

    Given a rod of length N inches and an array of prices, price[]. price[i] denotes the value of a piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

    Note: Consider 1-based indexing.

    Example 1:

    Input:
    N = 8
    Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
    Output:
    22
    Explanation:
    The maximum obtainable value is 22 by
    cutting in two pieces of lengths 2 and
    6, i.e., 5+17=22.
    Example 2:

    Input:
    N=8
    Price[] = {3, 5, 8, 9, 10, 17, 17, 20}
    Output:
    24
    Explanation:
    The maximum obtainable value is
    24 by cutting the rod into 8 pieces
    of length 3, i.e, 8*3=24.
*/
// MEMORIZATION

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int helper(const vector<int> &price, int i, int n, vector<vector<int>> &dp)
{
    // base case
    if (i == 0)
        return n * price[0];

    if (dp[i][n] != -1)
        return dp[i][n];

    // take
    int take = INT_MIN;
    if (i + 1 <= n)
        take = price[i] + helper(price, i, n - (i + 1), dp);

    // not take
    int notTake = helper(price, i - 1, n, dp);

    return dp[i][n] = max(take, notTake);
}

int cutRod(const vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return helper(price, n - 1, n, dp);
}

// Tabulation
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int cutRod(const vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    for (int i = 0; i <= n; ++i)
    {
        dp[0][i] = i * price[0];
    }

    for (int i = 1; i < n; ++i)
    {
        for (int length = 0; length <= n; ++length)
        {
            // take
            int take = INT_MIN;
            if (i + 1 <= length)
                take = price[i] + dp[i][length - (i + 1)];

            // not take
            int notTake = dp[i - 1][length];

            dp[i][length] = max(take, notTake);
        }
    }

    return dp[n - 1][n];
}
