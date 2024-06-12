/*
    Q. Partition Set Into 2 Subsets With Min Absolute Sum Diff (DP- 16)
    Practice : https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-sum-partition3317

    Given an array arr of size n containing non-negative integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference


    Example 1:

    Input: N = 4, arr[] = {1, 6, 11, 5}
    Output: 1
    Explanation:
    Subset1 = {1, 5, 6}, sum of Subset1 = 12
    Subset2 = {11}, sum of Subset2 = 11
    Example 2:
    Input: N = 2, arr[] = {1, 4}
    Output: 3
    Explanation:
    Subset1 = {1}, sum of Subset1 = 1
    Subset2 = {4}, sum of Subset2 = 4
*/

#include <bits/stdc++.h>
using namespace std;

// Function to solve the subset sum problem with memoization
bool subsetSumUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    // Base case: If the target sum is 0, return true
    if (target == 0)
        return dp[ind][0] = true;

    // Base case: If we have considered all elements and the target is still not 0, return false
    if (ind == 0)
        return dp[ind][target] = (arr[0] == target);

    // If the result for this state is already calculated, return it
    if (dp[ind][target] != -1)
        return dp[ind][target];

    // Recursive cases
    // 1. Exclude the current element
    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

    // 2. Include the current element if it doesn't exceed the target
    bool taken = false;
    if (arr[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

    // Store the result in the DP table and return
    return dp[ind][target] = notTaken || taken;
}

// Function to find the minimum absolute difference between two subset sums
int minSubsetSumDifference(vector<int> &arr, int n)
{
    int totSum = 0;

    // Calculate the total sum of the array
    for (int i = 0; i < n; i++)
    {
        totSum += arr[i];
    }

    // Initialize a DP table to store the results of the subset sum problem
    vector<vector<int>> dp(n, vector<int>(totSum + 1, -1));

    // Calculate the subset sum for each possible (target) from 0 to the total sum
    for (int i = 0; i <= totSum; i++)
    {
        bool dummy = subsetSumUtil(n - 1, i, arr, dp);
    }
    // determining min difference between subset1 and subset2
    int mini = 1e9;
    for (int i = 0; i <= totSum; i++)
    {
        if (dp[n - 1][i] == true)
        {
            int diff = abs(i - (totSum - i)); // subset(1) - subset(2)
            mini = min(mini, diff);
        }
    }
    return mini;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();

    cout << "The minimum absolute difference is: " << minSubsetSumDifference(arr, n);

    return 0;
}
// Time Complexity: O(N*totSum) +O(N) +O(N)
// Reason: There are two nested loops that account for O(N*totSum), at starting we are running a for loop to calculate totSum and at last a for loop to traverse the last row.

// Space Complexity: O(N*totSum) + O(N)
// Reason: We are using an external array of size ‘N * totSum’ and a stack space of O(N).

// TABULATION

#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum absolute difference between two subset sums
int minSubsetSumDifference(vector<int> &arr, int n)
{
    int totSum = 0;

    // Calculate the total sum of the array
    for (int i = 0; i < n; i++)
    {
        totSum += arr[i];
    }

    // Initialize a DP table to store the results of the subset sum problem
    vector<vector<bool>> dp(n, vector<bool>(totSum + 1, false));
    // base case-if target is zero
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    // if first element of the array is less than or equal to target than return true
    if (arr[0] <= totSum)
        dp[0][totSum] = true;

    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= totSum; target++)
        {
            // Exclude the current element
            bool notTaken = dp[ind - 1][target];

            // Include the current element if it doesn't exceed the target
            bool taken = false;
            if (arr[ind] <= target)
                taken = dp[ind - 1][target - arr[ind]];

            dp[ind][target] = notTaken || taken;
        }
    }

    int mini = 1e9;
    for (int i = 0; i <= totSum; i++)
    {
        // all the possible target stored in last row(i.e at last ind)
        if (dp[n - 1][i] == true)
        {
            // Calculate the absolute difference between two subset sums
            int diff = abs(i - (totSum - i)); // diff between subset(1) and subset(2)
            mini = min(mini, diff);
        }
    }
    return mini;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();

    cout << "The minimum absolute difference is: " << minSubsetSumDifference(arr, n);

    return 0;
}
