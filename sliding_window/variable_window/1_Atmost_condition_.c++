/*
ATMOST CONDITION=> https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/?envType=daily-question&envId=2024-03-28

Input: nums = [1,2,3,1,2,3,1,2], k = 2
Output: 6
Explanation: The longest possible good subarray is [1,2,3,1,2,3] since the values 1, 2, and 3 occur at most twice in this subarray. Note that the subarrays [2,3,1,2,3,1] and [3,1,2,3,1,2] are also good.
It can be shown that there are no good subarrays with length more than 6.
*/
// longest len of substring having atmost k frequency

int maxSubarrayLength(vector<int> &nums, int k)
{
    int n = nums.size();
    int i = 0, j = 0, len = 0;
    unordered_map<int, int> mp;
    while (j < n)
    {
        mp[nums[j]]++;
        if (mp[nums[j]] > k)
        {
            while (mp[nums[j]] > k)
            {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
        }
        len = max(len, j - i + 1);
        j++;
    }
    return len;
}

// cnt of substring having atmost k frequency

/* Q14.COUNT OF SUBSTRING HAVING ATMOST K UNIQUE CHARACTER
atmostdistinct(str, k - 1)
{
    unordered_map<char, int> mp;
    i = 0, j = 0, ans = 0;
    while (j < n)
    {
        mp[str[j]]++;
        while (i <= j && mp.size() > k)
        {
            mp[str[i]]--;
            if (mp[str[i]] == 0)
                mp.erase(str[i]);
            i++;
        }
        ans += (j - i + 1);
        j++
    }
    return ans;
}

*/