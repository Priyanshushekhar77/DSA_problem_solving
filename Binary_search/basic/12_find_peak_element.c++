/*
 * Peak element in Array
    Problem Statement: Given an array of length N. Peak element is defined as the element greater than both of its neighbors. Formally, if 'arr[i]' is the peak element, 'arr[i - 1]' < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'. Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.

   Examples:

   Example 1:
   Input:
    arr = {3, 5, 4, 1, 1}

   Output: Peak Element is 5
   Explanation:
    3 and 4 are lesser than 5, therefore 5 is a peak element (1 is also a peak element).

   Example 2:
   Input: arr = {2,6,3,7,8,9}
   Output: Peak element is 6
   Explanation: 2 and 3 are lesser than 6, therefore 6 is a peak element (9 is also a peak element)

=> How to identify if an element arr[i] is a peak:

1. We know that if arr[i] is the peak, arr[i] > arr[i-1] and arr[i] > arr[i+1]. So, we can check this condition for all the elements and identify the peak. But there are the following edge cases:

2. If n == 1: The aforementioned condition will not be applicable. In this scenario, when the array size is 1, the single element within the array serves as the peak, and thus we should return its index.

3. If i == 0: The aforementioned condition will not be applicable as arr[i-1] will refer to arr[-1] which is invalid. So, in this case, we should check if arr[0] > arr[1]. If this condition holds, we can conclude that arr[0] is a peak.

4. If i == n-1: The aforementioned condition will not be applicable as arr[i+1] will refer to arr[n] which is again invalid. So, in this case, we should check if arr[n-1] > arr[n-2]. If this condition holds, we can conclude that arr[n-1] is a peak.
*/

#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &arr)
{
    int n = arr.size(); // Size of array.

    // Edge cases:
    if (n == 1)
        return 0;
    if (arr[0] > arr[1])
        return 0;
    if (arr[n - 1] > arr[n - 2])
        return n - 1;

    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        // If arr[mid] is the peak:
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return mid;

        // If we are in the left:
        if (arr[mid] > arr[mid - 1])
            low = mid + 1;

        // If we are in the right: arr[mid]<arr[mid-1]
        else
            high = mid - 1;
    }
    // Dummy return statement
    return -1;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = findPeakElement(arr);
    cout << "The peak is at index: " << ans << "\n";
    return 0;
}
