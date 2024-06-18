/* Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

*/

int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    if (k <= 1)
        return 0;
    int n = nums.size();
    int i = 0;
    int j = 0;
    int cnt = 0;
    int prd = 1;
    while (j < n)
    {
        prd *= nums[j];
        if (prd >= k)
        {
            while (prd >= k)
            {
                prd = prd / nums[i];
                i++;
            }
        }

        cnt += (j - i + 1);
        j++;
    }
    return cnt;
}