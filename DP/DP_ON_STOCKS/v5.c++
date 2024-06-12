/*
    Q. Buy and Sell Stocks With Transaction Fees | (DP – 40)

    Practice : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

    Given an integer array nums, return the length of the longest strictly increasing
    subsequence.

    Example 1:

    Input: nums = [10,9,2,5,3,7,101,18]
    Output: 4
    Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
    Example 2:

    Input: nums = [0,1,0,3,2,3]
    Output: 4
    Example 3:

    Input: nums = [7,7,7,7,7,7,7]
    Output: 1
*/

// memorization

#include <bits/stdc++.h>
using namespace std;
int getAns(vector<int> &Arr, int ind, int buy, int n, int fee, vector<vector<int>> &dp)
{
    // Base case: If we've reached the end of the array, return 0 profit.
    if (ind == n)
        return 0;

    // Check if the result is already computed
    if (dp[ind][buy] != -1)
        return dp[ind][buy];

    int profit;

    if (buy == 0)
    { // We can buy the stock
        profit = max(0 + getAns(Arr, ind + 1, 0, n, fee, dp), -Arr[ind] + getAns(Arr, ind + 1, 1, n, fee, dp));
    }

    if (buy == 1)
    { // We can sell the stock
        profit = max(0 + getAns(Arr, ind + 1, 1, n, fee, dp), Arr[ind] - fee + getAns(Arr, ind + 1, 0, n, fee, dp));
    }
    // Store the computed profit in the DP array
    return dp[ind][buy] = profit;
}

int maximumProfit(int n, int fee, vector<int> &Arr)
{
    vector<vector<int>> dp(n, vector<int>(2, -1));
    if (n == 0)
        return 0; // Edge case: No stocks to trade.
    int ans = getAns(Arr, 0, 0, n, fee, dp);
    return ans;
}
int main()
{
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int n = prices.size();
    int fee = 2;
    cout << "The maximum profit that can be generated is " << maximumProfit(n, fee, prices) << endl;
    return 0;
}

// Tabulation

#include <bits/stdc++.h>
using namespace std;
int maximumProfit(int n, int fee, vector<int> &Arr)
{
    if (n == 0)
        return 0; // Edge case: No stocks to trade.
    // Create a 2D DP array with dimensions (n+1) x 2, initialized to 0
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    // Loop through the stock prices from the end to the beginning
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit;

            if (buy == 0)
            { // We can buy the stock
                profit = max(0 + dp[ind + 1][0], -Arr[ind] + dp[ind + 1][1]);
            }

            if (buy == 1)
            {                                                                      // We can sell the stock
                profit = max(0 + dp[ind + 1][1], Arr[ind] - fee + dp[ind + 1][0]); // subtract the fee
            }

            dp[ind][buy] = profit; // either of profit
        }
    }
    return dp[0][0]; // Return the maximum profit for buying.
}
