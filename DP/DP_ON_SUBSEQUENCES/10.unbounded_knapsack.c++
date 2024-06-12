/*
    Q. Unbounded Knapsack (DP-23)

    Practice : https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=knapsack-with-duplicate-items

    Given a set of N items, each with a weight and a value, represented by the array w[] and val[] respectively. Also, a knapsack with weight limit W.
    The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
    Note: Each item can be taken any number of times.

    Example 1:
    
    Input: N = 2, W = 3
    val[] = {1, 1}
    wt[] = {2, 1}
    Output: 3
    Explanation: 
    1.Pick the 2nd element thrice.
    2.Total profit = 1 + 1 + 1 = 3. Also the total 
      weight = 1 + 1 + 1  = 3 which is <= W.
    
    Example 2:
    
    Input: N = 4, W = 8
    val[] = {1, 4, 5, 7}
    wt[] = {1, 3, 4, 5}
    Output: 11
    Explanation: The optimal choice is to 
    pick the 2nd and 4th element.
*/
//MEMORIZATION

#include <bits/stdc++.h>
using namespace std;

// Function to solve the unbounded knapsack problem
int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector<int>>& dp) {
    // Base case: if we're at the first item
    if (ind == 0) {
        // Calculate and return the maximum value for the given weight limit
        return (W / wt[0]) * val[0];
    }
    
    // If the result for this index and weight limit is already calculated, return it
    if (dp[ind][W] != -1)
        return dp[ind][W];
        
    // Calculate the maximum value without taking the current item
    int notTaken = 0 + knapsackUtil(wt, val, ind - 1, W, dp);
    
    // Calculate the maximum value by taking the current item
    int taken = INT_MIN;
    if (wt[ind] <= W)
        taken = val[ind] + knapsackUtil(wt, val, ind, W - wt[ind], dp);
        
    // Store the maximum value in the DP table and return it
    return dp[ind][W] = max(notTaken, taken);
}

// Function to solve the unbounded knapsack problem
int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
    vector<vector<int>> dp(n, vector<int>(W + 1, -1)); // Create a DP table
    return knapsackUtil(wt, val, n - 1, W, dp);
}

int main() {
    vector<int> wt = {2, 4, 6}; // Weight of items
    vector<int> val = {5, 11, 13}; // Value of items
    int W = 10; // Weight capacity of the knapsack
    int n = wt.size(); // Number of items
    cout << "The Maximum value of items the thief can steal is " << unboundedKnapsack(n, W, val, wt) << endl;

    return 0; 
}
// Time Complexity: O(N*W)
// Reason: There are N*W states therefore at max ‘N*W’ new problems will be solved.

// Space Complexity: O(N*W) + O(N)
// Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*W)).

//TABULATION


#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
    vector<vector<int>> dp(n, vector<int>(W + 1, 0)); // Create a DP table

    // Base Condition
    for (int i = wt[0]; i <= W; i++) {
        dp[0][i] = (i / wt[0]) * val[0]; // Calculate the maximum value for the first item
    }

    for (int ind = 1; ind < n; ind++) {
        for (int cap = 0; cap <= W; cap++) {
            int notTaken = 0 + dp[ind - 1][cap]; // Maximum value without taking the current item

            int taken = INT_MIN;
            if (wt[ind] <= cap)
                taken = val[ind] + dp[ind][cap - wt[ind]]; // Maximum value by taking the current item

            dp[ind][cap] = max(notTaken, taken); // Store the maximum value in the DP table
        }
    }

    return dp[n - 1][W]; // Return the maximum value considering all items and the knapsack capacity
}


