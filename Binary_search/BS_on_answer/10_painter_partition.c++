/* Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘k’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.


You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards under a constraint that any painter will only paint the continuous sections of boards.

Example :
Input: arr = [2, 1, 5, 6, 2, 3], k = 2

Output: 11

Explanation:
First painter can paint boards 1 to 3 in 8 units of time and the second painter can paint boards 4-6 in 11 units of time. Thus both painters will paint all the boards in max(8,11) = 11 units of time. It can be shown that all the boards can't be painted in less than 11 units of time.
*/

// since here also dealing with answer lie between the range [maxele,sum(alleleemnt)] so simply apply binary search for optimal solution o(NlogN)

#include <bits/stdc++.h>
int getstudent(vector<int> &area, int mid)
{
    int cnt = 1;
    int pageno = 0;
    for (int i = 0; i < area.size(); i++)
    {
        if (pageno + area[i] > mid)
        {
            cnt++;
            pageno = area[i];
        }
        else
        {
            pageno += area[i];
        }
    }
    return cnt;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int n = boards.size();
    int ans = 0;
    if (k > n)
        return -1;                                          // painter>size
    int low = *max_element(boards.begin(), boards.end());   // to get max along arr
    int high = accumulate(boards.begin(), boards.end(), 0); // to get a  sum of arr
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int painter = getstudent(boards, mid);
        // since here also we dealing with minimize the max
        if (painter > k)
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