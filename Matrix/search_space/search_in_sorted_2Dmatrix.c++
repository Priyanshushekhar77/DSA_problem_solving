// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3(the first element of a row is greater than the last element of the previous row (if it exists))
// Output: true

// =>BRUTEFORCE ->traverse on each row and col
// Time Complexity: O(N X M),

// bool searchMatrix(vector<vector<int>>& matrix, int target) {
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

// BETTER => check for each row and if target may exist between any point in any row than apply binary search on that row becz A/Q; startind index of next row is grt than last ind of prev row.
// Time Complexity: O(N + logM), where N = given row number, M = given column number.
// Reason: We are traversing all rows and it takes O(N) time complexity. But for all rows, we are not applying binary search rather we are only applying it once for a particular row. That is why the time complexity is O(N + logM) instead of O(N*logM).

// bool binarySearch(vector<int>& nums, int target) {
//     int m = nums.size(); //size of the array
//     int low = 0, high = m - 1;

//     // Perform the steps:
//     while (low <= high) {
//         int mid = (low + high) / 2;
//         if (nums[mid] == target) return true;
//         else if (target > nums[mid]) low = mid + 1;
//         else high = mid - 1;
//     }
//     return false;
// }
// bool searchMatrix(vector<vector<int>>& matrix, int target) {
//     int m = matrix.size();
//     int n = matrix[0].size();

//     for (int i = 0; i < m; i++) {
//         if (matrix[i][0] <= target && target <= matrix[i][m - 1]) {
//             return binarySearch(matrix[i], target);
//         }
//     }
//     return false;
// }

// OPTIMAL=>flatten the 2D array into 1D array whereas s=0,e=m*n-1 and row=mid/n,col=mid%n and apply binary search on 1D array;
// Time Complexity: O(log(NxM)), where M= given row number, N = given column number.

#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int s = 0, e = m * n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        int row = mid / n;
        int col = mid % n;
        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] < target)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return false;
}
int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    searchMatrix(matrix, 3) == true ? cout << "true\n" : cout << "false\n";
}