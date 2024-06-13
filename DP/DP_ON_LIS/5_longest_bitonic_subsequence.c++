/*
    Q. Longest Bitonic Subsequence | (DP-46)

    Practice : https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1

    Given an array of positive integers. Find the maximum length of Bitonic subsequence.
    A subsequence of array is called Bitonic if it is first strictly increasing, then strictly decreasing.
    => A bitonic subsequence is a subsequence of an array in which the elements can be any of these three:
    First, increase till a point and then decrease.
    Goes on increasing (Longest increasing subsequence)
    Goes on decreasing (Longest decreasing subsequence)

    Example 1:

    Input: nums = [1, 2, 5, 3, 2]
    Output: 5
    Explanation: The sequence {1, 2, 5} is
    increasing and the sequence {3, 2} is
    decreasing so merging both we will get
    length 5.
    Example 2:

    Input: nums = [1, 11, 2, 10, 4, 5, 2, 1]
    Output: 6
    Explanation: The bitonic sequence
    {1, 2, 10, 4, 2, 1} has length 6.


    Approach:
   The algorithm approach is stated as follows:

   1. Using the approach of the article Printing Longest Increasing subsequence, find the dp1[ ] array, where dp1[i] gives us the length of the LIS from index 0 to index i.
   2. Modifying the approach slightly, find the dp2[ ] array, where dp2[i] gives us the length of the LIS from index n-1 to index i. To find this opposite direction LIS simply reverses the direction of variables in the nested loops (see the code).
   3. At last return the answer (the length of the longest bitonic subsequence) as the maximum value of dp1[i] - dp2[i] -1.
*/

#include <bits/stdc++.h>
using namespace std;
// Function to find the length of the longest bitonic subsequence
int longestBitonicSequence(vector<int> &arr, int n)
{
    // Initialize two arrays to store the increasing and decreasing subsequences
    vector<int> dp1(n, 1); // dp1[i] stores the length of the longest increasing subsequence from 0 to n-1
    vector<int> dp2(n, 1); // dp2[i] stores the length of the longest decreasing subsequence from n-1 to 0

    // Calculate the longest increasing subsequence
    for (int i = 0; i < n; i++)
    {
        for (int prev_index = 0; prev_index < i; prev_index++)
        {
            if (arr[prev_index] < arr[i] && dp1[i] < 1 + dp1[prev_index])
            {
                dp1[i] = 1 + dp1[prev_index];
            }
        }
    }

    // Reverse the direction of nested loops to calculate the longest decreasing subsequence
    for (int i = n - 1; i >= 0; i--)
    {
        for (int prev_index = n - 1; prev_index > i; prev_index--)
        {
            if (arr[prev_index] < arr[i] && dp2[i] < 1 + dp2[prev_index])
            {
                dp2[i] = 1 + dp2[prev_index];
            }
        }
    }

    int maxi = -1;
    // Find the maximum length of the bitonic subsequence
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }
    return maxi;
}

int main()
{
    vector<int> arr = {1, 11, 2, 10, 4, 5, 2, 1};
    int n = arr.size();
    cout << "The length of the longest bitonic subsequence is " << longestBitonicSequence(arr, n) << endl;
    return 0;
}

// output is 6