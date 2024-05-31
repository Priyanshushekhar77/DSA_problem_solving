// Input: matrix[][] =          {{  1,   2,   3,   4}
//                            {  5,   6,   7,   8}
//                            {  9, 10, 11, 12}
//                            {13, 14, 15, 16}
//                            {17, 18, 19, 20}}
// Output: 1 5 9 13 17 18 14 10 6 2 3 7 11 15 19 20 16 12 8 4
// T.C->O(N*M)
// S.C->0(1)
// link->https://www.geeksforgeeks.org/print-matrix-in-wave-form/

#include <bits/stdc++.h>
using namespace std;
vector<int> waveMatrix(vector<vector<int>> &matrix, int m, int n)
{
    vector<int>sol;
    for (int col = 0; col < n; col++)
    {
        // even case
        if (col % 2 == 0)
        {
            for (int row = 0; row < m; row++)
            {
                sol.push_back(matrix[row][col]);
            }
        }
        // odd case
        if (col % 2 != 0)
        {
            for (int row = m - 1; row >= 0; row--)
            {
                sol.push_back(matrix[row][col]);
            }
        }
    }
    return sol;
}
int main()
{
    vector<vector<int>> matrix =  {{  1,   2,   3,   4},
                           {  5,   6,   7,   8},
                           {  9, 10, 11, 12},
                           {13, 14, 15, 16},
                           {17, 18, 19, 20}};
    int m = matrix.size();
    int n = matrix[0].size();
    
    vector<int> ans = waveMatrix(matrix, m, n);

    cout << "The Final matrix is: ";
    for (auto it : ans)
    {

        cout << it << " ";
    }
    return 0;
}