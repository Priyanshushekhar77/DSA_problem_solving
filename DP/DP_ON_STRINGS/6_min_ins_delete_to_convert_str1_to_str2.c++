/*
    Q. Minimum Insertions/Deletions to Convert String | (DP- 30)

    Practice : https://leetcode.com/problems/delete-operation-for-two-strings/description/

    Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

    In one step, you can delete exactly one character in either string.

    Example 1:

    Input: word1 = "sea", word2 = "eat"
    Output: 2
    Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

    Example 2:

    Input: word1 = "leetcode", word2 = "etco"
    Output: 4
*/
// algo=> take string s1 and s2, 2.find longest subsequence of both, 3.return (size of s1- longest subsequence) + (size of s2 - longest subsequence)

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the length of the Longest Common Subsequence
int lcs(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    // base case-> Initialize the first row and first column to 0
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
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
            }
        }
    }
    return dp[n][m];
}

// Function to calculate the minimum operations required to convert str1 to str2
int canYouMake(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    // Calculate the length of the longest common subsequence between str1 and str2
    int k = lcs(str1, str2);
    // Calculate the minimum operations required to convert str1 to str2
    return (n - k) + (m - k);
}

int main()
{
    string str1 = "abcd";
    string str2 = "anc";
    cout << "The Minimum operations required to convert str1 to str2: " << canYouMake(str1, str2);
    return 0;
}
