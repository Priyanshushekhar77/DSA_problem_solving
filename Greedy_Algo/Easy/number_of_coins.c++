
// Input: V = 11, M = 4,coins[] = {9, 6, 5, 1}
// Output: 2
// Explanation: Use one 6 cent coin
// and one 5 cent coin
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &arr, int n, int target, vector<int> &dp)
{
    if (target < 0)
        return INT_MAX;
    if (target == 0)
        return 0;
    if (dp[target] != -1)
        return dp[target];
    int coins = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        // coins colln loop
        int ans = solve(arr, n, target - arr[i], dp);
        if (ans != INT_MAX)
        {
            coins = min(coins, ans + 1);
        }
    }
    dp[target] = coins;
    return dp[target];
}
int minCoins(vector<int> &coins, int M, int V)
{
    // Your code goes here
    vector<int> dp(V + 1, -1);
    int ans = solve(coins, M, V, dp);
    if (ans == INT_MAX)
        return -1;
    else
        return ans;
}
// T.C O(n)
// S.C O(n) + O(n)