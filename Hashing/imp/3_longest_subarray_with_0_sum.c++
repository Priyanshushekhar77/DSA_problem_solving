/* N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.

//link-> https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1?page=1&sprint=93bae517656b109148ce7a63a6175891&sortBy=submissions

*/

int maxLen(vector<int> &a, int n)
{
    // Your code here
    // here +,- and 0 is also there
    unordered_map<int, int> mp;
    int sum = 0;
    int maxi = 0;
    mp[0] = -1; // to handle test cases like [3,-3]
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        int rem = sum - 0;
        if (mp.find(rem) != mp.end())
        {
            maxi = max(maxi, i - mp[rem]);
        }

        else
        {
            // fortest cases [3,0,0,1],k=3
            if (mp.find(sum) == mp.end())
                mp[sum] = i;
        }
    }
    return maxi;
}