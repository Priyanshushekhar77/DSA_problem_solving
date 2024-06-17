/*
 * Find the First and Last occurrence in a sorted array
   Given a sorted array of N integers, write a program to find the index of the first and last occurrence of the target key. If the target is not found then return -1.

   Note: Consider 0 based indexing

   Examples:

   Example 1:
   Input: N = 7, target=13, array[] = {3,4,13,13,13,20,40}
   Output: 2, 4
   Explanation: As the target value is 13 , it appears for the first time at index number 2, and last time at index number 4.

   Example 2:
   Input: N = 7, target=60, array[] = {3,4,13,13,13,20,40}
   Output: -1, -1
   Explanation: Target value 60 is not present in the array
 */

vector<int> searchRange(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1, firstPos = -1, lastPos = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target)
            firstPos = mid, end = mid - 1;
        else if (nums[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    start = 0, end = nums.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target)
            lastPos = mid, start = mid + 1;
        else if (nums[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return {firstPos, lastPos};
}