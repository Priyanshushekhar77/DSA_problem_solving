// Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
// Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
// link->https://leetcode.com/problems/sort-the-matrix-diagonally/description/
// Time Complexity: O(m * n log(min(m, n)))(traversing on map and sorting each diagonal)
// Space Complexity: O(m * n)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    map<int, vector<int>> mp;

    // Populate the map with downward diagonals identified by (i - j)
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mp[i - j].push_back(mat[i][j]);
        }
    }

    // Sort each diagonal stored in the map
    for (auto &it : mp)
    {
        sort(it.second.begin(), it.second.end());
    }

    // Initialize the answer matrix with the same dimensions as mat
    vector<vector<int>> ans(m, vector<int>(n));

    // Populate the answer matrix with sorted diagonals
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            ans[i][j] = mp[i - j].back();
            mp[i - j].pop_back();
        }
    }

    return ans;
}
int main()
{
    vector<vector<int>> matrix = {{3, 3, 1, 1}, {2, 2, 1, 2}, {1, 1, 1, 2}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans2 = diagonalSort(matrix);

    cout << "The Final matrix is:";
    for (auto it : ans2)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "n";
    }
    return 0;
}