/*
 * Q. Write a program to Search an element from an array using binary Search.
 * Algorithm:

   Consider start index to be at 0 and last index to be n-1th index at starting      //n->length
   Find middle index(mid) of the array
   If key is found to be less than mid index element then update last index of the array to mid -1
   Else if key is found to be greater than mid index element then update start index of the array to mid +1
   Else check for mid index element with key if not match repeat the above steps till start index is less than end index

   Example:

   Example 1:
   Input: nums = [-1,0,3,5,9,12], target = 9
   Output: 4
   Explanation: 9 exists in nums and its index is 4

   Example 2:
   Input: nums = [-1,0,3,5,9,12], target = 2
   Output: -1
   Explanation: 2 does not exist in nums so return -1

*/

#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &nums, int target)
{
    int n = nums.size(); // size of the array
    int low = 0, high = n - 1;
    // Perform the steps:
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        else if (target > nums[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;
    int ind = binarySearch(a, target);
    if (ind == -1)
        cout << "The target is not present." << endl;
    else
        cout << "The target is at index: "
             << ind << endl;
    return 0;
}
