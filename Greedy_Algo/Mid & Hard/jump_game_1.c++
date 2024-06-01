// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:

// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

#include <bits/stdc++.h>
using namespace std;
bool canJump(vector<int> &nums)
{
    int maxind = 0;
    // If 0 is not present at any index then it always reaches the last index.
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > maxind)
            return false; // if index is more than max jump
        maxind = max(maxind, i + nums[i]);
    }
    return true;
}
int main()
{
    vector<int> nums = {2, 3, 1, 1, 4}; // Example input
    if (canJump(nums))
    {
        cout << "Can reach the last index" << endl;
    }
    else
    {
        cout << "Cannot reach the last index" << endl;
    }
    return 0;
}
