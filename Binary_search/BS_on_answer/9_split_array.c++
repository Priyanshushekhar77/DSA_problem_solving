/*
 * Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.

   Write an algorithm to minimize the largest sum among these m subarrays.



   Example 1:

   Input: nums = [7,2,5,10,8], m = 2
   Output: 18
   Explanation:
   There are four ways to split nums into two subarrays.
   The best way is to split it into [7,2,5] and [10,8],
   where the largest sum among the two subarrays is only 18.

   Example 2:

   Input: nums = [1,2,3,4,5], m = 2
   Output: 9

   Example 3:

   Input: nums = [1,4,4], m = 3
   Output: 4
*/

class Solution
{
public:
    // m=inimize the max qns apply simply binary search
    int getstudent(vector<int> &page, int mid)
    {
        int cnt = 1;
        int pageno = 0;
        for (int i = 0; i < page.size(); i++)
        {
            if (pageno + page[i] > mid)
            {
                cnt++;
                pageno = page[i];
            }
            else
            {
                pageno += page[i];
            }
        }
        return cnt;
    }

    int splitArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = 0;
        if (k > n)
            return -1;                                      // splitpart>size
        int low = *max_element(nums.begin(), nums.end());   // to get max along arr
        int high = accumulate(nums.begin(), nums.end(), 0); // to get   sum of arr
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int student = getstudent(nums, mid);
            // here dealing with minimize the max
            if (student > k)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};