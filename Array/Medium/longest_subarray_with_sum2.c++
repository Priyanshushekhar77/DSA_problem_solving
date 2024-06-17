// dealing with  positive ,Negative and zeroes

// this is optimal approach for dealing with positive,negative and zeroes.

#include <bits/stdc++.h>
using namespace std;
int getLongestSubarray(vector<int> &arr, int k)
{
    int n = arr.size(); // size of the array.

    map<int, int> prefixmp;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        // calculate the prefix sum till index i:
        sum += arr[i];

        // initially we have to do ,if the sum = k, update the maxLen:
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k: here x=sum
        int rem = sum - k;

        // Calculate the length and update maxLen:
        if (prefixmp.find(rem) != prefixmp.end())
        {
            int len = i - prefixmp[rem]; // currind - ind of remainder(x-k) => gives the len of target(k)
            maxLen = max(maxLen, len);
        }
        // Finally, update the map checking the conditions:
        // it is for example if arr=[2,0,0,3] k=2; so maxlen=3 otherwise maxlen becomes 1
        if (prefixmp.find(sum) == prefixmp.end())
        {
            prefixmp[sum] = i;
        }
    }

    return maxLen;
}

int main()
{
    vector<int> arr = {-1, 1, 1};
    int k = 1;
    int len = getLongestSubarray(arr, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}

// Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
// Reason: For example, if we are using an unordered_map data structure in C++ the time complexity will be O(N)(though in the worst case, unordered_map takes O(N) to find an element and the time complexity becomes O(N2)) but if we are using a map data structure, the time complexity will be O(N*logN). The least complexity will be O(N) as we are using a loop to traverse the array.

// Note: To know more about maps, please refer to this: Hashing | Maps | Time Complexity | Collisions | Division Rule of Hashing | Strivers A2Z DSA Course.

// Space Complexity: O(N) as we are using a map data structure.
