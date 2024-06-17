/*
    Q. Partition Array for Maximum Sum | Front Partition : DP 54

    Practice : https://leetcode.com/problems/partition-array-for-maximum-sum/description/

    Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

    Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

    Example 1:

    Input: arr = [1,15,7,9,2,5,10], k = 3
    Output: 84
    Explanation: arr becomes [15,15,15,9,10,10,10]
    Example 2:

    Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
    Output: 83
    Example 3:

    Input: arr = [1], k = 1
    Output: 1
    approach->
    1. Convert the problem to a recursive function marked by the pointer ind.
    2.Use a loop to check all possible partitions of the array and calculate the maximum sum we can achieve.
    3.Return the maximum possible sum.
    4.Base case: When the value of ind becomes equal to n(n = size of the array), we can say there are no elements left to be considered. So, when (ind == n) the function will return 0.
*/

// memoziation

#include <bits/stdc++.h>
using namespace std;
// Recursive function to find the maximum sum after partitioning.
int f(int ind, vector<int> &num, int k, vector<int> &dp)
{
    int n = num.size();
    // Base case: If the current index is equal to the size of the array, return 0.
    if (ind == n)
        return 0;
    // If the result for this index is already computed, return it from dp array.
    if (dp[ind] != -1)
        return dp[ind];
    int len = 0;
    int maxi = INT_MIN;
    int maxAns = INT_MIN;

    // Loop through the array starting from the current index.
    for (int j = ind; j < min(ind + k, n); j++)
    {
        len++;
        maxi = max(maxi, num[j]);
        int sum = len * maxi + f(j + 1, num, k, dp);
        maxAns = max(maxAns, sum);
    }
    // Store the computed result in the dp array and return it.
    return dp[ind] = maxAns;
}
int maxSumAfterPartitioning(vector<int> &num, int k)
{
    int n = num.size();
    vector<int> dp(n, -1);
    return f(0, num, k, dp);
}
int main()
{
    vector<int> num = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;
    int maxSum = maxSumAfterPartitioning(num, k);
    cout << "The maximum sum is: " << maxSum << "\n";
    return 0;
}
/* Time Complexity: O(N*k)
Reason: There are a total of N states and for each state, we are running a loop from 0 to k.
Space Complexity: O(N) + Auxiliary stack space O(N)
*/

/*Tabulation
1. First of all, we handle the base case. If (ind == n) we return 0. To cover this case we can initialize the entire dp array with 0.
Here, as we are checking dp[j+1]  every time, the function will give a runtime error if j = n-1. To avoid this, we will take the array size as n+1 instead of n.
2.Next, memoization is a top-down approach, whereas tabulation is bottom-up. Our changing parameter ind will change in opposite directions, i.e ind will change from n-1→0.
3.Next, we copy down the recursive logic(recurrence) inside the loop.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum sum after partitioning the array.
int maxSumAfterPartitioning(vector<int> &num, int k)
{
    int n = num.size();
    // Create a DP array to store the maximum sum.
    vector<int> dp(n + 1, 0);
    // Iterate through the array from right to left.
    for (int ind = n - 1; ind >= 0; ind--)
    {
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;

        // Loop through the next k elements (or remaining elements if k is smaller).
        for (int j = ind; j < min(ind + k, n); j++)
        {
            len++;
            maxi = max(maxi, num[j]);
            int sum = len * maxi + dp[j + 1];
            maxAns = max(maxAns, sum);
        }

        // Store the computed maximum sum in the DP array.
        dp[ind] = maxAns;
    }
    // The maximum sum after partitioning the entire array is stored in dp[0].
    return dp[0];
}
