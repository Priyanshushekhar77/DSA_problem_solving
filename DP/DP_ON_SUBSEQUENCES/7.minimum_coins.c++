/*
    Q. Minimum Coins (DP – 20)

    Practice : https://leetcode.com/problems/coin-change/description/

    You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

    Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

    You may assume that you have an infinite number of each kind of coin.

    Example 1:

    Input: coins = [1,2,5], amount = 11
    Output: 3
    Explanation: 11 = 5 + 5 + 1
    Example 2:

    Input: coins = [2], amount = 3
    Output: -1
    Example 3:

    Input: coins = [1], amount = 0
    Output: 0
*/

// MEMORIZATION

#include <bits/stdc++.h> // Include necessary libraries
using namespace std;

int minimumElementsUtil(vector<int> &arr, int ind, int T, vector<vector<int>> &dp)
{

    // Base case: If we're at the first element
    if (ind == 0)
    {
        // Check if the target sum is divisible by the first element
        if (T % arr[0] == 0)
            return T / arr[0]; // If yes, return the quotient as the answer
        else
            return 1e9; // Otherwise, return a very large value to indicate it's not possible
    }
    if(T==0) return 1;//optional

    // If the result for this index and target sum is already calculated, return it
    if (dp[ind][T] != -1)
        return dp[ind][T];

    // Calculate the minimum elements needed without taking the current element
    int notTaken = 0 + minimumElementsUtil(arr, ind - 1, T, dp);

    // Calculate the minimum elements needed by taking the current element
    int taken = 1e9; // Initialize 'taken' to a very large value
    if (arr[ind] <= T)
        taken = 1 + minimumElementsUtil(arr, ind, T - arr[ind], dp);

    // Store the minimum of 'notTaken' and 'taken' in the DP array and return it
    return dp[ind][T] = min(notTaken, taken);
}

// Function to find the minimum number of elements needed to form the target sum
int minimumElements(vector<int> &arr, int T)
{

    int n = arr.size();

    // Create a DP (Dynamic Programming) table with n rows and T+1 columns and initialize it with -1
    vector<vector<int>> dp(n, vector<int>(T + 1, -1));

    // Call the utility function to calculate the answer
    int ans = minimumElementsUtil(arr, n - 1, T, dp);

    // If 'ans' is still very large, it means it's not possible to form the target sum
    if (ans >= 1e9)
        return -1;
    return ans; // Return the minimum number of elements needed
}

int main()
{

    vector<int> arr = {1, 2, 5};
    int T = 11;

    cout << "The minimum number of coins required to form the target sum is " << minimumElements(arr, T);

    return 0; // Return 0 to indicate successful program execution
}

// Time Complexity: O(N*T)

// Reason: There are N*T states therefore at max ‘N*T’ new problems will be solved.

// Space Complexity: O(N*T) + O(N)
// Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*T)).

//Tabulation
// #include <bits/stdc++.h>
// using namespace std;

// // Function to find the minimum number of elements needed to form the target sum
// int minimumElements(vector<int> &arr, int T)
// {
//     int n = arr.size();

//     // Create a 2D DP (Dynamic Programming) table with n rows and T+1 columns
//     vector<vector<int>> dp(n, vector<int>(T + 1, 0));

//     // Initialize the first row of the DP table
//     for (int target = 0; target <= T; target++)
//     {
//         if (target % arr[0] == 0)
//             dp[0][target] = target / arr[0];
//         else
//             dp[0][target] = 1e9; // Set it to a very large value if not possible
//     }

//     // Fill the DP table using a bottom-up approach
//     for (int ind = 1; ind < n; ind++)
//     {
//         for (int target = 0; target <= T; target++)
//         {
//             // Calculate the minimum elements needed without taking the current element
//             int notTake = dp[ind - 1][target];

//             // Calculate the minimum elements needed by taking the current element
//             int take = 1e9; // Initialize 'take' to a very large value
//             if (arr[ind] <= target)
//                 take = 1 + dp[ind][target - arr[ind]];

//             // Store the minimum of 'notTake' and 'take' in the DP table
//             dp[ind][target] = min(notTake, take);
//         }
//     }

//     // The answer is in the bottom-right cell of the DP table
//     int ans = dp[n - 1][T];

//     // If 'ans' is still very large, it means it's not possible to form the target sum
//     if (ans >= 1e9)
//         return -1;

//     return ans; // Return the minimum number of elements needed
// }

// int main()
// {
//     vector<int> arr = {1, 2, 3};
//     int T = 7;

//     // Call the function to find the minimum number of elements needed
//     int result = minimumElements(arr, T);

//     // Output the result
//     cout << "The minimum number of coins required to form the target sum is " << result << endl;

//     return 0; // Return 0 to indicate successful program execution
// }
