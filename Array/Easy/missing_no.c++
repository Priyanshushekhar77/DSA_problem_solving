/*
   Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
 * Example 1:
   Input: nums = [3,0,1]
   Output: 2
   Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
 */
// 6.MISSING NUMBER--->>HASHING,SUM AND DIFFERNCE,XOR METHODS

#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &a, int N)
{

    // Summation of first N numbers:
    int sum = (N * (N + 1)) / 2;

    // Summation of all array elements:
    int s2 = 0;
    for (int i = 0; i < N - 1; i++)
    {
        s2 += a[i];
    }

    int missingNum = sum - s2;
    return missingNum;
}

int main()
{
    int N = 5;
    vector<int> a = {1, 2, 4, 5};
    int ans = missingNumber(a, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}

// method 2

int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ i ^ nums[i];
    }
    return ans ^ n;
}