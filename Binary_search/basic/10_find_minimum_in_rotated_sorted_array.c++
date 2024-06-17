/*
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
Example 3:

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times.

 Algo=>
1. Place the 2 pointers i.e. low and high: Initially, we will place the pointers like this: low will point to the first index, and high will point to the last index.
2. Calculate the ‘mid’: Now, inside a loop, we will calculate the value of ‘mid’ using the following formula:
mid = (low+high) // 2 ( ‘//’ refers to integer division)
3. If arr[low] <= arr[high]: In this case, the array from index low to high is completely sorted. Therefore, we can select the minimum element, arr[low], and update the 'ans' variable with the minimum value i.e. min(ans, arr[low]). Once this is done, there is no need to continue with the binary search algorithm. So, we will break from this step.

4. Identify the sorted half, and after picking the leftmost element, eliminate that half.
  a. If arr[low] <= arr[mid]: This condition ensures that the left part is sorted. So, we will pick the leftmost element i.e. arr[low]. Now, we will compare it with 'ans' and update 'ans' with the smaller value (i.e., min(ans, arr[low])). Now, we will eliminate this left half(i.e. low = mid+1).
  b. Otherwise, if the right half is sorted:  This condition ensures that the right half is sorted. So, we will pick the leftmost element i.e. arr[mid]. Now, we will compare it with 'ans' and update 'ans' with the smaller value (i.e., min(ans, arr[mid])). Now, we will eliminate this right half(i.e. high = mid-1).
5. This process will be inside a loop and the loop will continue until low crosses high. Finally, we will return the ‘ans’ variable that stores the minimum element.

*/

#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // search space is already sorted
        // then arr[low] will always be
        // the minimum in that search space: and break from loop
        if (arr[low] <= arr[high])
        {
            ans = min(ans, arr[low]);
            break;
        }

        // if left part is sorted:
        if (arr[low] <= arr[mid])
        {
            // keep the minimum: and go for right half can minimum exist on right part
            ans = min(ans, arr[low]);

            // Eliminate left half: and go for right half
            low = mid + 1;
        }
        else
        { // if right part is sorted://arr[mid]<arr[high]

            // keep the minimum: and go for left half can be minimum exist on the left part
            ans = min(ans, arr[mid]);

            // Eliminate right half: and go for left
            high = mid - 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findMin(arr);
    cout << "The minimum element is: " << ans << "\n";
    return 0;
}
