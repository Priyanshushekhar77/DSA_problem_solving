/*  link= https://leetcode.com/problems/count-number-of-nice-subarrays/description/
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There is no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
*/

/*
  int numberOfSubarrays(vector<int>& nums, int k) {
        //method 1-> counting methods
        // return subArray(nums, k) - subArray(nums, k - 1);
        //method 2-> using map methods
        int oddcnt=0,cnt=0;
        int n=nums.size();
         unordered_map<int,int>mp;
          mp[0]=1;// handle if(oddcnt==k) cnt++;
         for(int i=0;i<n;i++){
             if(nums[i]%2==1)oddcnt++;
             int rem=oddcnt-k;
             if(mp.find(rem)!=mp.end()){
                 cnt+=mp[rem];
             }
             mp[oddcnt]++;
         }
         return cnt;

    }
*/

// Optimal

class Solution
{
public:
    int subArray(vector<int> &nums, int k)
    {
        int oddcnt = 0, i = 0, j = 0, ans = 0;
        int n = nums.size();
        while (j < n)
        {
            if (nums[j] % 2 == 1)
                oddcnt++;
            if (oddcnt > k)
            {
                while (i <= j && oddcnt > k)
                {
                    // shrink the window
                    if (nums[i] % 2 == 1)
                        oddcnt--;
                    i++;
                }
            }
            ans += j - i + 1;
            j++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return subArray(nums, k) - subArray(nums, k - 1);
    }
};