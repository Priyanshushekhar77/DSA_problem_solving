/*
    Q. Partition Equal Subset Sum (DP- 15)
    Practice : https://leetcode.com/problems/partition-equal-subset-sum/description/

    Given an integer numsay nums, return true if you can partition the numsay into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

    Example 1:

    Input: nums = [1,5,11,5]
    Output: true
    Explanation: The numsay can be partitioned as [1, 5, 5] and [11].
    Example 2:

    Input: nums = [1,2,3,5]
    Output: false
    Explanation: The numsay cannot be partitioned into equal sum subsets.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to check if it's possible to partition the array into two subsets with equal sum
bool subsetSumUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    // Base case: If the target sum is 0, we found a valid partition
    if (target == 0)
        return true;

    // Base case: If we have considered all elements and the target is still not 0, return false
    if (ind == 0)
        return arr[0] == target;

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

// Function to check if the array can be partitioned into two equal subsets
bool canPartition(int n, vector<int> &arr)
{
    int totSum = 0;

    // Calculate the total sum of the array
    for (int i = 0; i < n; i++)
    {
        totSum += arr[i];
    }

    // If the total sum is odd, it cannot be partitioned into two equal subsets
    if (totSum % 2 == 1)
        return false;
    else
    {
        int k = totSum / 2;

        // Create a DP table with dimensions n x k+1 and initialize with -1
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        // Call the subsetSumUtil function to check if it's possible to partition
        return subsetSumUtil(n - 1, k, arr, dp);
    }
}

int main()
{
    vector<int> arr = {2, 3, 3, 3, 4, 5};
    int n = arr.size();

    if (canPartition(n, arr))
        cout << "The Array can be partitioned into two equal subsets";
    else
        cout << "The Array cannot be partitioned into two equal subsets";

    return 0;
}

// Time Complexity: O(N*K) + O(N)
// Reason: There are N*K states therefore at max ‘N*K’ new problems will be solved and we are running a for loop for ‘N’ times to calculate the total sum
// Space Complexity: O(N*K) + O(N)
// Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*K)).

// TABULATION

#include <bits/stdc++.h>
using namespace std;

// Function to check if it's possible to partition the array into two subsets with equal sum
bool canPartition(int n, vector<int> &arr)
{
    int totSum = 0;

    // Calculate the total sum of the array
    for (int i = 0; i < n; i++)
    {
        totSum += arr[i];
    }

    // If the total sum is odd, it cannot be partitioned into two equal subsets
    if (totSum % 2 == 1)
        return false;
    else
    {
        int k = totSum / 2;

        // Create a DP table with dimensions n x k+1, initialized with false
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

        // Base case: If the target sum is 0, it can be achieved by not selecting any elements
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }

        // Initialize the first row based on the first element of the array
        if (arr[0] <= k)
            dp[0][arr[0]] = true;

        // Fill in the DP table using a bottom-up approach
        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 1; target <= k; target++)
            {
                // Exclude the current element
                bool notTaken = dp[ind - 1][target];

                // Include the current element if it doesn't exceed the target
                bool taken = false;
                if (arr[ind] <= target)
                    taken = dp[ind - 1][target - arr[ind]];

                // Update the DP table
                dp[ind][target] = notTaken || taken;
            }
        }

        // The final result is in the last cell of the DP table
        return dp[n - 1][k];
    }
}

int main()
{
    vector<int> arr = {2, 3, 3, 3, 4, 5};
    int n = arr.size();

    if (canPartition(n, arr))
        cout << "The Array can be partitioned into two equal subsets";
    else
        cout << "The Array cannot be partitioned into two equal subsets";

    return 0;
}
