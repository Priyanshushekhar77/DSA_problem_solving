// dealing with only positive and zeroes
// bruteforce T.C=> O(N(pow(2)))

// #include <bits/stdc++.h>
// using namespace std;

// int getLongestSubarray(vector<int>& a, int k) {
//     int n = a.size(); // size of the array.

//     int len = 0;
//     for (int i = 0; i < n; i++) { // starting index
//         int s = 0;
//         for (int j = i; j < n; j++) { // ending index
//             // add the current element to
//             // the subarray a[i...j-1]:
//             s += a[j];

//             if (s == k)
//                 len = max(len, j - i + 1);
//         }
//     }
//     return len;
// }

// int main()
// {
//     vector<int> a = { -1, 1, 1};
//     int k = 1;
//     int len = getLongestSubarray(a, k);
//     cout << "The length of the longest subarray is: " << len << "\n";
//     return 0;
// }

// OPTRIMAL

#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int> &arr, long long k)
{
    int n = arr.size(); // size of the array.

    int i = 0, j = 0; // 2 pointers
    long long sum = 0;
    int maxLen = 0;
    while (j < n)
    {
        sum += arr[j];
        // if sum = k, update the maxLen i.e. answer:
        if (sum == k)
        {
            maxLen = max(maxLen, j - i + 1);
        }
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        else if (sum > k)
        {
            while (i <= j && sum > k)
            {
                sum -= arr[i];
                i++;
            }
        }
        // Move forward thw right pointer:
        j++;
    }
    return maxLen;
}

int main()
{
    vector<int> arr = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(arr, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
