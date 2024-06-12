/*
    Q. Minimum insertions to make string palindrome | DP-29

    Practice : https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

    Given a string s. In one step you can insert any character at any index of the string.

    Return the minimum number of steps to make s palindrome.

    A Palindrome String is one that reads the same backward as well as forward.

    Example 1:

    Input: s = "zzazz"
    Output: 0
    Explanation: The string "zzazz" is already palindrome we do not need any insertions.
    Example 2:

    Input: s = "mbadm"
    Output: 2
    Explanation: String can be "mbdadbm" or "mdbabdm".
    Example 3:

    Input: s = "leetcode"
    Output: 5
    Explanation: Inserting 5 characters the string becomes "leetcodocteel".
*/
// algo=>1.take string s, 2.take string t which is reversen of s, 3.find longest subsequence of s and t, 4. return size of string - length of longest subsequence

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the length of the Longest Common Subsequence
int lcs(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // base case -> Initialize the first row and first column to 0
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }

    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
            {
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]); // s1 ka same ind and s2 ka ind-1 than compare or s1 ka ind-1 and s2 ka same ind than compare
            }
        }
    }

    return dp[n][m];
}

// Function to calculate the length of the Longest Palindromic Subsequence
int longestPalindromeSubsequence(string s)
{
    string t = s;
    reverse(s.begin(), s.end());
    return lcs(s, t);
}

// Function to calculate the minimum insertions required to make a string palindrome
int minInsertion(string s)
{
    int n = s.size();
    int k = longestPalindromeSubsequence(s);
    // The minimum insertions required is the difference between the string length and its longest palindromic subsequence length
    return n - k;
}

int main()
{
    string s = "abcaa";
    cout << "The Minimum insertions required to make string palindrome: " << minInsertion(s);
    return 0;
}
