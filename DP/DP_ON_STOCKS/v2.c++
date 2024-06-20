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
// memoziation (gives TLE)

int solve(int ind ,int tran,int k, vector<int>& prices,vector<vector<int>>&dp){
    int n=prices.size();
    if(ind==n) return 0;
    if(tran==2*k) return 0;
    int profit=0;
    if(tran%2==0){
      profit=max(0+solve(ind+1,tran,k,prices,dp) , -prices[ind]+ solve(ind+1,tran+1,k,prices,dp));
    }
      else{
       profit=max(0+solve(ind+1,tran,k,prices,dp),prices[ind]+solve(ind+1,tran+1,k,prices,dp));
      }
    return dp[ind][tran]=profit;
}
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
         vector<vector<int>>dp(n+1,vector<int>(2*k+1,-1));
    int trans=0;
    return solve(0,0,k,prices,dp);
    }

// tabulation
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
                int profit = 0;
                if (trans % 2 == 0)
                { // buy
                    profit = max(0 + dp[ind + 1][trans], -prices[ind] + dp[ind + 1][trans + 1]);
                }
                else
                { // sell will allowed at odd places
                    profit = max(0 + dp[ind + 1][trans], prices[ind] + dp[ind + 1][trans + 1]);
                }
                dp[ind][trans] = profit;
            }
        }
        return dp[0][0];
    }
};