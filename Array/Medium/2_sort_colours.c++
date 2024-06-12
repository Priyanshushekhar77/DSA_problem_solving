
      ⊛ The most easiest Approach is sort the Array as order as 0, 1, 2 (Time complexity: O(NlogN).
      ⊛  The most Optimized Solution is to use Dutch National Flag Algorithm
      ⊛ Time Complexity: O(N ) & Space Complexity: O(1).

      /*
       * Sort an array of 0s, 1s and 2s
         Problem Statement: Given an array consisting of only 0s, 1s and 2s. Write a program to in-place sort the array without using inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)

         Example 1:

         Input: nums = [2,0,2,1,1,0]
         Output: [0,0,1,1,2,2]

         Input: nums = [2,0,1]
         Output: [0,1,2]

         Input: nums = [0]
         Input: nums = [0]

      */
      /* Bruteforce Approach:
      Take 3 variables to maintain the count of 0, 1 and 2.
      Travel the array once and increment the corresponding counting variables and last print the 0,1,2 a/c no of times count variable.
      */

      /*optimal=>DUTCH NATIONAL FLAG ALGO
      Here, as the entire array is unsorted, we have placed the mid pointer in the first index and the high pointer in the last index. The low is also pointing to the first index as we have no other index before 0. Here, we are mostly interested in placing the ‘mid’ pointer and the ‘high’ pointer as they represent the unsorted part in the hypothetical array.

      Now, let’s understand how the pointers will work to make the array sorted.

      Approach:

      Note: Here in this tutorial we will work based on the value of the mid pointer.

      The steps will be the following:

      First, we will run a loop that will continue until mid <= high.
      There can be three different values of mid pointer i.e. arr[mid]
      If arr[mid] == 0, we will swap arr[low] and arr[mid] and will increment both low and mid. Now the subarray from index 0 to (low-1) only contains 0.
      If arr[mid] == 1, we will just increment the mid pointer and then the index (mid-1) will point to 1 as it should according to the rules.
      If arr[mid] == 2, we will swap arr[mid] and arr[high] and will decrement high. Now the subarray from index high+1 to (n-1) only contains 2.
      In this step, we will do nothing to the mid-pointer as even after swapping, the subarray from mid to high(after decrementing high) might be unsorted. So, we will check the value of mid again in the next iteration.
      Finally, our array should be sorted.
      */

#include <bits/stdc++.h>
using namespace std;

void sortArray(vector<int>& arr, int n) {
    int low = 0, mid = 0, high = n - 1; // 3 pointers

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    sortArray(arr, n);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
