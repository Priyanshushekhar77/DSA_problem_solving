/*
    Q. Longest Common Substring | (DP – 27)

    Practice : https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1

    Given two strings. The task is to find the length of the longest common substring.

    Example 1:

    Input: S1 = "ABCDGH", S2 = "ACDGHR", n = 6, m = 6
    Output: 4
    Explanation: The longest common substring
    is "CDGH" which has length 4.
    Example 2:

    Input: S1 = "ABC", S2 "ACB", n = 3, m = 3
    Output: 1
    Explanation: The longest common substrings
    are "A", "B", "C" all having length 1.
*/
// MEMORIZATION

#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the Longest Common Substring (LCS)
int lcs(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();

    // Create a 2D DP table with dimensions (n+1) x (m+1)
    //(here shifting of one ind to right side have to be do to handle base case)
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // base case handled with 0;

    int ans = 0; // Initialize the answer variable

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                int val = 1 + dp[i - 1][j - 1]; // Characters match, increment substring length
                dp[i][j] = val;                 // Update the DP table
                ans = max(ans, val);            // Update the maximum substring length found so far
            }
            else
                dp[i][j] = 0; // Characters don't match, substring length becomes 0
        }
    }

    return ans; // Return the length of the Longest Common Substring
}

int main()
{
    string s1 = "abcjklp";
    string s2 = "acjkp";

    // Call the function to find and output the length of the Longest Common Substring
    cout << "The Length of Longest Common Substring is " << lcs(s1, s2) << endl;

    return 0; // Return 0 to indicate successful program execution
}
