/*
 Maximum Product Subarray in an Array
  Problem Statement: Given an array that contains both negative and positive integers, find the maximum product subarray.

  Examples:

  Example 1:
  Input:
   Nums = [1,2,3,4,5,0]
  Output:
   120
  Explanation:
   In the given array, we can see 1×2×3×4×5 gives maximum product value.


  Example 2:
  Input:
   Nums = [1,2,-3,0,-4,-5]
  Output:
   20
  Explanation:
  In the given array, we can see (-4)×(-5) gives maximum product value.
*/

// BRUTEFORCE

#include <bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int> &nums)
{
    int result = nums[0];
    for (int i = 0; i < nums.size() - 1; i++)
    {
        int p = nums[i];
        for (int j = i + 1; j < nums.size(); j++)
        {
            result = max(result, p);
            p *= nums[j];
        }
        result = max(result, p); // manages (n-1)th term
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 2, -3, 0, -4, -5};
    cout << "The maximum product subarray: " << maxProductSubArray(nums);
    return 0;
}

// OPTIMAL

#include <bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int> &arr)
{
    int n = arr.size(); // size of array.

    int pre = 1, suff = 1;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (pre == 0)
            pre = 1;
        if (suff == 0)
            suff = 1;
        pre *= arr[i];
        suff *= arr[n - i - 1];
        ans = max(ans, max(pre, suff));
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, -3, 0, -4, -5};
    cout << "The maximum product subarray is: "
         << maxProductSubArray(arr) << "\n";
    return 0;
}
