// link->https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

// Input: points = [[10,16],[2,8],[1,6],[7,12]]
// Output: 2
// Explanation: The balloons can be burst by 2 arrows:
// - Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
// - Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
#include <bits/stdc++.h>
using namespace std;
int findMinArrowShots(vector<vector<int>> &points)
{
    sort(points.begin(), points.end());
    vector<int> prev = points[0]; // as a pair
    int cnt = 1;
    for (int i = 1; i < points.size(); i++)
    {
        int currstartpt = points[i][0];
        int currendpt = points[i][1];
        int prevstartpt = prev[0];
        int prevendpt = prev[1];
        if (currstartpt > prevendpt)
        {
            cnt++;
            prev = points[i]; // overlap nahi ho rha hai isliye prev ko next pe kar diye hai
        }
        else
        { // pakka overlap ho rha hai
            // overlapping region nikal rahe hai...taki next ind se compare kare
            prev[0] = max(prevstartpt, currstartpt);
            prev[1] = min(prevendpt, currendpt);
        }
    }
    return cnt;
}