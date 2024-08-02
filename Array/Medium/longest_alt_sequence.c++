/*
1.  x1 < x2 > x3 < x4 > x5. . . . . and so on
2.  x1 >x2 < x3 > x4 < x5. . . . . and so on

Note: A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.

Examples:

Input: arr= [1, 5, 4]
Output: 3
Explanation: The entire sequenece is a good sequence.
Input: arr= [1, 17, 5, 10, 13, 15, 10, 5, 16, 8]
Output: 7
Explanation: There are several subsequences that achieve this length.
One maximum length good subsequences is [1, 17, 10, 13, 10, 16, 8].
*/

int alternatingMaxLength(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return 0;

    int ans = 1;
    int prev = arr[0];

    for (int i = 1; i < n; i++)
    {
        if ((prev < arr[i] && (i == n - 1 || arr[i] > arr[i + 1])) ||
            (prev > arr[i] && (i == n - 1 || arr[i] < arr[i + 1])))
        {
            ans++;
            prev = arr[i];
        }
    }
    return ans;
}