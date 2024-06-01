// link->https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/description/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<int> rowone(m, 0);
    vector<int> colone(n, 0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                rowone[i]++;
                colone[j]++;
            }
        }
    }
    vector<vector<int>> diff(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int row1 = rowone[i];
            int row0 = m - row1;
            int col1 = colone[j];
            int col0 = n - col1;
            diff[i][j] = row1 + col1 - row0 - col0;
        }
    }
    return diff;
}