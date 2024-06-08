//  * Move all Zeros to the end of the array
//    In this article we will learn how to solve the most asked coding interview problem: “Move all Zeros to the end of the array”

//    Problem Statement: You are given an array of integers, your task is to move all the zeros in the array to the end of the array and move non-negative integers to the front by maintaining their order.

//    Examples:

//    Example 1:
//    Input: 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1
//    Output: 1 ,2 ,3 ,4 ,1 ,0 ,0 ,0
//    Explanation: All the zeros are moved to the end and non-negative integers are moved to front by maintaining order

//    Example 2:
//    Input: 1,2,0,1,0,4,0
//    Output: 1,2,1,4,0,0,0
//    Explanation: All the zeros are moved to the end and non-negative integers are moved to front by maintaining order

// */

// Bruteforce->
//  1. Suppose, there are N-X zeros and X non-zero elements in the array. We will first copy those X non-zero elements from the original array to a temporary array.
//  2. Then, we will copy the elements from the temporary array one by one and fill the first X places of the original array.
//  3. The last N-X places of the original array will be then filled with zero. Now, our task is completed.

// optimal=>

#include <bits/stdc++.h>
using namespace std;

vector<int> moveZeros(int n, vector<int> a)
{
    int zeroind = -1;
    // place the pointer j:
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            zeroind = i;
            break;
        }
    }

    // no non-zero elements:
    if (zeroind == -1)
        return a;

    // Move the pointers i from the next ind of zero
    // and swap accordingly:
    for (int i = zeroind + 1; i < n; i++)
    {
        if (a[i] != 0)
        {
            swap(a[i], a[zeroind]);
            zeroind++;
        }
    }
    return a;
}

int main()
{
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = 10;
    vector<int> ans = moveZeros(n, arr);
    for (auto &it : ans)
    {
        cout << it << " ";
    }
    cout << '\n';
    return 0;
}

// ALSO
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int j = 0;
        for (int k = 0; k < nums.size(); k++)
        {
            if (nums[k] != 0)
            {
                swap(nums[j], nums[k]);
                j++;
            }
        }
    }
};
