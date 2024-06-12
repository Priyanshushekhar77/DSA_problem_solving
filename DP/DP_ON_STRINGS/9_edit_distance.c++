/*
    Q. Edit Distance | (DP-33)

    Practice : https://leetcode.com/problems/edit-distance/description/

    Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

    You have the following three operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character

    Example 1:

    Input: word1 = "horse", word2 = "ros"
    Output: 3
    Explanation:
    horse -> rorse (replace 'h' with 'r')
    rorse -> rose (remove 'r')
    rose -> ros (remove 'e')

    Example 2:

    Input: word1 = "intention", word2 = "execution"
    Output: 5
    Explanation:
    intention -> inention (remove 't')
    inention -> enention (replace 'i' with 'e')
    enention -> exention (replace 'n' with 'x')
    exention -> exection (replace 'n' with 'c')
    exection -> execution (insert 'u')

    approach->

    To summarise, these are the three choices we have in case characters don’t match:
1. return 1+f(i-1,j) // Insertion of character.
2. return 1+f(i,j-1) // Deletion of character.
3. return 1+f(i-1,j-1) // Replacement of character.
Step 4.  Return the minimum of all choices.
As we have to return the minimum number of operations, we will return the minimum of all operations.

Base Cases:
We are reducing i and j in our recursive relation, there can be two possibilities, either i becomes -1 or j becomes -1., i,e we exhaust either S1 or S2 respectively.
*/

// MEMORIZATION

#include <bits/stdc++.h>
using namespace std;
// Function to calculate the edit distance between two strings
int editDistanceUtil(string &S1, string &S2, int i, int j, vector<vector<int>> &dp)
{
    // Base cases
    if (i < 0)
        return j + 1; // remaining char of string s2 is considered as insertion
    if (j < 0)
        return i + 1; // remaining char of string s1 is considered as deletion

    // If the result for this state has already been calculated, return it
    if (dp[i][j] != -1)
        return dp[i][j];

    // If the characters at the current positions match,than no operation is needed
    if (S1[i] == S2[j])
        return dp[i][j] = 0 + editDistanceUtil(S1, S2, i - 1, j - 1, dp);

    // Minimum of three choices:
    // 1. Replace the character at S1[i] with the character at S2[j]
    // 2. Delete the character at S1[i]
    // 3. Insert the character at S2[j] into S1
    else
        return dp[i][j] = 1 + min(editDistanceUtil(S1, S2, i - 1, j - 1, dp),
                                  min(editDistanceUtil(S1, S2, i - 1, j, dp),
                                      editDistanceUtil(S1, S2, i, j - 1, dp)));
}

// Function to calculate the minimum number of operations required to transform S1 into S2
int editDistance(string &S1, string &S2)
{
    int n = S1.size();
    int m = S2.size();
    // Create a DP table to memoize results
    vector<vector<int>> dp(n, vector<int>(m, -1));
    // Call the utility function with the last indices of both strings
    return editDistanceUtil(S1, S2, n - 1, m - 1, dp);
}
int main()
{
    string s1 = "horse";
    string s2 = "ros";
    // Call the editDistance function and print the result
    cout << "The minimum number of operations required is: " << editDistance(s1, s2);
    return 0;
}

// Tabulation

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the edit distance between two strings
int editDistance(string &S1, string &S2)
{
    int n = S1.size();
    int m = S2.size();

    // Create a DP table to store edit distances
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // base case a/c memorization
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = j;
    }
    // Fill in the DP table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (S1[i - 1] == S2[j - 1])
            {
                // If the characters match, no additional cost
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                // Minimum of three choices:
                // 1. Replace the character at S1[i-1] with S2[j-1]
                // 2. Delete the character at S1[i-1]
                // 3. Insert the character at S2[j-1] into S1
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }
    // The value at dp[n][m] contains the edit distance
    return dp[n][m];
}

int main()
{
    string s1 = "horse";
    string s2 = "ros";
    // Call the editDistance function and print the result
    cout << "The minimum number of operations required is: " << editDistance(s1, s2);
    return 0;
}
