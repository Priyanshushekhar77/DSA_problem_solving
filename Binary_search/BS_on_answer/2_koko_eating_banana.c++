/*
 * Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

   Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

   Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

   Return the minimum integer k such that she can eat all the bananas within h hours.

   Example 1:
   Input: piles = [3,6,7,11], h = 8
   Output: 4

   Example 2:
   Input: piles = [30,11,23,4,20], h = 5
   Output: 30

   Example 3:
   Input: piles = [30,11,23,4,20], h = 6
   Output: 23

*/

// Bruteforce

#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &v)
{
    int maxi = INT_MIN;
    int n = v.size();
    // find the maximum:
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}
int calculateTotalHours(vector<int> &v, int hourly)
{
    int totalH = 0;
    int n = v.size();
    // find total hours:
    for (int i = 0; i < n; i++)
    {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}

int minimumRateToEatBananas(vector<int> v, int h)
{
    // Find the maximum number:
    int maxi = findMax(v);
    // Find the minimum value of k:
    for (int i = 1; i <= maxi; i++)
    {
        int reqTime = calculateTotalHours(v, i);
        if (reqTime <= h)
        {
            return i;
        }
    }
    return maxi;
}
int main()
{
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minimumRateToEatBananas(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}

// since here answer lies between the ranges[1,maxele] so simply apply the binary search for the optimal solution

long long checkhours(vector<int> &piles, int mid)
{
    long long cnt = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        cnt += ceil(piles[i] / (double)mid);
    }
    return cnt;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int s = 1;
    // Max speed to eat
    int e = *max_element(piles.begin(), piles.end());
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        // Total time taken to eat bananas
        long long totalTime = checkhours(piles, mid);
        // Since we have to find minimum speed , we need to keep checking for lowest possible speed
        if (totalTime <= h)
        {
            ans = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    return ans;
}
