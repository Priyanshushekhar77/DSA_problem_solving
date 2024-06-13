/*
    Q.Number of  Longest Inc. Subsequence | (DP-46)

    Practice : https://leetcode.com/problems/number-of-longest-increasing-subsequence/

    Given an integer array nums, return the number of longest increasing subsequences.

    Notice that the sequence has to be strictly increasing.

    Example 1:

    Input: nums = [1,3,5,4,7]
    Output: 2
    Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
    Example 2:

    Input: nums = [2,2,2,2,2]
    Output: 5
    Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.


    dp[i] refers to the length of the longest incresing subsequence of the original array with the element arr[i] as its last element.
    ct[i] refers to the count of longest inc subsequence of the org. array that are possible of length of dp[i] with the element arr[i] as its last element.

    =>Approach -
    1. if( arr[j] < arr[i] && dp[j+1] > dp[i]), in this case we get a new LIS of greater length, therefore the number of LIS ending at arr[i], is the same as number of LIS ending at arr[j] as we simply append the element arr[j] to all those LIS. In simple terms, ct[i] = ct[j]. Try to dry run this example to understand: [1, 2, 3],

   2. if( arr[j] < arr[i] && dp[j+1]==dp[i]) in this case we get a new LIS of same length at which the ct[i] is originally holding the value for. Therefore the new ct[j] value will be the number of LIS that was given by its original value plus the number of LIS that ends at element arr[j] at length dp[j]. In simple terms, ct[i] = ct[i] + ct[j]. Try to dry run this example to understand: [1, 5, 6, 10].
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the count of Longest Increasing Subsequences (LIS)
int findNumberOfLIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 1); // dp[i] stores the length of the LIS ending at arr[i]
    vector<int> ct(n, 1); // ct[i] stores the count of LIS ending at arr[i]
    int maxi = 1;         // Initialize the maximum length as 1

    for (int i = 0; i < n; i++)
    {
        for (int prev_index = 0; prev_index < i; prev_index++)
        {
            if (arr[prev_index] < arr[i] && dp[prev_index] + 1 > dp[i])
            {
                dp[i] = dp[prev_index] + 1;
                // Inherit count
                ct[i] = ct[prev_index];
            }
            else if (arr[prev_index] < arr[i] && dp[prev_index] + 1 == dp[i])
            {
                // Increase the count
                ct[i] = ct[i] + ct[prev_index];
            }
        }
        maxi = max(maxi, dp[i]);
    }
    // counting lis of max length
    int numberOfLIS = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxi)
        {
            numberOfLIS += ct[i];
        }
    }
    return numberOfLIS;
}

int main()
{
    vector<int> arr = {1, 5, 4, 3, 2, 6, 7, 2};
    cout << "The count of Longest Increasing Subsequences (LIS) is " << findNumberOfLIS(arr) << endl;
    return 0;
}
// output is 4