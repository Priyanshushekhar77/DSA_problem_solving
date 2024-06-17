/* The floor of x is the largest element in the array which is smaller than or equal to x( i.e. largest element in the array <= x).
The ceiling of x is the smallest element in the array greater than or equal to x( i.e. smallest element in the array >= x). it is simply a lower bound algorithm

1. N = 8, X = 7
Arr[] = {5, 6, 8, 9, 6, 5, 5, 6}
Output: 6 8
Explanation:
Floor of 7 is 6 and ceil of 7
is 8.

Example 2:
Input:
N = 8, X = 10
Arr[] = {5, 6, 8, 9, 6, 5, 5, 6}
Output: 9 -1
Explanation:
Floor of 10 is 9 but ceil of 10 is not
possible.
*/

pair<int, int> getFloorAndCeil(int arr[], int n, int x)
{
    // code here
    sort(arr, arr + n);
    int floor = -1, ceil = -1;
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == x)
        {
            return {arr[mid], arr[mid]};
        }
        if (arr[mid] < x)
        {
            floor = arr[mid];
            s = mid + 1;
        }
        else
        { // arr[mid]>x
            ceil = arr[mid];
            e = mid - 1;
        }
    }
    return {floor, ceil};