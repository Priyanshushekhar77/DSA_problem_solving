/*
 * Given a binary array nums, return the maximum number of consecutive 1's in the array.
 * 
   Example 1:
   Input: nums = [1,1,0,1,1,1]
   Output: 3
   Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
   Example 2:
   
   Input: nums = [1,0,1,1,0,1]
   Output: 2
 */
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int cnt = 0;
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }

            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};

int main()
{
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    Solution obj;
    int ans = obj.findMaxConsecutiveOnes(nums);
    cout << "The maximum  consecutive 1's are " << ans;
    return 0;
}