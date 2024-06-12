/*
    Q. Count Subsets with Sum K (DP – 17)
    Practice : https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=perfect-sum-problem

    Given an array arr[] of non-negative integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.

    Note: Answer can be very large, so, output answer modulo 109+7

    Example 1:

    Input: N = 6, arr[] = {2, 3, 5, 6, 8, 10}
           sum = 10
    Output: 3
    Explanation: {2, 3, 5}, {2, 8}, {10}
    Example 2:
    Input: N = 5, arr[] = {1, 2, 3, 4, 5}
           sum = 10
    Output: 3
    Explanation: {1, 2, 3, 4}, {1, 4, 5},
                 {2, 3, 5}
*/

#include <bits/stdc++.h>
using namespace std;
// Function to count the number of subsets with a given sum
int findWaysUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    // Base case: If the target sum is 0, we found a valid subset
    if (target == 0)
        return 1;
    // Base case: If ind(0) ele is equal to target or not
    if (ind == 0)
        return (arr[0] == target) ? 1 : 0;

    // If the result for this state is already calculated, return it
    if (dp[ind][target] != -1)
        return dp[ind][target];

    // 1. Exclude the current element
    int notTaken = findWaysUtil(ind - 1, target, arr, dp);

    // 2. Include the current element if it doesn't exceed the target
    int taken = 0;
    if (arr[ind] <= target)
        taken = findWaysUtil(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = notTaken + taken;
}

// Function to count the number of subsets with a given sum
int findWays(vector<int> &num, int k)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return findWaysUtil(n - 1, k, num, dp);
}
int main()
{
    vector<int> arr = {1, 2, 2, 3};
    int k = 3;
    cout << "The number of subsets found are " << findWays(arr, k);
    return 0;
}

// Time Complexity: O(N*K)
// Reason: There are N*K states therefore at max ‘N*K’ new problems will be solved.

// Space Complexity: O(N*K) + O(N)
// Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*K)).

// TABULATION

#include <bits/stdc++.h>
using namespace std;

// Function to count the number of subsets with a given sum
int findWays(vector<int> &num, int k)
{
    int n = num.size();
    // Create a 2D DP table with dimensions n x k+1, initialized with zeros
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    // Base case: If the target sum is 0,
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    // Base caes Initialize the first row based on the first element of the array
    if (num[0] <= k)
    {
        dp[0][num[0]] = 1;
    }

    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            // Exclude the current element
            int notTaken = dp[ind - 1][target];
            // Include the current element if it doesn't exceed the target
            int taken = 0;
            if (num[ind] <= target)
            {
                taken = dp[ind - 1][target - num[ind]];
            }
            // Update the DP table
            dp[ind][target] = notTaken + taken;
        }
    }
    // The final result is in the last cell of the DP table
    return dp[n - 1][k];
}

int main()
{
    vector<int> arr = {1, 2, 2, 3};
    int k = 3;
    cout << "The number of subsets found are " << findWays(arr, k);
    return 0;
}
