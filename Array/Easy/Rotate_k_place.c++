/*
 * Given an array arr[] of size N and an integer K, the task is to left rotate the array K indexes

   Example 1:
   Input: N = 7, K = 2
   arr[] = {1, 2, 3, 4, 5, 6, 7}
   Output: 3 4 5 6 7 1 2
   Explanation: Rotation of the above
   array by 2 will make the output array .

 */
#include <bits/stdc++.h>
using namespace std;
// Function to Reverse the array
void Reverse(int arr[], int start, int end)
{
    while (start <= end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
// Function to Rotate k elements to left
void Rotateeletoleft(int arr[], int n, int k)
{
    // Reverse first k elements
    Reverse(arr, 0, k - 1);
    // Reverse last n-k elements
    Reverse(arr, k, n - 1);
    // Reverse whole array
    Reverse(arr, 0, n - 1);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    int k = 2;
    Rotateeletoleft(arr, n, k);
    cout << "After Rotating the k elements to left ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
// t.c=>O(N) and s.c=>O(1)

// method2
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[(i + k) % n] = nums[i];
        }
        nums = ans;
    }
};