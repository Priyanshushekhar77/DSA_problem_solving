/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).



Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/

/*
Bruteforce->
1.put nums1 and nums2 in temp vector of size=n+m
2.sort them
3.if size is odd return temp[size/2] else its even then return (temp[size/2 -1] + temp[size/2]) /2;

step 1 and 2 time comp can reduced if we apply merge method other applying than sort
while(i<m && j<n){
    if(nums[i]<nums[j]) temp.push_back(nums[i]) i++;
    else temp.push_back(nums[j]) j++;
}
*/

// better
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &arr1, vector<int> &arr2)
    {
        vector<int> temp;
        int first = -1;
        int sec = -1;
        int k = 0;
        int m = arr1.size();
        int n = arr2.size();
        int a = (m + n) / 2;//mid index
        int b = a - 1;//mid-1 index
        int i = 0, j = 0;
        while (i < m && j < n)
        {
            if (arr1[i] < arr2[j])
            {
                temp.push_back(arr1[i]);
                i++;
                k++;
                if (k == a)
                    first = arr1[i];
                if (k == b)
                    sec = arr1[i];
            }
            else
            {
                temp.push_back(arr2[j]);
                j++;
                k++;
                if (k == a)
                    first = arr2[j];
                if (k == b)
                    sec = arr2[j];
            }
        }
        while (i < m)
        {
            temp.push_back(arr1[i]);
            i++;
            k++;
            if (k == a)
                first = arr1[i];
            if (k == b)
                sec = arr1[i];
        }
        while (j < n)
        {
            temp.push_back(arr2[j]);
            j++;
            k++;
            if (k == a)
                first = arr2[j];
            if (k == b)
                sec = arr2[j];
        }
        if ((m + n) % 2 == 1)
            return temp[a];
        else
            return (temp[a] + temp[b]) / 2.0;
    }
};

// OPTIMAL
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &arr1, vector<int> &arr2)
    {
        if (arr1.size() > arr2.size())
            return findMedianSortedArrays(arr2, arr1);
        int m = arr1.size();
        int n = arr2.size();
        int low = 0, high = m;
        while (low <= high)
        {
            int a1 = low + (high - low) / 2;
            int a2 = (m + n + 1) / 2 - a1;
            int x1 = (a1 == 0) ? INT_MIN : arr1[a1 - 1];
            int x2 = (a2 == 0) ? INT_MIN : arr2[a2 - 1];
            int x3 = (a1 == m) ? INT_MAX : arr1[a1];
            int x4 = (a2 == n) ? INT_MAX : arr2[a2];

            if (x1 <= x4 && x2 <= x3)
            {
                if ((m + n) % 2 == 1)
                    return max(x1, x2);
                else
                    return (max(x1, x2) + min(x3, x4)) / 2.0;
            }
            if (x1 > x4)
                high = a1 - 1;
            else
                low = a1 + 1;
        }
        return 0.0;
    }
};