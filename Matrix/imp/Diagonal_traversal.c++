// Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.
// //link->https://leetcode.com/problems/diagonal-traverse/description/
// Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
// A/Q;in each next step we have to reverse the dirn and than store
// Output: [1,2,4,7,5,3,6,8,9]
// The total complexity for processing the map is O((m + n - 1) * min(m, n)) + O(m * n), which simplifies to O(m * n).
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

#include <bits/stdc++.h>
using namespace std;
vector<int> findDiagonalOrder(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    vector<int> ans;
    map<int, vector<int>> mp;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mp[i + j].push_back(mat[i][j]);
        }
    }
    bool flip = true;
    for (auto it : mp)
    {
        if (flip)
        {
            reverse(it.second.begin(), it.second.end());
        }
        for (auto it2 : it.second)
        {
            ans.push_back(it2);
        }
        flip = !flip;
    }
    return ans;
}
int main()
{
    vector<vector<int>> mat{{1, 2, 3, 4},
                            {5, 6, 7, 8},
                            {9, 10, 11, 12},
                            {13, 14, 15, 16}};
    vector<int> ans = findDiagonalOrder(mat);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}