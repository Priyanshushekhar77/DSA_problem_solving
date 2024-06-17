/*
n = 5
arr[] = {5, 1, 2, 3, 4}
Output: 1
Explanation: The given array is 5 1 2 3 4.
The original sorted array is 1 2 3 4 5.
We can see that the array was rotated
1 times to the right.
Example 2:

Input:
n = 5
arr[] = {1, 2, 3, 4, 5}
Output: 0
Explanation: The given array is not rotated.

approach =>  in order to solve this problem, we have to find the index of the minimum element.

*/

#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // search space is already sorted
        // then arr[low] will always be
        // the minimum in that search space:
        if (arr[low] <= arr[high])
        {
            if (arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            }
            break;
        }

        // if left part is sorted:
        if (arr[low] <= arr[mid])
        {
            // keep the minimum:
            if (arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            }

            // Eliminate left half: and go for right half becz ans can exist there
            low = mid + 1;
        }
        else
        { // if right part is sorted:// arr[mid] < arr[high]

            // keep the minimum:
            if (arr[mid] < ans)
            {
                index = mid;
                ans = arr[mid];
            }

            // Eliminate right half: and go for left half becz ans can exist there
            high = mid - 1;
        }
    }
    return index;
}
int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findKRotation(arr);
    cout << "The array is rotated " << ans << " times.\n";
    return 0;
}
