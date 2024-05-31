// search in a row and column-wise sorted matrix

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.
// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
// Output: true

// => BRUTEFORCE -> we are traversing on each row and col and checking for a target
// Time Complexity: O(N X M)
// bool searchElement(vector<vector<int>>& matrix, int target) {
//     int m = matrix.size(), n = matrix[0].size();

//     //traverse the matrix:
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             if (matrix[i][j] == target)
//                 return true;
//         }
//     }
//     return false;
// }

// =>BETTER ->The question specifies that each row and col in the given matrix is sorted. Therefore, to determine if the target is present in a specific row or col,apply B.S on row or col.
// Time Complexity: O(M*logN), where M= given row number, N= given column number.
// Reason: We are traversing all rows and it takes O(M) time complexity. And for all rows, we are applying binary search. So, the total time complexity is O(M*logN).

// bool binarySearch(vector<int>& nums, int target) {
//     int n = nums.size(); //size of the array
//     int low = 0, high = n- 1;

//     // Perform the steps:
//     while (low <= high) {
//         int mid = (low + high) / 2;
//         if (nums[mid] == target) return true;
//         else if (target > nums[mid]) low = mid + 1;
//         else high = mid - 1;
//     }
//     return false;
// }

// bool searchElement(vector<vector<int>>& matrix, int target) {
//     int m = matrix.size();

//     for (int i = 0; i < m; i++) {
//         bool check =  binarySearch(matrix[i], target);
//         if (check) return true;
//     }
//     return false;
// }

// =>OPTIMAL ->we are at topmostright pos and from where
// If matrix[n-1][0] < target: We should move row-wise.
// If matrix[n-1][0] > target: We need smaller elements and so we should move column-wise.
// Time Complexity: O(N+M)
#include <bits/stdc++.h>
using namespace std;
bool searchElement(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    // topmostright pos
    int row = 0, col = n - 1;
    // traverse the matrix from (0, m-1)
    while (row < m && col >= 0)
    {
        int pos = matrix[row][col];
        if (pos == target)
            return true;
        else if (pos < target)
            row++;
        else
            col--;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    searchElement(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}
