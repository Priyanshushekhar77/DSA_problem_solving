/*
    Q. Subset sum equal to target (DP- 14)
    Practice : https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=subset-sum-problem-1611555638

    Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.

    Example 1:

    Input:
    N = 6
    arr[] = {3, 34, 4, 12, 5, 2}
    sum = 9
    Output: 1
    Explanation: Here there exists a subset with
    sum = 9, 4+3+2 = 9.
    Example 2:

    Input:
    N = 6
    arr[] = {3, 34, 4, 12, 5, 2}
    sum = 30
    Output: 0
    Explanation: There is no subset with sum 30.
*/
#include <bits/stdc++.h>
using namespace std;
bool subsetSumUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    // base cases
    if (target == 0)
        return 1;
    if (ind == 0)
        return arr[0] == target;
    if (dp[ind][target] != -1)
        return dp[ind][target];
    // Try not taking the current element into the subset
    bool nottake = subsetSumUtil(ind - 1, target, arr, dp);
    bool take = false;
    // taking the current element
    if (target >= arr[ind])
    {
        take = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);
    }
    return dp[ind][target] = take || nottake;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Initialize a 2D DP array for memoization yaking care of(ind and target)
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    // Call the recursive subsetSumUtil function
    return subsetSumUtil(n - 1, k, arr, dp);
}
int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();

    // Call the subsetSumToK function and print the result
    if (subsetSumToK(n, k, arr))
        cout << "Subset with the given target found";
    else
        cout << "Subset with the given target not found";

    return 0;
}
// Time Complexity: O(N*K)
// Reason: There are N*K states therefore at max ‘N*K’ new problems will be solved.
// Space Complexity: O(N*K) + O(N)
// Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*K)).

// TABULATION

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    // Base case: If the target sum is 0, we can always achieve it by taking no elements
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    // Base case: If the first element of 'arr' is less than or equal to 'k', set dp[0][arr[0]] to true
    if (arr[0] <= k)
    {
        dp[0][arr[0]] = true;
    }
    // fill the dp array
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool nottake = dp[ind - 1][target];
            bool take = false;
            if (arr[ind] <= target)
            {
                take = dp[ind - 1][target - arr[ind]];
            }
            dp[ind][target] = take || nottake;
        }
    }
    return dp[n - 1][k];
}

// Time Complexity: O(N*K)

// Reason: There are two nested loops

// Space Complexity: O(N*K)

// Reason: We are using an external array of size ‘N*K’. Stack Space is eliminated.