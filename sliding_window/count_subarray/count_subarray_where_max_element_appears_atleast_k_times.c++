/*  ATLEAST COND =>  https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/?envType=daily-question&envId=2024-03-29

Input: nums = [1,3,2,3,3], k = 2
Output: 6
Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].
*/

long long countSubarrays(vector<int> &nums, int k)
{
    // find max ele
    int maxele = *max_element(nums.begin(), nums.end());
    int i = 0, j = 0;
    int n = nums.size();
    long long len = 0;
    int cnt = 0;
    while (j < n)
    {
        // if maxele found than inc the cnt
        if (nums[j] == maxele)
        {
            cnt++;
        }
        // if cnt is equal or greater than k than atleast condn hits
        if (cnt >= k)
        {
            while (cnt >= k)
            {
                // shrink the window
                if (nums[i] == maxele)
                    cnt--;
                i++;
                // count the appearence becz if at j pos condn hits than it must satisfies all the pos greater than j so apply ans+=(n-j)
                len += (n - j);
            }
        }
        j++;
    }
    return len;
}