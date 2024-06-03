// link-https://www.geeksforgeeks.org/problems/quick-sort/1
#include <bits/stdc++.h>
using namespace std;
class QuickSort
{
public:
    void quickSort(int arr[], int l, int h)
    {
        if (l >= h)
            return;
        int pind = partition(arr, l, h); //from pind to left all the ele are less than pind ele and to right all the ele are greater than pind ele.
        quickSort(arr, l, pind - 1);
        quickSort(arr, pind + 1, h);
    }

    int partition(int arr[], int l, int h)
    {
        int pivot = arr[h];
        int ind = l;
        for (int i = l; i < h; i++)
        {
            if (arr[i] < pivot)
            {
                swap(arr[i], arr[ind]);
                ind++;
            }
        }
        //swap ind ele pos with pivot ele pos to make it at corect pos
        swap(arr[ind], arr[h]);
        return ind;
    }
};

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, arr_size);

    QuickSort qs;
    qs.quickSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}

// For Merge sort worst case is O(n*log(n)), for Quick sort: O(n2). For other cases (avg, best) both have O(n*log(n)). However Quick sort is space constant where Merge sort depends on the structure you're sorting.
// Quick sort is typically faster than merge sort when the data is stored in memory.
