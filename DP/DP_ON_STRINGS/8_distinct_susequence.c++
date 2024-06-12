/*
    Q. Distinct Subsequences| (DP-32)

    Practice : https://leetcode.com/problems/distinct-subsequences/description/

    Given two strings s and t, return the number of distinct subsequences of s which equals t.

    The test cases are generated so that the answer fits on a 32-bit signed integer.

    Example 1:

    Input: s = "rabbbit", t = "rabbit"
    Output: 3
    Explanation:
    As shown below, there are 3 ways you can generate "rabbit" from s.
    rabbbit
    rabbbit
    rabbbit
    Example 2:

    Input: s = "babgbag", t = "bag"
    Output: 5
    Explanation:
    As shown below, there are 5 ways you can generate "bag" from s.
    babgbag
    babgbag
    babgbag
    babgbag
    babgbag

    approach->
    1. if(S1[i]==S2[j]), call f(i-1,j-1) and f(i-1,j).
    2. if(S1[i]!=S2[j]), call f(i-1,j).
    Step 3:  Return the sum of choices

     As we have to return the total count, we will return the sum of f(i-1,j-1) and f(i-1,j) in case 1 and simply return f(i-1,j) in case 2.

Base Cases:
We are reducing i and j in our recursive relation, there can be two possibilities, either i becomes -1 or j becomes -1.
if j<0, it means we have matched all characters of S2 with characters of S1, so we return 1.
if i<0, it means we have checked all characters of S1 but we are not able to match all characters of S2, therefore we return 0.
*/

// MEMORIZATION

#include <bits/stdc++.h>
using namespace std;

const int prime = 1e9 + 7;

// Function to count the number of distinct subsequences of s2 in s1
int countUtil(string s1, string s2, int ind1, int ind2, vector<vector<int>> &dp)
{
    // If s2 has been completely matched, return 1 (found a valid subsequence)
    if (ind2 < 0)
        return 1;

    // If s1 has been completely traversed but s2 hasn't, return 0
    if (ind1 < 0)
        return 0;

    // If the result for this state has already been calculated, return it
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    int result = 0;

    // If the characters match, consider two options: either leave one character in s1 and s2
    // or leave one character in s1 and continue matching s2
    if (s1[ind1] == s2[ind2])
    {
        int leaveOne = countUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
        int stay = countUtil(s1, s2, ind1 - 1, ind2, dp);

        result = (leaveOne + stay) % prime;
    }
    else
    {
        // If characters don't match, just leave one character in s1 and continue matching s2
        result = countUtil(s1, s2, ind1 - 1, ind2, dp);
    }

    // Store the result and return it
    dp[ind1][ind2] = result;
    return result;
}

// Function to count the number of distinct subsequences of s2 in s1
int subsequenceCounting(string &s1, string &s2, int lt, int ls)
{
    vector<vector<int>> dp(lt, vector<int>(ls, -1));
    return countUtil(s1, s2, lt - 1, ls - 1, dp);
}

int main()
{
    string s1 = "babgbag";
    string s2 = "bag";

    // Call the subsequenceCounting function and print the result
    cout << "The Count of Distinct Subsequences is " << subsequenceCounting(s1, s2, s1.size(), s2.size());
    return 0;
}

// TABULATION

#include <bits/stdc++.h>
using namespace std;

const int prime = 1e9 + 7;

// Function to count the number of distinct subsequences of s2 in s1
int subsequenceCounting(string &s1, string &s2, int n, int m)
{
    // Create a 2D DP array to store the count of distinct subsequences
    //1 base indexing
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Initialize the first row: empty string s2 can be matched with any non-empty s1 in one way
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    // Initialize the first column: s1 can't match any non-empty s2
    for (int i = 1; i <= m; i++)
    {
        dp[0][i] = 0;
    }

    // Fill in the DP array
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                // If the characters match, we have two options:
                // 1. Match the current characters and move diagonally (dp[i-1][j-1])
                // 2. Leave the current character in s1 and match s2 with the previous characters (dp[i-1][j])
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % prime;
            }
            else
            {
                // If the characters don't match, we can only leave the current character in s1
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // The value at dp[n][m] contains the count of distinct subsequences
    return dp[n][m];
}

int main()
{
    string s1 = "babgbag";
    string s2 = "bag";

    // Call the subsequenceCounting function and print the result
    cout << "The Count of Distinct Subsequences is " << subsequenceCounting(s1, s2, s1.size(), s2.size());
    return 0;
}
