/*  ⊛ we will take a hashmap and we will check in each iteration that hashmap contains (target - nums[i]) if contains then
    ⊛  we will store our current index in ans[1] and in ans[0] we will store the index of that element which is the (target - nums[i]).
    ⊛ Time Complexity: O(N ) & Space Complexity: O(N).


* Two Sum : Check if a pair with given sum exists in Array
 Problem Statement: Given an array of integers nums[] and an integer target, return indices of the two numbers such that their sum is equal to the target.

 Note: Assume that there is exactly one solution, and you are not allowed to use the same element twice. Example: If target is equal to 6 and num[1] = 3, then nums[1] + nums[1] = target is not a solution.

 Example 1:

 Input: nums = [2,7,11,15], target = 9

 Output: [0,1]

 Explanation: Because nums[0] + nums[1] == 9,
 which is the required target, we return
 indexes [0,1]. (0-based indexing)
 Example 2:

 Input Format: nums = [3,2,4,6], target = 6

 Output: [1,2]

 Explanation: Because nums[1] + nums[2] == 6,
 which is the required target, we return
 indexes [1,2].

*/

// approach1)
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(int n, vector<int> &arr, int target)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end())
        {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return {-1, -1};
}

int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    vector<int> ans = twoSum(n, arr, target);
    cout << "This is the answer for variant 2: [" << ans[0] << ", "
         << ans[1] << "]" << endl;
    return 0;
}
// Time Complexity: O(N), where N = size of the array.
// Reason: The loop runs N times in the worst case and searching in a hashmap takes O(1) generally. So the time complexity is O(N).

// Note: In the worst case(which rarely happens), the unordered_map takes O(N) to find an element. In that case, the time complexity will be O(N2). If we use map instead of unordered_map, the time complexity will be O(N* logN) as the map data structure takes logN time to find an element.

// Space Complexity: O(N) as we use the map data structure.

// Note: We have optimized this problem enough. But if in the interview, we are not allowed to use the map data structure, then we should move on to the following approach i.e. two pointer approach. This approach will have the same time complexity as the better approach.

// approach 2)
/*
We will sort the given array first.
Now, we will take two pointers i.e. left, which points to the first index, and right, which points to the last index.
Now using a loop we will check the sum of arr[left] and arr[right] until left < right.
If arr[left] + arr[right] > sum, we will decrement the right pointer.
If arr[left] + arr[right] < sum, we will increment the left pointer.
If arr[left] + arr[right] == sum, we will return the result.
Finally, if no results are found we will return “No” or {-1, -1}.
*/

#include <bits/stdc++.h>
using namespace std;

string twoSum(int n, vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target)
        {
            return "YES";
        }
        else if (sum < target)
            left++;
        else
            right--;
    }
    return "NO";
}
