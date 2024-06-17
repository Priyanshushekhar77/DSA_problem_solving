/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

A/Q => longest subarray which contains atmost k zeroes

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
*/

// bruteforce
/*
for(int i=0;i<n;i++){
  for(int j=i;j<n;j++){
  if(arr[i]==0) cnt++;
  if(cnt==k) len=max(len,j-i+1);
  else break;
  }
}
return len;
*/

// optimal

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int cnt = 0;
        int i = 0, j = 0, len = 0;
        int n = nums.size();
        while (j < n)
        {
            if (nums[j] == 0)
                cnt++;
            if (cnt <= k)
            {
                len = max(len, j - i + 1);
            }
            else if (cnt > k)
            {
                while (cnt > k)
                {
                    if (nums[i] == 0)
                        cnt--;
                    i++;
                }
            }
            j++;
        }
        return len;
    }
};