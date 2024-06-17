/* Approach=>
1. Place the 2 pointers i.e. low and high: Initially, we will place the pointers like this: low will point to the first index, and high will point to the last index.
2. Calculate the ‘mid’: Now, inside a loop, we will calculate the value of ‘mid’ using the following formula:
mid = (low+high) // 2 ( ‘//’ refers to integer division)
3. Check if arr[mid] = target: If it is, return True.
4. Check if arr[low] = arr[mid] = arr[high]: If this condition is satisfied, we will just increment the low pointer and decrement the high pointer by one step. We will not perform the later steps until this condition is no longer satisfied. So, we will continue to the next iteration from this step.this will remove duplicate ele.
5. Identify the sorted half, check where the target is located, and then eliminate one half accordingly:
6. If arr[low] <= arr[mid]: This condition ensures that the left part is sorted.
7. If arr[low] <= target && target <= arr[mid]: It signifies that the target is in this sorted half. So, we will eliminate the right half (high = mid-1).
8. Otherwise, the target does not exist in the sorted half. So, we will eliminate this left half by doing low = mid+1.
9. Otherwise, if the right half is sorted:
If arr[mid] <= target && target <= arr[high]: It signifies that the target is in this sorted right half. So, we will eliminate the left half (low = mid+1).
Otherwise, the target does not exist in this sorted half. So, we will eliminate this right half by doing high = mid-1.
10. Once, the ‘mid’ points to the target, we will return True.
11. This process will be inside a loop and the loop will continue until low crosses high. If no element is found, we will return False.
*/

#include <bits/stdc++.h>
using namespace std;

bool searchInARotatedSortedArrayII(vector<int> &arr, int k)
{
    int n = arr.size(); // size of the array.
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // if mid points the target
        if (arr[mid] == k)
            return true;

        // Edge case:
        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low = low + 1;
            high = high - 1;
            continue;
        }

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
        { // if right part is sorted: arr[mid]<arr[high]
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
    return false;
}
int main()
{
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 3;
    bool ans = searchInARotatedSortedArrayII(arr, k);
    if (!ans)
        cout << "Target is not present.\n";
    else
        cout << "Target is present in the array.\n";
    return 0;
}
