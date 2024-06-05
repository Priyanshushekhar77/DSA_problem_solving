//   Problem Statement: Given a number of stairs. Starting from the 0th stair we need to climb to the “Nth” stair. At a time we can climb either one or two steps. We need to return the total number of distinct ways to reach from 0th to Nth stair.
//     There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does matter).
//     Input:
//     n = 4
//     Output: 5
//     Explanation:
//     You can reach 4th stair in 5 ways.
//     Way 1: Climb 2 stairs at a time.
//     Way 2: Climb 1 stair at a time.
//     Way 3: Climb 2 stairs, then 1 stair
//     and then 1 stair.
//     Way 4: Climb 1 stair, then 2 stairs
//     then 1 stair.
//     Way 5: Climb 1 stair, then 1 stair and
//     then 2 stairs.

#include <iostream>
#include <vector>
using namespace std;
// RECURSION
int count(int ind)
{
    if (ind == 0)
        return 1;
    if (ind < 0)
        return 0;
    return count(ind - 1) + count(ind - 2);
}
int climbStairs(int n)
{
    return count(n);
}
// Time complexity is O(2(pow(n))) becz each call for two steps
// The space complexity is O(n) due to the maximum depth of the recursion stack.
// MEMORIZATION
int count(int ind, vector<int> &dp)
{
    if (ind == 0)
        return 1;
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    return dp[ind] = count(ind - 1, dp) + count(ind - 2, dp);
}
int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);
    return count(n, dp);
}
// Each state is computed once, resulting in O(n) time complexity.
// Space complexity is O(n) for the memoization array and O(n) for the recursion stack.

// TABULATION
int climbstairs(int n)
{
    if (n == 0)
        return 1;
    vector<int> dp(n + 1, 0);
    // bottom to top approach
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
// Iterates through the array once, so O(n) time complexity and O(n) space.

// SPACE OPTMZ
int climbStairs(int n)
{
    if (n < 2)
        return 1;
    int curr = 0, prev1 = 1, prev2 = 1;
    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}
// Space Optimization:
// O(n) time,
// O(1) space
int main()
{
    int n = 4;
    cout << climbStairs(n) << endl;
    return 0;
}