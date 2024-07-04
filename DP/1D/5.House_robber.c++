
// Q. Dynamic Programming: House Robber (DP 6)
// Practice : https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=stickler-theif-
// Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i]amount of money present in it.
// n = 6
// a[] = {5,5,10,100,10,5}
// Output: 110
// Explanation: 5+100+5=110

#include <bits/stdc++.h>
using namespace std;

// memoziation
 int solve(vector<int>& nums,int ind,vector<int>& dp){
    if(ind==0) return nums[0];
    if(ind<0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int take=nums[ind];
    if(ind>1){
        take+=solve(nums,ind-2,dp);
    }
    int nottake=0+solve(nums,ind-1,dp);
    return dp[ind]=max(take,nottake);
}


    int rob(vector<int>& arr) {
       int n = arr.size();
    if (n == 0) return 0;
    if (n == 1) return arr[0];

    vector<int> dp1(n, -1); // dp array for arr1
    vector<int> dp2(n, -1); // dp array for arr2

    vector<int> arr1(arr.begin(), arr.end() - 1); // arr1 excludes the last element
    vector<int> arr2(arr.begin() + 1, arr.end()); // arr2 excludes the first element

    int ans1 = solve(arr1, arr1.size() - 1, dp1); // solve for arr1
    int ans2 = solve(arr2, arr2.size() - 1, dp2); // solve for arr2

    return max(ans1, ans2);
    }