
// Q. Dynamic Programming: House Robber (DP 6)
// Practice : https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=stickler-theif-
// Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i]amount of money present in it.
// n = 6
// a[] = {5,5,10,100,10,5}
// Output: 110
// Explanation: 5+100+5=110

#include <bits/stdc++.h>
using namespace std;

// Tabulation
long long solve(vector<int> &arr1, int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = arr1[0];
    for (int i = 1; i < n; i++)
    {
        int pick = arr1[i];
        if (i > 1)
        {
            pick += dp[i - 2];
        }
        int notpick = dp[i - 1];
        dp[i] = max(pick, notpick);
    }
    return dp[n - 1];
}

long long solve(vector<int> &arr2, int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = arr2[0];
    for (int i = 1; i < n; i++)
    {
        int pick = arr2[i];
        if (i > 1)
        {
            pick += dp[i - 2];
        }
        int notpick = dp[i - 1];
        dp[i] = max(pick, notpick);
    }
    return dp[n - 1];
}
long long int robStreet(int n, vector<int> &arr)
{
    vector<int> arr1;
    vector<int> arr2;

    if (n == 1)
        return arr[0];

    for (int i = 0; i < n; i++)
    {

        if (i != 0)
            arr1.push_back(arr[i]);
        if (i != n - 1)
            arr2.push_back(arr[i]);
    }
    long long int ans1 = solve(arr1, n);
    long long int ans2 = solve(arr2, n);

    return max(ans1, ans2);
}
int main()
{

    vector<int> arr{1, 5, 1, 2, 6};
    int n = arr.size();
    cout << robStreet(n, arr);
}