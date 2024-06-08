//  Q. Write a program to remove duplicates from Sorted Array and Return K where K is the Last position of distinct element.
//  * Example 1:

//    Input: arr[1,1,2,2,2,3,3]

//    Output: arr[1,2,3,_,_,_,_]

//    Explanation: Total number of unique elements are 3, i.e[1,2,3] and Therefore return 3 after assigning [1,2,3] in the beginning of the array.

#include <bits/stdc++.h>
using namespace std;

// BruteForce Appraoch:insert in set<int>st;
//          * Time complexity: O(N) & Space complexity: O(N)

// Solution 2: Time Complexity: O(N) & Space Complexity: O(1)
int removeDuplicates(int arr[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[j] != arr[i])
        {
            j++;
            arr[j] = arr[i];
        }
    }
    return j + 1;
}

int main()
{
    int arr[] = {1, 1, 2, 2, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = removeDuplicates(arr, n);
    cout << "The array after removing duplicate elements is " << endl;
    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }
}