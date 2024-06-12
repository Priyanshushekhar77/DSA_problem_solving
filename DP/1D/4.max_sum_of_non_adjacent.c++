/*
    Q. Maximum sum of non-adjacent elements (DP 5)
    Practice : https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=max-sum-without-adjacents
    Given an array Arr of size N containing positive integers. Find the maximum sum of a subsequence such that no two numbers in the sequence should be adjacent in the array.

    Example 1:

    Input:
    N = 6
    Arr[] = {5, 5, 10, 100, 10, 5}
    Output: 110
    Explanation: If you take indices 0, 3
    and 5, then Arr[0]+Arr[3]+Arr[5] =
    5+100+5 = 110.
    Example 2:

    Input:
    N = 4
    Arr[] = {3, 2, 7, 10}
    Output: 13
    Explanation: 3 and 10 forms a non
    continuous  subsequence with maximum
    sum.
*/

#include <bits/stdc++.h>
using namespace std;
// RECURSION
static int maxSum(int arr[], int idx)
{
    if (idx < 0)
        return 0;

    // pick
    int a = arr[idx] + maxSum(arr, idx - 2);

    // not pick
    int b = 0 + maxSum(arr, idx - 1);

    return max(a, b);
}

static int findMaxSum(int arr[], int n)
{
    return maxSum(arr, n - 1);
}
// T.C=>O(2(pow(n))) becz for each element has two choices either pick or not pick and space complexity is O(N) becz max depth of the recursion stack will be N.

// MEMORIZATION
static int maxSum(int arr[], int idx, vector<int> &dp)
{
    if (idx < 0)
        return 0;
    if (idx == 0)
        return arr[0];
    if (dp[idx] != -1)
        return dp[idx];
    // pick
    int a = arr[idx] + maxSum(arr, idx - 2, dp);
    // not pick
    int b = 0 + maxSum(arr, idx - 1, dp);
    return dp[idx] = max(a, b);
}
// T.C=>O(N) becz Each state (each index) is computed once and stored in the dp array,and  Space for the dp array (O(N)) + Recursion stack space (O(N)).

// Tabulation
static int maxsum(int arr[], int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        int pick = arr[i];
        if (i > 1)
        {
            pick += dp[i - 2];
        }
        int notpick = dp[i - 1];
        dp[i] = max(pick, notpick);
    }
    return dp[n - 1];
}
// Time Complexity:
// O(N): Iterates through the array once, computing the result for each index.
// Space Complexity:
// O(N): Space for the dp array
int main()
{
    int N = 6;
    int arr[] = {5, 5, 10, 100, 10, 5};
    cout << maxSum(arr, N) << endl;
    return 0;
}