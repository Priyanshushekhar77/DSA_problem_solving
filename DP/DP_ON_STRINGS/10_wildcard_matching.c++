/*
    Q. Wildcard Matching | (DP-34)

    Practice : https://leetcode.com/problems/wildcard-matching/description/

    Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

    '?' Matches any single character.
    '*' Matches any sequence of characters (including the empty sequence).
    The matching should cover the entire input string (not partial).

    Example 1:

    Input: s = "aa", p = "a"
    Output: false
    Explanation: "a" does not match the entire string "aa".
    Example 2:

    Input: s = "aa", p = "*"
    Output: true
    Explanation: '*' matches any sequence.
    Example 3:

    Input: s = "cb", p = "?a"
    Output: false
    Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.


Approach->
(1) When the characters match
if(S1[i]==S2[j]),
If this is true, the characters at i and j match, we can simply move to the next characters of both the strings. So we will just decrement both i and j by 1 and recursively find the answer for the remaining string portions. We return f(i-1,j-1). The following figure makes it clear.

(2) When the characters don’t match
If the characters don’t match, there are three possible scenarios:
S1[i] == ‘?’
S1[i] == ‘*’
S1[i] is some other character
Let us discuss them one by one:

(i) If S1[i] == ‘?’
In this case, we can explicitly match ‘?’ at index i of S1 with the corresponding character at index j of S2. And then recursively call f(i-1,j-1) to check for the remaining string.

(ii) If S1[i] == ‘*’
Call f(i-1,j). i.e replace ‘*’ with nothing and act as if it was not present.
Call f(i,j-1). i.e replace ‘*’ with a single character at index j and make the i pointer to still point at index i. In this, we matched it with a single character (one of the many options that need to be tried) and in the next recursive call, as i still point to ‘*’, we get the exact two recursive calls again.

Step 3: Return logical OR (||) of all the choices

Base Cases:
We are reducing i and j in our recursive relation, there can be two possibilities, either i becomes -1 or j becomes -1., i,e we exhaust either S1 or S2 respectively.

(i) When S1 is exhausted:
When S1 is exhausted (i<0), we know that in order for the strings to match, String S2 should also exhaust simultaneously. If it does, we return true, else we return false.
We can say:

if(i<0 && j<0), return true.
if(i<0 && j>=0), return false.

(ii) When S2 is exhausted:
When S2 is exhausted(j<0) and S1 has not, there is only one pattern that can account for true(matching of strings). It is if S1 is like this “*”,”****”,”***”, i.e: S1 contains only stars. Then we can replace every star with a sequence of length 0 and say that the string match.
If S1 is all-stars, we return true, else return false.
*/

// MEMORIZATION

#include <bits/stdc++.h>
using namespace std;
// Function to check if a substring of S1 contains only '*'
bool isAllStars(string &S1, int i)
{
    for (int j = 0; j <= i; j++)
    {
        if (S1[j] != '*')
            return false;
    }
    return true;
}

// Function to check if S1 matches S2 using wildcard pattern matching
bool wildcardMatchingUtil(string &S1, string &S2, int i, int j, vector<vector<bool>> &dp)
{
    // Base Cases
    if (i < 0 && j < 0)
        return true;
    if (i < 0 && j >= 0)
        return false;
    if (j < 0 && i >= 0)
        return isAllStars(S1, i);

    // If the result for this state has already been calculated, return it
    if (dp[i][j] != -1)
        return dp[i][j];

    // If the characters at the current positions match or S1 has a '?'
    if (S1[i] == S2[j] || S1[i] == '?')
        return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j - 1, dp);
    else
    {
        if (S1[i] == '*')
            // Two options: either '*' represents an empty string or it matches a character in S2
            return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j, dp) || wildcardMatchingUtil(S1, S2, i, j - 1, dp);
        else
            return false;
    }
}
// Main function to check if S1 matches S2 using wildcard pattern matching
bool wildcardMatching(string &S1, string &S2)
{
    int n = S1.size();
    int m = S2.size();
    // Create a DP table to memoize results
    vector<vector<bool>> dp(n, vector<bool>(m, -1));
    return wildcardMatchingUtil(S1, S2, n - 1, m - 1, dp);
}
int main()
{
    string S1 = "ab*cd";
    string S2 = "abdefcd";
    // Call the wildcardMatching function and print the result
    if (wildcardMatching(S1, S2))
        cout << "String S1 and S2 do match";
    else
        cout << "String S1 and S2 do not match";

    return 0;
}

// TABULATION

#include <bits/stdc++.h>
using namespace std;

// Function to check if a substring of S1 contains only '*'
bool isAllStars(string &S1, int i)
{
    // S1 is taken in 1-based indexing
    for (int j = 1; j <= i; j++)
    {
        if (S1[j - 1] != '*')
            return false;
    }
    return true;
}

// Function to perform wildcard pattern matching between S1 and S2
bool wildcardMatching(string &S1, string &S2)
{
    int n = S1.size();
    int m = S2.size();
    // Create a DP table to memoize results
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    // Initialize the first row and column
    dp[0][0] = true;
    for (int j = 1; j <= m; j++)
    {
        dp[0][j] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = isAllStars(S1, i);
    }

    // Fill in the DP table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                if (S1[i - 1] == '*')
                {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }
    }
    // The value at dp[n][m] contains whether S1 matches S2
    return dp[n][m];
}
int main()
{
    string S1 = "ab*cd";
    string S2 = "abdefcd";
    if (wildcardMatching(S1, S2))
        cout << "String S1 and S2 do match";
    else
        cout << "String S1 and S2 do not match";

    return 0;
}
