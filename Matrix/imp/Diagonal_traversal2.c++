// //link->https://leetcode.com/problems/diagonal-traverse-ii/
// Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,4,2,7,5,3,8,6,9]

#include <bits/stdc++.h>
using namespace std;
vector<int> diagonal2(vector<vector<int>> &mat)
{
    vector<int> ans;
    unordered_map<int, vector<int>> mp;
    // as for filling in ans ;for avoid of doing reverse of strored ele in map ;we start a filling from last row so that we get ele in rev order
    for (int i = mat.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            mp[i + j].push_back(mat[i][j]);
        }
    }
    int diag = 0;
    while (mp.find(diag) != mp.end())
    {
        for (auto it : mp[diag])
        {
            ans.push_back(it);
        }
        diag++;
    }
    return ans;
}
int main()
{
    vector<vector<int>> mat{{1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9}};
    vector<int> ans = diagonal2(mat);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}