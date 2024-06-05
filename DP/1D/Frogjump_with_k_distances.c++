//   Q. Dynamic Programming: Frog Jump with k Distances (DP 4)
//     Practice : https://practice.geeksforgeeks.org/problems/minimal-cost/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimal-cost
//     There are n stones and an array of heights and Geek is standing at stone 1 and can jump to one of the following: Stone i+1, i+2, ... i+k stone and cost will be [hi-hj] is incurred, where j is the stone to land on. Find the minimum possible total cost incurred before the Geek reaches Stone N.
//     Input:
//     n = 5, k = 3
//     heights = {10, 30, 40, 50, 20}
//     Output:
//     30
//     Explanation:
//     Geek will follow the path 1->2->5, the total cost
//     would be | 10-30| + |30-20| = 30, which is minimum
#include <bits/stdc++.h>
using namespace std;
// RECURSION
int solve(const vector<int> &arr, int ind, int k)
{
    if (ind == 0)
        return 0;
    int mincost = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (ind >= i)
        {
            int currcost = solve(arr, ind - i, k) + abs(arr[ind] - arr[ind - i]);
            mincost = min(mincost, currcost);
        }
    }
    return mincost;
}
int minimizeCost(const vector<int> &arr, int N, int K)
{
    return solve(arr, N - 1, K);
}
// Time Complexity: O(K(pow(n)))This is because at each step, up to K recursive calls are made, leading to exponential time complexity. Each state can have up to K ifferent subproblems, and this repeats N times.
// The maximum depth of the recursion stack is N

// MEMORIZATION
int helper(const vector<int> &arr, int idx, int k, vector<int> &dp)
{
    if (idx == 0)
        return 0;
    if (dp[idx] != -1)
        return dp[idx];
    int minCost = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (idx >= i)
        {
            int currCost = abs(arr[idx] - arr[idx - i]) + helper(arr, idx - i, k, dp);
            minCost = min(currCost, minCost);
        }
    }
    return dp[idx] = minCost;
}
int minimizeCost(const vector<int> &arr, int N, int K)
{
    vector<int> dp(N, -1);
    return helper(arr, N - 1, K, dp);
}
// Each state is computed once, resulting in O(n*K) time complexity.
// Space complexity is O(n) for the memoization array and O(n) for the recursion stack.

// TABULATION
int minimizeCost(const vector<int> &arr, int n, int k)
{
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i >= j)
            {
                int currcost = dp[i - j] + abs(arr[i] - arr[i - j]);
                dp[i] = min(dp[i], currcost);
            }
        }
    }
    return dp[n - 1];
}

// Iterates through the array once, so O(n*k) time complexity and O(n) space.

int main()
{
    int n = 5, k = 3;
    vector<int> heights = {10, 30, 40, 50, 20};
    cout << minimizeCost(heights, n, k) << endl;
    return 0;
}