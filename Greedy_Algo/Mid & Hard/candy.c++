// There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
// You are giving candies to these children subjected to the following requirements:

// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// Return the minimum number of candies you need to have to distribute the candies to the children.
// Input: ratings = [1,0,2]
// Output: 5
// Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
// Example 2:
// Input: ratings = [1,2,2]
// Output: 4
// You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
// The third child gets 1 candy because it satisfies the above two conditions.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int candy(vector<int>& arr) {
    int n = arr.size();
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    left[0] = 1; // direction -->
    right[n-1] = 1; // direction <--

    for(int i = 1; i < n; i++) {
        if(arr[i] > arr[i-1]) {
            left[i] = left[i-1] + 1;
        } else {
            left[i] = 1;
        }
    }

    for(int i = n-2; i >= 0; i--) {
        if(arr[i] > arr[i+1]) {
            right[i] = right[i+1] + 1;
        } else {
            right[i] = 1;
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += max(left[i], right[i]);
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 0, 2}; // Example input

    cout << "Total candies needed: " << candy(arr) << endl;
    return 0;
}
//2.slope method to avoid space complexity
//   int n = arr.size();
//     if (n == 0) return 0;

//     int sum = 1, i = 1;
//     while (i < n) {
//         if (arr[i] == arr[i - 1]) {
//             sum++;
//             i++;
//             continue;
//         }

//         int peak = 1;
//         // Slope upwards
//         while (i < n && arr[i] > arr[i - 1]) {
//             peak++;
//             sum += peak;
//             i++;
//         }

//         int fall = 1;
//         // Slope downwards
//         while (i < n && arr[i] < arr[i - 1]) {
//             fall++;
//             sum += fall;
//             i++;
//         }

//         if (fall > peak) {
//             sum += (fall - peak);
//         }

//         // For flat sections
//         if (i < n && arr[i] == arr[i - 1]) {
//             sum++;
//             i++;
//         }
//     }
//return sum;
