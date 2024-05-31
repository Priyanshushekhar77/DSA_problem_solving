// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]
// Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
// Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
// link->https://leetcode.com/problems/rotate-image/description/
// =>BRUTEFORCE->Take another dummy matrix of n*n, and then take the first row of the matrix and put it in the last column of the dummy matrix, take the second row of the matrix, and put it in the second last column of the matrix and so.
// Time Complexity: O(N*N)
// SPACE Complexity: O(N*N)

// =>OPTIMAL -> first find transpose of matrix than reverse the each row of matrix.
// A/Q;IF IT HAVE TO BE ROTATE IN 90 degree ANTI-CLOCKWISE DIRECTION;
// a)than ,first reverse each row;
// b)than, swap the element;
// Time Complexity: O(N*N) + O(N*N).One O(N*N) is for transposing the matrix and the other is for reversing the matrix.
// Space Complexity: O(1).

#include <bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>> &matrix)
{

    int m = matrix.size();
    int n = matrix[0].size();
    // transposing the matrix by swaping the ele of corresponding row and col
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // reversing each row of the matrix
    for (int i = 0; i < m; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
int main()
{
    vector<vector<int>> arr;
    arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(arr);
    int m = arr.size();
    int n = arr[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}