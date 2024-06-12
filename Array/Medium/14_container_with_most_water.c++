/*
//link->https://leetcode.com/problems/container-with-most-water/description/

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
*/
// bruteforce
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);
        // max of left height
        left[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            left[i] = max(left[i - 1], height[i]);
        }
        // max of right height
        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = max(right[i + 1], height[i]);
        }

        int ans = 0;
        // summing
        for (int i = 1; i < n; i++)
        {
            ans += min(left[i], right[i]) - height[i];
        }
        return ans;
    }
};

// optimal -> using stack