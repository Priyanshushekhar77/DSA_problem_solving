/*
    Q. Buy and Sell Stock – IV | (DP – 38)  atmost K transaction allowed

    Practice : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

    You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

    Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

    Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

    Example 1:

    Input: k = 2, prices = [2,4,1]
    Output: 2
    Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
    Example 2:

    Input: k = 2, prices = [3,2,6,5,0,3]
    Output: 7
    Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
*/

class Solution
{
public:
    int maxProfit(vector<int> &prices, int k)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int trans = 2 * k - 1; trans >= 0; trans--)
            {
                if (trans % 2 == 0)
                { // buy
                    dp[ind][trans] = max(0 + dp[ind + 1][trans], -prices[ind] + dp[ind][trans + 1]);
                }
                else
                { // sell will allowed at odd places
                    dp[ind][trans] = max(0 + dp[ind + 1][trans], prices[ind] + dp[ind + 1][trans + 1]);
                }
            }
        }
        return dp[0][0];
    }
};