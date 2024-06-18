/*
 * Nth Root of a Number using Binary Search
   Problem Statement: Given two numbers N and M, find the Nth root of M.

   The nth root of a number M is defined as a number X when raised to the power N equals M.

   Example 1:
   Input: N=3 M=27
   Output: 3
   Explanation: The cube root of 27 is 3.

   Example 2:
   Input: N=2 M=16
   Output: 4
   Explanation: The square root of 16 is 4

   Example 3:
   Input: N=5 M=243
   Output: 3
   Explaination: The 5th root of 243 is 3
*/

#include <bits/stdc++.h>
using namespace std;

// return 1, if == m:
// return 0, if < m:
// return 2, if > m:
int func(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;
        if (ans > m)
            return 2;
    }
    if (ans == m)
        return 1;
    return 0;
}

int NthRoot(int n, int m)
{
    // Use Binary search on the answer space:
    int low = 1, high = m;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int midN = func(mid, n, m);
        if (midN == 1)
        {
            return mid;
        }
        else if (midN == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int n = 3, m = 27;
    int ans = NthRoot(n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
