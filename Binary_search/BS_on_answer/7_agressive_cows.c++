/*
 * Aggressive Cows : Detailed Solution
   Problem Statement: There is a new barn with N stalls and C cows. The stalls are located on a straight line at positions x1,….,xN (0 <= xi <= 1,000,000,000). We want to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

   Examples:

   Input: No of stalls = 5
          Array: {1,2,8,4,9}
          And number of cows: 3

   Output: One integer, the largest minimum distance 3

*/

#include <bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> &stalls, int dist, int cows)
{
    int n = stalls.size(); // size of array
    int cntCows = 1;       // no. of cows placed
    int last = stalls[0];  // position of last placed cow.
    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - last >= dist)
        {
            cntCows++;        // place next cow.
            last = stalls[i]; // update the last location.
        }
        if (cntCows >= cows)
            return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size(); // size of array
    // sort the stalls[]:
    sort(stalls.begin(), stalls.end());
    int ans = 0;
    int low = 1, high = stalls[n - 1] - stalls[0];
    // apply binary search:
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, k) == true)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}

int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}

// Output:The maximum possible minimum distance is: 3.