/*

*/

/* bruteforce->
1. We will use a loop to traverse the array.
2. Inside the loop,
   a. If vec[i] <= k: we will simply increase the value of k by 1.
   b. Otherwise, we will break out of the loop.
3.Finally, we will return the value of k.
*/
#include <bits/stdc++.h>
using namespace std;

int missingK(vector<int> vec, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (vec[i] <= k)
            k++; // shifting k
        else
            break;
    }
    return k;
}

// optimal
/*
1. So, in the given array, the preceding neighbor of the kth missing number is vec[high].
2. Now, we know, up to index ‘high’,
the number of missing numbers = vec[high] - (high+1).
3. But we want to go further and find the kth number. To extend our objective, we aim to find the kth number in the sequence. In order to determine the number of additional missing values required to reach the kth position, we can calculate this as
more_missing_numbers = k - (vec[high] - (high+1)).
4. Now, we will simply add more_missing_numbers to the preceding neighbor i.e. vec[high] to get the kth missing number.
kth missing number = vec[high] + k - (vec[high] - (high+1))
        =  vec[high] + k - vec[high] + high + 1
        = k + high + 1.
*/

int missingK(vector<int> vec, int n, int k)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int missing = vec[mid] - (mid + 1);
        if (missing < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return k + high + 1;
}

int main()
{
    vector<int> vec = {4, 7, 9, 10};
    int n = 4, k = 4;
    int ans = missingK(vec, n, k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}

// Output:The missing number is: 5.