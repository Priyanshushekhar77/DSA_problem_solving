// link->https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/
#include <bits/stdc++.h>
using namespace std;
int maxWidthOfVerticalArea(vector<vector<int>> &points)
{
    sort(points.begin(), points.end());
    int area = 0;
    for (int i = 1; i < points.size(); i++)
    {
        area = max(area, points[i][0] - points[i - 1][0]);
    }
    return area;
}