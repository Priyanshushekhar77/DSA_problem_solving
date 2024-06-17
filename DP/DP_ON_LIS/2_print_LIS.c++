/*
    Q. Printing Longest Increasing Subsequence | (DP-42)

    Practice : https://leetcode.com/problems/longest-increasing-subsequence/description/

    Given an integer array nums, print the longest strictly increasing subsequence.

    Example 1:

    Input: nums = [10,9,2,5,3,7,101,18]
    Output: 2 5 7 18
    Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
    Example 2:

    Input: nums = [0,1,0,3,2,3]
    Output: 0 1 2 3
    Example 3:

    Input: nums = [7,7,7,7,7,7,7]
    Output: 7

    Approach-> 1.In order to print the LIS, we maintain a separate array along with a dp array (say hash).

         2. Whenever we update our dp[i] value in the inner loop, we know that for index i, the previous index is prev_index. Therefore we simply store prev_index to hash[ i ]. In this way, we will have a way to trace back the LIS.

        3. Whenever we have computed the entire dp array and we find the maximum value in it. We store that maximum value’s index in a variable ( say last_index). Now with this last_index, and the hash array we can trace back the LIS elements.
        4. atlast, we reverse the answer
*/

#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n)
{
    int ans = -1;
    int lastIndex = -1;
    vector<int> dp(n, 1);
    vector<int> hash(n, 1);
    for (int i = 0; i <= n - 1; i++)
    {
        hash[i] = i; // initializing with current index
        for (int prev_index = 0; prev_index < i; prev_index++)
        {
            if (arr[prev_index] < arr[i] && 1 + dp[prev_index] > dp[i])
            {
                dp[i] = 1 + dp[prev_index];
                hash[i] = prev_index; // trace back the LIS so that from which ind the curr ind ele is greater.
            }
        }
        if (dp[i] > ans)
        {
            ans = dp[i];
            lastIndex = i;
        }
    }

    vector<int> temp;               // for storage of LIS
    temp.push_back(arr[lastIndex]); // pushing last ele of LIS

    while (hash[lastIndex] != lastIndex)
    { // till not reach the initialization value
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }

    // reverse the array
    reverse(temp.begin(), temp.end());
    cout << "The subsequence elements are ";
    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }
    cout << endl;
    return ans;
}
int main()
{
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    longestIncreasingSubsequence(arr, n);
    return 0;
}

// Output:
// The subsequence elements are 2 5 7 101