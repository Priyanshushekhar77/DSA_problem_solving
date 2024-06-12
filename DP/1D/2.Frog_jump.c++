/*
    Q. Dynamic Programming : Frog Jump (DP 3)
    Practice : https://practice.geeksforgeeks.org/problems/geek-jump/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geek-jump
    Geek Jump
    Geek wants to climb from the 0th stair to the (n-1)th stair. At a time the Geek can climb either one or two steps. A height[N] array is also given. Whenever the geek jumps from stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. return the minimum energy that can be used by the Geek to jump from stair 0 to stair N-1.

    Example:
    Input:
    n = 4
    height = {10 20 30 10}
    Output:
    20
    Explanation:
    Geek jump from 1st to 2nd stair(|20-10| = 10 energy lost).
    Then a jump from the 2nd to the last stair(|10-20| = 10 energy lost).
    so, total energy lost is 20 which is the minimum.
*/
#include <bits/stdc++.h>
using namespace std;
int solve(const vector<int> &arr, int ind)
{
    if (ind == 0)
        return 0;
    int step1 = solve(arr, ind - 1) + abs(arr[ind] - arr[ind - 1]);
    int step2 = INT_MAX;
    if (ind > 1)
    {
        step2 = solve(arr, ind - 2) + abs(arr[ind] - arr[ind - 2]);
    }
    return min(step1, step2);
}
int minimumEnergy(const vector<int> &arr, int n)
{
    return solve(arr, n - 1);
}
// Time complexity is O(2(pow(n))) becz each call for two steps
// The space complexity is O(n) due to the maximum depth of the recursion stack.
// MEMORIZATION
int solve(const vector<int> &arr, int ind, vector<int> &dp)
{
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];

    int step1 = abs(arr[ind] - arr[ind - 1]) + solve(arr, ind - 1, dp);
    int step2 = INT_MAX;
    if (ind > 1)
    {
        step2 = solve(arr, ind - 2) + abs(arr[ind] - arr[ind - 2]);
    }
    return dp[ind] = min(step1, step2);
}
int minimumEnergy(const vector<int> &arr, int n)
{
    vector<int> dp(n, -1);
    return solve(arr, n - 1, dp);
}
// Each state is computed once, resulting in O(n) time complexity.
// Space complexity is O(n) for the memoization array and O(n) for the recursion stack.

// TABULATION
int minimumEnergy(const vector<int> &arr, int n)
{
    if (n == 1)
        return 0;
    vector<int> dp(n);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int step1 = dp[i - 1] + abs(arr[i] - arr[i - 1]);
        int step2 = INT_MAX;
        if (i > 1)
        {
            step2 = dp[i - 2] + abs(arr[i] - arr[i - 2]);
        }
        dp[i] = min(step1, step2);
    }
    return dp[n - 1];
}
// Iterates through the array once, so O(n) time complexity and O(n) space.

// SPACE OPTMZ
int minimumEnergy(const vector<int> &arr, int ind)
{
    if (ind == 1)
        return 0;
    int prev2 = 0, prev = abs(arr[1] - arr[0]);
    for (int i = 2; i < ind; i++)
    {
        int step1 = prev + abs(arr[i] - arr[i - 1]);
        int step2 = prev2 + abs(arr[i] - arr[i - 2]);
        prev2 = prev;
        prev = min(step2, step1);
    }
    return prev;
}

// Space Optimization:
// O(n) time,
// O(1) space

int main()
{
    int n = 4;
    vector<int> height = {10, 20, 30, 10};
    cout << minimumEnergy(height, n) << endl;
    return 0;
}