// link->https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-matrix/problem/unique-rows-in-boolean-matrix

// row = 3, col = 4
// M[][] = {{1 1 0 1},{1 0 0 1},{1 1 0 1}}
// Output: $1 1 0 1 $1 0 0 1 $

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> uniqueRow(int M[3][3], int row, int col)
{
    // Your code here
    map<vector<int>, int> mp;
    vector<vector<int>> ans;
    for (int i = 0; i < row; i++)
    {
        vector<int> rows;
        for (int j = 0; j < col; j++)
        {
            rows.push_back(M[i][j]);
        }
        // if particular row is not present in the map
        if (mp.find(rows) == mp.end())
        {
            mp[rows]++;
            ans.push_back(rows);
        }
        // if present than skip
        else
        {
            continue;
        }
    }
    return ans;
};
