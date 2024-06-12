/*
    Q. Count Partitions with Given Difference (DP – 18)
    Practice : https://practice.geeksforgeeks.org/problems/partitions-with-given-difference/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=partitions-with-given-difference

    Given an array arr, partition it into two subsets(possibly empty) such that their union is the original array. Let the sum of the element of these two subsets be S1 and S2.

    Given a difference d, count the number of partitions in which S1 is greater than or equal to S2 and the difference S1 and S2 is equal to d. since the answer may be large return it modulo 109 + 7.

    Example 1:

    Input:
    n = 4, d = 3
    arr[] =  { 5, 2, 6, 4}
    Output:
    1
    Explanation:
    There is only one possible partition of this array. Partition : {6, 4}, {5, 2}. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3.
    Example 2:

    Input:
    n = 4, d = 0 arr[] = {1, 1, 1, 1} Output: 6

ALGO-> S1-S2=D => (Totalsum - S2) - S2 = D => S2=(Totalsum - D) / 2;
*/

#include <bits/stdc++.h>
using namespace std;
int mod = (int)1e9 + 7;
int countPartitionsUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    // Base case if 0 have to be count along
    if (ind == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0 || target == arr[0])
            return 1;
        return 0;
    }
    if (dp[ind][target] != -1)
        return dp[ind][target];

    int notTaken = countPartitionsUtil(ind - 1, target, arr, dp);
    int taken = 0;
    if (arr[ind] <= target)
        taken = countPartitionsUtil(ind - 1, target - arr[ind], arr, dp);
    return dp[ind][target] = (notTaken + taken) % mod;
}

int countPartitions(int d, vector<int> &arr)
{
    int n = arr.size();
    int totSum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        totSum += arr[i];
    }
    // Checking for edge cases
    if (totSum - d < 0)
        return 0;
    if ((totSum - d) % 2 == 1)
        return 0;

    int s2 = (totSum - d) / 2;
    // Here se becomes the target
    vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));
    return countPartitionsUtil(n - 1, s2, arr, dp);
}
int main()
{
    vector<int> arr = {5, 2, 6, 4};
    int d = 3;
    cout << "The number of subsets found are " << countPartitions(d, arr);
}

// TABULATION
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
    if (num[0] == 0)
        dp[0][0] = 2; // 2 cases -pick and not pick
    else
        dp[0][0] = 1; // if num[0] is not zero
    if (num[0] != 0 && num[0] <= tar)
        dp[0][num[0]] = 1;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= tar; target++)
        {

            int notTaken = dp[ind - 1][target];

            int taken = 0;
            if (num[ind] <= target)
                taken = dp[ind - 1][target - num[ind]];

            dp[ind][target] = (notTaken + taken) % mod;
        }
    }
    return dp[n - 1][tar];
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int totSum = 0;
    for (int i = 0; i < n; i++)
    {
        totSum += arr[i];
    }
    // Checking for edge cases
    if (totSum - d < 0 || (totSum - d) % 2)
        return 0; //-ve or odd tan return 0;
    return findWays(arr, (totSum - d) / 2);
}