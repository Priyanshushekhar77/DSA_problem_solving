// link->https://www.geeksforgeeks.org/problems/merge-sort/1
//  Given array is
//  38 27 43 3 9 82 10
//  Sorted array is
//  3 9 10 27 38 43 82
#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int mid, int r)
{
    // Your code here
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int arr1[n1];
    int arr2[n2];
    int k = l;
    //2 diff components of aaray
    for (int i = 0; i < n1; i++)
    {
        arr1[i] = arr[k];
        k++;
    }
    for (int i = 0; i < n2; i++)
    {
        arr2[i] = arr[k];
        k++;
    }
    int i = 0, j = 0;
    int ind = l;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            arr[ind] = arr1[i];
            i++;
            ind++;
        }
        else
        {
            arr[ind] = arr2[j];
            j++;
            ind++;
        }
    }
    while (i < n1)
    {
        arr[ind] = arr1[i];
        i++;
        ind++;
    }
    while (j < n2)
    {
        arr[ind] = arr2[j];
        j++;
        ind++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l == r)
        return;
    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

// Merge Sort is efficient for large datasets and guarantees a time complexity of O(n log n), but it requires additional space of O(N) for the temporary arrays used during the merging process.