/*
    Q. Buy and Sell Stock – II | (DP -36) Unlimited times buy and sell allowed

    Practice : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

    You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

    On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

    Find and return the maximum profit you can achieve.

    Example 1:

    Input: prices = [7,1,5,3,6,4]
    Output: 7
    Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
    Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
    Total profit is 4 + 3 = 7.
    Example 2:

    Input: prices = [1,2,3,4,5]
    Output: 4
    Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
    Total profit is 4.
    Example 3:

    Input: prices = [7,6,4,3,1]
    Output: 0
    Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

    algo=>
Case 1: When buy == 0, we can buy the stock.

If we can buy the stock on a particular day, we have two options:

Option 1: To do no transaction and move to the next day. In this case, the net profit earned will be 0 from the current transaction, and to calculate the maximum profit starting from the next day, we will recursively call f(ind+1,0). As we have not bought the stock, the ‘buy’ variable value will still remain 0, indicating that we can buy the stock the next day.
Option 2: The other option is to buy the stock on the current day. In this case, the net profit earned from the current transaction will be -Arr[i]. As we are buying the stock, we are giving money out of our pocket, therefore the profit we earn is negative. To calculate the maximum profit starting from the next day, we will recursively call f(ind+1,1). As we have bought the stock, the ‘buy’ variable value will change to 1, indicating that we can’t buy and only sell the stock the next day.
Case 2: When buy == 1, we can sell the stock.

2. If we can buy the stock on a particular day, we have two options:

Option 1: To do no transaction and move to the next day. In this case, the net profit earned will be 0 from the current transaction, and to calculate the maximum profit starting from the next day, we will recursively call f(ind+1,1). As we have not bought the stock, the ‘buy’ variable value will still remain at 1, indicating that we can’t buy and only sell the stock the next day.
Option 2: The other option is to sell the stock on the current day. In this case, the net profit earned from the current transaction will be +Arr[i]. As we are selling the stock, we are putting the money into our pocket, therefore the profit we earn is positive. To calculate the maximum profit starting from the next day, we will recursively call f(ind+1,0). As we have sold the stock, the ‘buy’ variable value will change to 0, indicating that we can buy the stock the next day.

Step 3:  Return the maximum

base case-If ind==n, it means we have finished trading on all days, and there is no more money that we can get, therefore we simply return 0.
*/

// memorization

#include <bits/stdc++.h>
using namespace std;

long getAns(long *Arr, int ind, int buy, int n, vector<vector<long>> &dp)
{
    // Base case: When we reach the end of the array, there are no more decisions to make.
    if (ind == n)
    {
        return 0;
    }
    // If the result for this state has already been calculated, return it
    if (dp[ind][buy] != -1)
    {
        return dp[ind][buy];
    }
    long profit = 0;

    if (buy == 0)
    { // We can buy the stock
        profit = max(0 + getAns(Arr, ind + 1, 0, n, dp), -Arr[ind] + getAns(Arr, ind + 1, 1, n, dp));
    }

    if (buy == 1)
    { // We can sell the stock
        profit = max(0 + getAns(Arr, ind + 1, 1, n, dp), Arr[ind] + getAns(Arr, ind + 1, 0, n, dp));
    }

    // Store the calculated profit in the DP table and return it
    return dp[ind][buy] = profit;
}

long getMaximumProfit(long *Arr, int n)
{
    // Create a DP table to memoize results
    vector<vector<long>> dp(n, vector<long>(2, -1));
    if (n == 0)
    {
        return 0;
    }
    long ans = getAns(Arr, 0, 0, n, dp);
    return ans;
}

/*
Time Complexity: O(N*2)

Reason: There are N*2 states therefore at max ‘N*2’ new problems will be solved and we are running a for loop for ‘N’ times to calculate the total sum

Space Complexity: O(N*2) + O(N)

Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*2)).
*/

// Tabulation

#include <bits/stdc++.h>
using namespace std;

long getMaximumProfit(long *Arr, int n)
{
    // Create a DP table to memoize results
    vector<vector<long>> dp(n + 1, vector<long>(2, -1)); // size n+1 initialsied to avoid runtime error

    // Base condition: When we have no stocks left, the profit is 0.
    dp[n][0] = dp[n][1] = 0;
    long profit;

    // Loop through the array in reverse order   // 0 means buy and 1 means sell
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy == 0)
            { // We can buy the stock
                profit = max(0 + dp[ind + 1][0], -Arr[ind] + dp[ind + 1][1]);
            }

            if (buy == 1)
            { // We can sell the stock
                profit = max(0 + dp[ind + 1][1], Arr[ind] + dp[ind + 1][0]);
            }

            dp[ind][buy] = profit;
        }
    }

    // The maximum profit is stored in dp[0][0] after all calculations
    return dp[0][0];
}
int main()
{
    int n = 6;
    long Arr[n] = {7, 1, 5, 3, 6, 4};
    cout << "The maximum profit that can be generated is " << getMaximumProfit(Arr, n);

    return 0;
}

// The maximum profit that can be generated is 7

/*
Complexity Analysis
Time Complexity: O(N*2)

Reason: There are two nested loops that account for O(N*2) complexity.

Space Complexity: O(N*2)

Reason: We are using an external array of size ‘N*2’. Stack Space is eliminated.
*/