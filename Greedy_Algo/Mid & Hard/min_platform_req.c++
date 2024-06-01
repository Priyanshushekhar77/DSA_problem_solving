// link->https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
//  arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
//  dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
//  Output: 3
//  Minimum 3 platforms are required to
//  safely arrive and depart all trains.

#include <bits/stdc++.h>
using namespace std;
int findPlatform(int arr[], int dep[], int n)
{
    // two pointer approach
    sort(arr, arr + n);
    sort(dep, dep + n);
    int req = 0;
    int i = 0, j = 0, cnt = 0;
    while (i < n)
    {
        if (arr[i] <= dep[j])
        { // arrival time of index i is less than departure time of index j
            cnt++;
            i++;
        }
        else
        {
            cnt--;
            j++;
        }
        req = max(req, cnt);
    }
    return req;
}
// T.C->O(NLOGN + N)