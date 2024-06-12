/*
 * 3 Sum : Find triplets that add up to a zero
   Problem Statement: Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero. In short, you need to return an array of all the unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.

   Examples:

   Example 1:
   Input: nums = [-1,0,1,2,-1,-4]
   Output: [[-1,-1,2],[-1,0,1]]
   Explanation: Out of all possible unique triplets possible, [-1,-1,2] and [-1,0,1] satisfy the condition of summing up to zero with i!=j!=k

   Example 2:
   Input: nums=[-1,0,1,0]
   Output: Output: [[-1,0,1],[-1,1,0]]
   Explanation: Out of all possible unique triplets possible, [-1,0,1] and [-1,1,0] satisfy the condition of summing up to zero with i!=j!=k
 */

// bruteforce
vector<vector<int>> triplet(int n, vector<int> &arr)
{
    set<vector<int>> st;

    // check all possible triplets:
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    // store the set elements in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

/*better  => arr[k] = target - (arr[i]+arr[j]+arr[k]) = 0-(arr[i]+arr[j]+arr[k]) = -(arr[i]+arr[j]+arr[k])
So, we will first calculate arr[i] and arr[j] using 2 loops and for the third one i.e. arr[k] we will not use another loop and instead we will look up the value 0-(arr[i]+arr[j]+arr[k]) in the set data structure. Thus we can remove the third loop from the algorithm.

For implementing the search operation of the third element,  we will store all the elements between the indices i and j in a HashSet and then we will search for the third element in the HashSet.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> &arr)
{
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            // Calculate the 3rd element:
            int third = -(arr[i] + arr[j]);

            // Find the element in the set:
            if (hashset.find(third) != hashset.end())
            {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    // store the set in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
/*Time Complexity: O(N2 * log(no. of unique triplets)), where N = size of the array.
Reason: Here, we are mainly using 3 nested loops. And inserting triplets into the set takes O(log(no. of unique triplets)) time complexity. But we are not considering the time complexity of sorting as we are just sorting 3 elements every time.

Space Complexity: O(2 * no. of the unique triplets) + O(N) as we are using a set data structure and a list to store the triplets and extra O(N) for storing the array elements in another set.
*/

/*
OPTIMAL=> Time Complexity: O(NlogN)+O(N2), where N = size of the array.

*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> &arr)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        // remove duplicates:
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        // moving 2 pointers:
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                // skip the duplicates:
                while (j < k && arr[j] == arr[j - 1])
                    j++;
                while (j < k && arr[k] == arr[k + 1])
                    k--;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (auto it : ans)
    {
        cout << "[";
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}
