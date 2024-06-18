/* https://www.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

N = 4
A[] = {0,1,0,1}
Output: 4
Explanation: The array from index [0...3]
contains equal number of 0's and 1's.
Thus maximum length of subarray having
equal number of 0's and 1's is 4.
Example 2:

Input:
N = 5
A[] = {0,0,1,0,0}
Output: 2
*/

int maxLen(int nums[], int n)
{
    // Your code here
    int len = 0, sum = 0;
    unordered_map<int, int> mp;
    mp[0] = -1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
            sum += -1;
        else
            sum += 1;
        if (mp.find(sum) != mp.end())
        {
            len = max(len, i - mp[sum]);
        }
        else
        {
            mp[sum] = i;
        }
    }
    return len;
}

// 2.count subarray with equal no's of 1 and 0
/*
n = 7
A[] = {1,0,0,1,0,1,1}
Output: 8
Explanation: The index range for the 8
sub-arrays are: (0, 1), (2, 3), (0, 3), (3, 4),
(4, 5) ,(2, 5), (0, 5), (1, 6)
Example 2:

Input:
n = 5
A[] = {1,1,1,1,0}
Output: 1
Explanation: The index range for the
subarray is (3,4).
*/

long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
{
    // Your code here
    int cnt = 0, sum = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            sum += -1;
        else
            sum += 1;
        if (mp.find(sum) != mp.end())
        {
            cnt += mp[sum];
        }

        mp[sum]++;
    }
    return cnt;
}