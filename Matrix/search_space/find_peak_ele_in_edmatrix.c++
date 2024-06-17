/*
Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
Output: [1,1]
Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.
*/

// determining maximum row index of particular col equal to mid
int find(vector<vector<int>> &mat, int row, int col, int mid)
{
    int maxi = -1;
    int ind = -1;
    for (int i = 0; i < row; i++)
    {
        if (maxi < mat[i][mid])
        {
            maxi = mat[i][mid];
            ind = i;
        }
    }
    return ind;
}
vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    int row = mat.size();
    int col = mat[0].size();
    int s = 0, e = col - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;                // for column
        int maxrowind = find(mat, row, col, mid); // gives maximum row index
        // now compare the left and right part of max row index value becz it is already greater than its upper and lower part
        int leftpart = mid - 1 >= 0 ? mat[maxrowind][mid - 1] : -1;
        int rightpart = mid + 1 < col ? mat[maxrowind][mid + 1] : -1;
        // if maxrow index value(mat[maxrowind][mid]) is greater than left and right part than it is peak element
        if (mat[maxrowind][mid] > leftpart && mat[maxrowind][mid] > rightpart)
        {
            return {maxrowind, mid}; // row and col
        }
        else if (mat[maxrowind][mid] < leftpart)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return {-1, -1};
}