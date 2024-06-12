
      ⊛ The brute force approach is find the all possible subarrays and calculate the sum. (Time complexity: O(N^3)
      ⊛  We only need to calculate the maximum sum so we can avoid our third loop and when ever previous sum is less than curr sum we will updated our sum. (O(N^2))
      ⊛  The Best Optimized Approach is to use KADANE'S ALGORITHM
      ⊛ Time Complexity: O(N ) & Space Complexity: O(1).

      /*
       * Kadane’s Algorithm : Maximum Subarray Sum in an Array
         Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which
         has the largest sum and return its sum and print the subarray.

         Examples:

         Example 1:
         Input: arr = [-2,1,-3,4,-1,2,1,-5,4]
         Output: 6
         Explanation: [4,-1,2,1] has the largest sum = 6.

         Examples 2:
         Input: arr = [1]
         Output: 1
         Explanation: Array has only one element and which is giving positive sum of 1.

       */
      // BRUTEFORCE ->2 loop

#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            // current subarray = arr[i.....j]

            // add the current element arr[j]
            //  to the sum i.e. sum of arr[i...j-1]
            sum += arr[j];

            maxi = max(maxi, sum); // getting the maximum
        }
    }

    return maxi;
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}

      // OPtimal-> KADANE'S ALGO
      /*Approach:
      The steps are as follows:

      We will run a loop(say i) to iterate the given array.
      Now, while iterating we will add the elements to the sum variable and consider the maximum one.

      If at any point the sum becomes negative we will set the sum to 0 as we are not going to consider it as a part of our answer.

      Note: In some cases, the question might say to consider the sum of the empty subarray while solving this problem. So, in these cases, before returning the answer we will compare the maximum subarray sum calculated with 0(i.e. The sum of an empty subarray is 0). And after that, we will return the maximum one.
      For e.g. if the given array is {-1, -4, -5}, the answer will be 0 instead of -1 in this case.
      */

#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {

        sum += arr[i];

        if (sum > maxi)
        {
            maxi = sum;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0)
        {
            sum = 0;
        }
    }

    // To consider the sum of the empty subarray
    // uncomment the following check:

    // if (maxi < 0) maxi = 0; handle edge case for negaitve answer

    return maxi;
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}
