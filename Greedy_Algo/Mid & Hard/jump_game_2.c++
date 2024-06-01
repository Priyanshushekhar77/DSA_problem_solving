
// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Input: nums = [2,3,0,1,4]
// Output: 2
#include <bits/stdc++.h>
using namespace std;
// using dp approach
int minJumps(vector<int> &nums, int ind, vector<int> &dp)
{
    int n = nums.size();
    if (ind >= n - 1)
        return 0; // If already at or beyond the last index
    if (dp[ind] != -1)
        return dp[ind]; // Return if already calculated
    int maxjump = min(ind + nums[ind], n - 1);
    int minSteps = INT_MAX;
    // Range of jumps
    for (int i = ind + 1; i <= maxjump; i++)
    {
        int jumps = minJumps(nums, i, dp); // cal form rec
        if (jumps != INT_MAX)
        {
            minSteps = min(minSteps, jumps + 1); // ninstep is minimum jump from all range of jumps
        }
    }
    // putting in the dp
    dp[ind] = minSteps;
    return dp[ind];
}

int jump(vector<int> &nums)
{
    vector<int> dp(nums.size(), -1);
    return minJumps(nums, 0, dp);
}

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4}; // Example input
    int result = jump(nums);
    cout << "The minimum number of jumps to reach the last index is " << result << endl;
    return 0;
}

// greddy Approach  => SPACE-COMPLEXITY=O(1)
//  Since both the outer while loop and the inner for loop together process each element of the array at most once, the overall time complexity of the algorithm is O(N)

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0; // No jumps needed if already at the last index

        int l = 0, r = 0;
        int step = 0;

        while (r < n - 1)
        {
            int maxjump = 0;
            // Range of jumps -> [l, r]
            for (int i = l; i <= r; i++)
            {
                maxjump = max(maxjump, i + nums[i]);
                if (maxjump >= n - 1)
                { // If we can reach or exceed the last index
                    return step + 1;
                }
            }
            // Move to the next range
            step++;
            l = r + 1;
            r = maxjump;
        }

        return step;
    }
};
