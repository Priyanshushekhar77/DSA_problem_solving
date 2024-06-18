// link->https://www.geeksforgeeks.org/problems/zero-sum-subarrays1825/1?page=1&sprint=93bae517656b109148ce7a63a6175891&sortBy=submissions

/* n = 6
arr[] = {0,0,5,5,0,0}
Output: 6
Explanation: The 6 subarrays are
[0], [0], [0], [0], [0,0], and [0,0].
*/

long long int findSubarray(vector<long long int> &arr, int n)
{
    // code here
    unordered_map<int, int> mp;

    long long sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            cnt++;
        }
        int rem = sum - 0;
        if (mp.find(rem) != mp.end())
        {
            cnt += mp[rem];
        }

        mp[sum]++;
    }
    return cnt;
}