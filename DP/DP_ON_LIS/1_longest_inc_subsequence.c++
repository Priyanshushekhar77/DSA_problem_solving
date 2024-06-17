/* Q. Longest Increasing Subsequence | (DP-41)

    Practice: https://leetcode.com/problems/longest-increasing-subsequence/description/

    Given an integer array nums, return the length of the longest strictly increasing
    subsequence.

    Example 1:

    Input: nums = [10,9,2,5,3,7,101,18]
    Output: 4
    Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
    Example 2:

    Input: nums = [0,1,0,3,2,3]
    Output: 4

    Approach 1: Using Brute Force
We are given an array arr[]. To find the longest increasing subsequence, the brute force method that comes to our mind is to generate all subsequences and then manually filter the subsequences whose elements come in increasing order and then return the longest such subsequence.

This naive approach will give us the correct answer but to generate all the subsequences, we will require exponential ( 2n ) time. Therefore we will try some other approaches.

Approach 2: Using Dynamic Programming

step1. express in terms of index
       we also need a second parameter called prev_index to decide at every index ‘ind’ whether this array element can be considered in the increasing subsequence or not. Initially, prev_index will be -1 as there is no element present in the subsequence.
step2. explore all possibilities at that index
       At every index, we have two choices based on the pick/non-pick technique as discussed in the“Recursion on Subsequences”.
      A)  Do not consider the current element in the subsequence: In this case, we are not considering the current element in the subsequence, therefore the length of the subsequence will not increase and the prev_index element will remain as it is. Hence we will return 0 + f(ind+1,prev_index) as our answer.

      B) Consider the current element in the subsequence: In this case, we are considering the current element in the subsequence, therefore the length of the subsequence will increase by 1 and the prev_index element will be updated to the current index element.. Hence we will return 1 + f(ind+1,ind) as our answer. Here is a simple catch, when we want to consider the current index element to the subsequence, we need to check that it is greater than the last element of the subsequence so far,i.e the prev_index element.

Step 3:  Return the maximum of the choices
step4.  Base case
       When ind==n,
      It means that we have considered all the elements of the array and there are no more elements left to explore, therefore we return 0.
*/

// memorization

#include <bits/stdc++.h>
using namespace std;
// Function to find the length of the longest increasing subsequence
int getAns(int arr[], int n, int ind, int prev_index, vector<vector<int>> &dp)
{
    // Base condition
    if (ind == n)
        return 0;

    if (dp[ind][prev_index + 1] != -1)
        return dp[ind][prev_index + 1];

    int notTake = 0 + getAns(arr, n, ind + 1, prev_index, dp);

    int take = 0;

    if (prev_index == -1 || arr[ind] > arr[prev_index])
    {
        take = 1 + getAns(arr, n, ind + 1, ind, dp);
    }

    return dp[ind][prev_index + 1] = max(notTake, take);
}

int longestIncreasingSubsequence(int arr[], int n)
{
    // Create a 2D DP array for ind and prev_ind initialized to -1
    vector<vector<int>> dp(n, vector<int>(n + 1, -1)); // becz prev_ind start from -1 to n-1  so we have to shift the ind of 1 towards right side and initalise with size(n+1);
    return getAns(arr, n, 0, -1, dp);
}
int main()
{
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The length of the longest increasing subsequence is " << longestIncreasingSubsequence(arr, n);
    return 0;
}

/* Time Complexity: O(N*N)
Reason: There are N*N states therefore at max ‘N*N’ new problems will be solved.
Space Complexity: O(N*N) + O(N)
*/

// Tabulation
/* To convert the memoization approach to a tabulation one, create a dp array with the same size as done in memoization i.e dp[N][N+1].

1. Now the base case is if(ind==n), we return 0. We can initialize the entire dp array as 0. In this way, we need to write the base case explicitly.
2. The changing parameters in the recursive code are ind and prev_index. We will write them in the opposite direction of memoization.
3. We will set for a loop of ind to range from n-1 to 0.
4. If we look closely at the recursive tree, we will see a pattern that the second parameter, prev_index is always smaller than the first parameter ind. Therefore we will write the for loop for prev_index to start from ind-1 till -1.
5. Next, we write the recursive logic inside the nested loops.
6.We need to keep in that mind that we are storing prev_index in the dp array by making a coordinate shift
7.At last, we will print dp[0][0] as our answer.
*/

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_index = ind - 1; prev_index >= -1; prev_index--)
        {

            int notTake = 0 + dp[ind + 1][prev_index + 1]; // becz of shifying of index we do +1 in prev_ind loop

            int take = 0;

            if (prev_index == -1 || arr[ind] > arr[prev_index])
            {

                take = 1 + dp[ind + 1][ind + 1];
            }

            dp[ind][prev_index + 1] = max(notTake, take);
        }
    }

    return dp[0][0];
}

/* Tabulation algorithm to find the length of the longest increasing subsequence.(follow this)

1. Run an outer loop running from 0 to n-1. Every outer loop iteration will find the dp[i] value.
2. Nest another loop inside it. For particular index i, this inner loop will help us to find the maximum value of dp[prev_index].
3. Now inside the inner loop, we will first of all see that the element at the prev_index is smaller than the element at index i. If it is, we update dp[i] with the max(1+dp[prev_ind],dp[prev_index]).
4.At last, we will loop over the dp array and return its largest value as our answer.

*/

#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n)
{

    vector<int> dp(n, 1);

    for (int i = 0; i <= n - 1; i++)
    {
        for (int prev_index = 0; prev_index <= i - 1; prev_index++)
        {
            if (arr[prev_index] < arr[i] && dp[i] < 1 + dp[prev_index])
            {
                dp[i] = 1 + dp[prev_index];
            }
        }
        // maxi=max(maxi,dp[i])  return maxi
    }

    int ans = -1;
    for (int i = 0; i <= n - 1; i++)
    {
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main()
{
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The length of the longest increasing subsequence is "
         << longestIncreasingSubsequence(arr, n);
    return 0;
}
/*Time Complexity: O(N*N)
Reason: There are two nested loops.
Space Complexity: O(N)
*/

/* LIS calculation using binary search with the help of lower_bound taht gives the ind of ele which is ele>=arr[i].

Approach =>
 1. Initialize a temp array.
2.  Push the first element of the array to temp.
3.  Iterate over the next elements.
4.  In every iteration, if arr[i] is greater than the last element of the temp array simply push it to the temp array.
5.  Else, just find the lower_bound index of that element in the temp array (say ind). THen simply initialize temp[ind] = arr[i] (// replacement step).
6.  Maintain a len variable to calculate the length of the temp array in the iteration itself.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the longest increasing subsequence
int longestIncreasingSubsequence(int arr[], int n)
{
    // Create a temporary vector to store the increasing subsequence
    vector<int> temp;
    temp.push_back(arr[0]);
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > temp.back())
        {
            // If arr[i] is greater than the last element of temp,than push the ele in temp vector and extend the subsequence
            temp.push_back(arr[i]);
            len++;
        }
        else
        {
            // If arr[i] is not greater, replace the element in temp with arr[i]
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i]; // overriding
        }
    }

    return len; // or simply return temp.size()
}
int main()
{
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The length of the longest increasing subsequence is " << longestIncreasingSubsequence(arr, n);
    return 0;
}

// The length of the longest increasing subsequence is 4

/*
Time Complexity: O(N*logN)
Reason: We iterate over the array of size N and in every iteration, we perform a binary search which takes logN time.
Space Complexity: O(N)
*/