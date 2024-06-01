// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
// link->https://leetcode.com/problems/set-matrix-zeroes/description/

// =>BRUTEFORCE -> here we take an additional row and col and if any particular row or col in matrix is zero than we mark 1 on that additonal row and col.
// Time Complexity: O(2*(N*M)),
// Space Complexity: O(N) + O(M)

// vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int m, int n){
//     int row[m]={0};
//     int col[n]={0};
//     for(int i=0;i<m;i++){
//         for (int j=0;j<n;j++){
//             if(matrix[i][j]==0){
//                 //mark
//                 row[i]=1;
//                 col[j]=1;
//             }
//         }
//     }
//     // if row[i] or col[j] is marked with 1 than make corresponding pos equals to 0.
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             if (row[i] || col[j]) {
//                 matrix[i][j] = 0;
//             }
//         }
//     }
//     return matrix;
// }

// =>OPTIMAL ->To reduce the space complexity we store for tracking a 0 ,we do marking in first row and first col itself only extra space for variable topmostleft element for the purpose of marking col array;
// IMP->The marking will be like this: if cell(i, j) contains 0, we will mark the i-th row i.e. matrix[i][0] with 0 and we will mark j-th column i.e. matrix[0][j] with 0.
// If i is 0, we will mark matrix[0][0] with 0 but if j is 0, we will mark the col0 variable with 0 instead of marking matrix[0][0] again.
// Time Complexity: O(2*(N*M)),
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int m, int n)
{
    // 1.marking
    int col0 = 1; // variable for col array marking
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                // mark the first row to be zero
                matrix[i][0] = 0;
                // mark the first col to be zero
                if (j != 0)
                {
                    matrix[0][j] = 0;
                }
                else
                {
                    col0 = 0;
                }
            }
        }
    }
    // 2.placing from pos(1,1)->(m-1,n-1)
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] != 0)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    // 3.checking if matrix[0][0] is zero than make all the ele of column 0 to zero and if topmostleft variable for col0 is 0 than make all the ele of row 0 to zero.
    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[i][0] = 0;
        }
    }
    return matrix;
}
int main()
{
    vector<vector<int>> matrix = {{1, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {0, 1, 1, 1}};
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, m, n);

    cout << "The Final matrix is: ";
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}
