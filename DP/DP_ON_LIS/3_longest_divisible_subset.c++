/*
    Q. Longest Divisible Subset | (DP-44)

    Practice : https://leetcode.com/problems/largest-divisible-subset/

    Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

    answer[i] % answer[j] == 0, or
    answer[j] % answer[i] == 0
    If there are multiple solutions, return any of them.

    Example 1:

    Input: nums = [1,2,3]
    Output: [1,2]
    Explanation: [1,3] is also accepted.
    Example 2:

    Input: nums = [1,2,4,8]
    Output: [1,2,4,8]

Approach

The algorithm approach is stated as follows:

1.  First of all sort the array,
2.  Then find the longest divisible subsequence of the array.
3.  In order to find the longest divisible subsequence, we will follow the algorithm used to find the longest increasing subsequence discussed
4.  The distinguishing factor between longest increasing subsequence and longest divisible subsequence is that we used to insert the element if arr[i] > arr[prev] but here we will insert the element when arr[i] % arr[prev] == 0.
At last return the hash array as the answer.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the longest divisible subset
vector<int> divisibleSet(vector<int> &arr)
{
    int n = arr.size();
    int ans = -1;
    int lastIndex = -1;
    // Sort the array in ascending order
    sort(arr.begin(), arr.end());
    vector<int> dp(n, 1);   // dp[i] stores the length of the divisible subset ending at arr[i]
    vector<int> hash(n, 1); // hash[i] stores the previous index in the divisible subset ending at arr[i]

    for (int i = 0; i < n; i++)
    {
        hash[i] = i; // Initialize with the current index
        for (int prev_index = 0; prev_index < i; prev_index++)
        {
            if (arr[i] % arr[prev_index] == 0 && 1 + dp[prev_index] > dp[i])
            {
                dp[i] = 1 + dp[prev_index];
                hash[i] = prev_index;
            }
        }
        if (dp[i] > ans)
        {
            ans = dp[i];
            lastIndex = i;
        }
    }

    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    // Reconstruct the divisible subset using the hash table
    while (hash[lastIndex] != lastIndex)
    { // till not reach the initialization value
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }
    // Reverse the array to get the correct order
    reverse(temp.begin(), temp.end());
    return temp;
}
int main()
{
    vector<int> arr = {1, 16, 7, 8, 4};
    vector<int> ans = divisibleSet(arr);
    cout << "The longest divisible subset elements are: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
// Output:
//  The longest divisible subset elements are: 1 4 8 16

/*Time Complexity: O(N*N)
Reason: There are two nested loops.
Space Complexity: O(N)
Reason: We are only using two rows of size n.
*/