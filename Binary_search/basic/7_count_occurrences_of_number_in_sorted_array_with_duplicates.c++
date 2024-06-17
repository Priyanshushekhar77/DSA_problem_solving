/*
 * Count Occurrences in Sorted Array  => (lastpos - firstpos + 1;)

   Problem Statement: You are given a sorted array containing N integers and a number X, you have to find the occurrences of X in the given array.

   Examples:

   Example 1:
   Input: N = 7,  X = 3 , array[] = {2, 2 , 3 , 3 , 3 , 3 , 4}
   Output: 4
   Explanation: 3 is occurring 4 times in
   the given array so it is our answer.

   Example 2:
   Input: N = 8,  X = 2 , array[] = {1, 1, 2, 2, 2, 2, 2, 3}
   Output: 5
   Explanation: 2 is occurring 5 times in the given array so it is our answer.

   Count Occurrences in Sorted Array  => (lastpos - firstpos + 1;)
*/

// could also implemented with define function like int firstpos=firstocc(arr,x) and int lastpos=lastocc(arr,x);

int count(int arr[], int n, int x)
{
    // code here for finding firstpos
    int start = 0, end = n - 1, firstPos = -1, lastPos = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == x)
            firstPos = mid, end = mid - 1;
        else if (arr[mid] > x)
            end = mid - 1;
        else
            start = mid + 1;
    }
    // code here for finding lastpos
    start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == x)
            lastPos = mid, start = mid + 1;
        else if (arr[mid] < x)
            start = mid + 1;
        else
            end = mid - 1;
    }
    if (firstPos == -1)
        return 0;
    else
        return lastPos - firstPos + 1;
}