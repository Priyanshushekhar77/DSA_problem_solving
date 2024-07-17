
// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Input: nums = [2,3,0,1,4]
// Output: 2
#include <bits/stdc++.h>
using namespace std;
// using dp approach
int solve(vector<int> &nums, vector<int> &dp, int ind)
{
    if (ind >= nums.size() - 1)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int maxjump = min(ind + nums[ind], (int)nums.size() - 1);
    int steps = INT_MAX - 1;
    for (int i = ind + 1; i <= maxjump; i++)
    {
        int jump = 1 + solve(nums, dp, i);
        if (jump < steps)
        {
            steps = min(steps, jump);
        }
    }
    return dp[ind] = steps;
}

int jump(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return solve(nums, dp, 0); // Fixed the arguments order
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
            }
            // Move to the next range
            step++;
            l = r;
            r = maxjump;
        }

        return step;
    }
};
