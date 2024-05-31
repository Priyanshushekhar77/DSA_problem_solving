// Input:
// [[1, 2, 3],
//  [4, 5, 6],
//  [7, 8, 9]]

// Output:
// [
// [1],
// [2, 4],
// [3, 5, 7],
// [6, 8],
// [9]
// ]
// =>APPROACH ->1.for the upper half traverse and store in ans from row=0,col=j=0; and row++,col--;
//             2.for the lower half traverse and store in ans from row=j=1,col=n-1; and row++,col--;
#include <bits/stdc++.h>
using namespace std;
vector<int> antidiagonal(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    vector<int>ans;
    for (int j = 0; j < n; j++)
    {
        int row = 0, col = j;
        while (row < m && col >= 0)
        {
            ans.push_back(mat[row][col]);
            row++;
            col--;
        }
    }
    for (int j = 1; j < n; j++)
    {
        int row = j, col = n - 1;
        while (row < m && col >= 0)
        {
            ans.push_back(mat[row][col]);
            row++;
            col--;
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> mat{{1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9}};
    vector<int> ans = antidiagonal(mat);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}