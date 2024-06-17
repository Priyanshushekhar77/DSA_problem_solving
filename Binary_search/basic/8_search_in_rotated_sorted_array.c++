/*
 * Search Element in a Rotated Sorted Array
   Problem Statement: There is an integer array nums sorted in ascending order (with distinct values). Given the array nums after the possible clockwise rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums. We need to search a given element in a rotated sorted array.

   Example 1:

   Input: nums = [4,5,6,7,0,1,2,3], target = 0

   Output: 4

   Explanation: Here, the target is 0. We can see that 0 is present in the given rotated sorted array, nums. Thus, we get output as 4, which is the index at which 0 is present in the array.
   Example 2:

   Input: nums = [4,5,6,7,0,1,2], target = 3

   Output: -1

   Explanation: Here, the target is 3. Since 3 is not present in the given rotated sorted array. Thus, we get output as -1.

   Approach=>
1. First, we identify the sorted half of the array.
2. Once found, we determine if the target is located within this sorted half.
   a. If not, we eliminate that half from further consideration.
   b. Conversely, if the target does exist in the sorted half, we eliminate the other half.
*/

#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &arr, int n, int k)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        // if mid points the target
        if (arr[mid] == k)
            return mid;

        // if left part is sorted:
        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= k && k <= arr[mid])
            {
                // element exists:
                high = mid - 1;
            }
            else
            {
                // element does not exist:
                low = mid + 1;
            }
        }
        else
        { // if right part is sorted: i.r arr[mid] < arr[high]
            if (arr[mid] <= k && k <= arr[high])
            {
                // element exists:
                low = mid + 1;
            }
            else
            {
                // element does not exist:
                high = mid - 1;
            }
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n = 9, k = 1;
    int ans = search(arr, n, k);
    if (ans == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << ans << "\n";
    return 0;
}
