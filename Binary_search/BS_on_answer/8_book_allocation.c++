/*
 * Allocate Minimum Number of Pages
   Problem Statement: Given an array of integers A of size N and an integer B.

   The College library has N bags, the ith book has A[i] number of pages.

   You have to allocate books to B number of students so that the maximum number of pages allocated to a student is minimum.

   Conditions given :

   A book will be allocated to exactly one student.

   Each student has to be allocated at least one book.

   Allotment should be in contiguous order, for example, A student cannot be allocated book 1 and book 3, skipping book 2.

   Calculate and return the minimum possible number. Return -1 if a valid assignment is not possible.
   Examples:

   Example 1:

   Input: A = [12, 34, 67, 90]
          B = 2
   Output: 113
   Explaination: Let’s see all possible cases of how books can be allocated for each student.
   So, the maximum number of pages allocated in each case is [191,157,113]. So, the minimum number among them is 113. Hence, our result is 113.
*/

#include <bits/stdc++.h>
int getstudent(vector<int> &page, int mid)
{
    int cnt = 1;
    int pageno = 0;
    for (int i = 0; i < page.size(); i++)
    {
        if (pageno + page[i] > mid)
        {
            cnt++;
            pageno = page[i];
        }
        else
        {
            pageno += page[i];
        }
    }
    return cnt;
}
int findPages(vector<int> &arr, int n, int m)
{
    // Write your code here.
    int ans = 0;
    if (m > n)//student>size
        return -1;
    int low = *max_element(arr.begin(), arr.end());   // to get max along arr
    int high = accumulate(arr.begin(), arr.end(), 0); // to get a  sum of arr
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int student = getstudent(arr, mid);
        if (student > m)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}