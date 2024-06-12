/*
 * Leaders in an Array
   Problem Statement: Given an array, print all the elements which are leaders. A Leader is an element that is greater than all of the elements on its right side in the array.

   Examples:

   Example 1:
   Input:
    arr = [4, 7, 1, 0]
   Output:
    7 1 0
   Explanation:
    Rightmost element is always a leader. 7 and 1 are greater than the elements in their right side.

   Example 2:
   Input:
    arr = [10, 22, 12, 3, 0, 6]
   Output:
    22 12 6
   Explanation:
    6 is a leader. In addition to that, 12 is greater than all the elements in its right side (3, 0, 6), also 22 is greater than 12, 3, 0, 6.
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> printLeaders(int arr[], int n)
{

    vector<int> ans;

    // Last element of an array is always a leader,
    // push into ans array.
    int max = arr[n - 1];
    ans.push_back(arr[n - 1]);

    // Start checking from the end whether a number is greater
    // than max no. from right, hence leader.
    for (int i = n - 2; i >= 0; i--)
        if (arr[i] > max)
        {
            ans.push_back(arr[i]);
            max = arr[i];
        }

    return ans;
}

int main()
{

    // Array Initialization.
    int n = 6;
    int arr[n] = {10, 22, 12, 3, 0, 6};

    vector<int> ans = printLeaders(arr, n);

    for (int i = ans.size() - 1; i >= 0; i--)
    {

        cout << ans[i] << " ";
    }

    cout << endl;
    return 0;
}
