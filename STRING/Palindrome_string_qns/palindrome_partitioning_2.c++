/*
    Q. Palindrome Partitioning – II | Front Partition : DP 53

    Practice : https://leetcode.com/problems/palindrome-partitioning-ii/

    Given a string s, partition s such that every substring of the partition is a palindrome.

    Return the minimum cuts needed for a palindrome partitioning of s.

    Example 1:

    Input: s = "aab"
    Output: 1
    Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

    Example 2:

    Input: s = "a"
    Output: 0
    Example 3:
    Input: s = "ab"
    Output: 1

    Approach->
       1. Convert the problem to a recursive function marked by the pointer i.
       2.Use a loop to check all possible partitions of the string and calculate the number of partitions.
       3.Return the minimum number of partitions counted.
      4.Base case: When the index i will be equal to the size of the string(i.e. i == n), we can say there are no more characters left to be partitioned. So, this is the base case and in this case, the function will return 0.
*/

// Memoization -> maximum partition of any string to make palindromic is divided into (n-1) palindromic substrings.

#include <bits/stdc++.h>
using namespace std;
// Function to check if a substring is a palindrome.
bool isPalindrome(int i, int j, string &s)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int minPartitions(int ind, int n, string &str, vector<int> &dp)
{
    // Base case: If we've reached the end of the string.
    if (ind == n)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];
    int minCost = INT_MAX;
    // Consider all possible substrings starting from the current index.
    for (int j = ind; j < n; j++)
    {
        if (isPalindrome(ind, j, str))
        {
            // If the substring is a palindrome, calculate the cost and minimize it.
            int cost = 1 + minPartitions(j + 1, n, str, dp);
            minCost = min(minCost, cost);
        }
    }
    return dp[ind] = minCost;
}

// Main function to find the minimum number of partitions for palindrome partitioning.
int palindromePartitioning(string str)
{
    int n = str.size();
    vector<int> dp(n, -1);
    return minPartitions(0, n, str, dp) - 1; // because we have to ignore the last partition
}
int main()
{
    string str = "BABABCBADCEDE";
    int partitions = palindromePartitioning(str);
    cout << "The minimum number of partitions: " << partitions << "\n";
    return 0;
}

/*tabulation
1. First of all, we handle the base case. If (i == n) we return 0. To cover this case we can initialize the entire dp array with 0.
Here, as we are checking dp[j+1]  every time, the function will give a runtime error if j = n-1. To avoid this, we will take the array size as n+1 instead of n.
2. Next, memoization is a top-down approach, whereas tabulation is bottom-up. Our changing parameter i will change in opposite directions, i.e i will change from n-1→0.
3. Next, we copy down the recursive logic(recurrence) inside the loop.
*/

#include <bits/stdc++.h>
using namespace std;
// Function to check if a substring is a palindrome.
bool isPalindrome(int i, int j, string &s)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
// Function to find the minimum number of partitions for palindrome partitioning.
int palindromePartitioning(string str)
{
    int n = str.size();
    // Create a DP array to store the minimum number of partitions.
    vector<int> dp(n + 1, 0);
    dp[n] = 0; // Initialize the last element to 0. as base case

    // Loop through the string in reverse order.
    for (int i = n - 1; i >= 0; i--)
    {
        int minCost = INT_MAX;
        // Consider all possible substrings starting from the current index.
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(i, j, str))
            {
                // If the substring is a palindrome, calculate the cost and minimize it.
                int cost = 1 + dp[j + 1];
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }
    // Subtract 1 becz ignore last partition
    return dp[0] - 1;
}
