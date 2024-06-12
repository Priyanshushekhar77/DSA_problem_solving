/*
 * Longest Consecutive Sequence in an Array
   Problem Statement: You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.

   Examples:

   Example 1:
   Input: [100, 200, 1, 3, 2, 4]
   Output: 4
   Explanation: The longest consecutive subsequence is 1, 2, 3, and 4.

   Example 2:
   Input: [3, 8, 5, 7, 6]
   Output: 4

   Explanation: The longest consecutive subsequence is 5, 6, 7, and 8.
 */

#include <bits/stdc++.h>
using namespace std;

int longestSuccessiveElements(vector<int> &a)
{
    int n = a.size();
    if (n == 0)
        return 0;

    // sort the array:
    sort(a.begin(), a.end());
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    // find longest sequence:
    for (int i = 0; i < n; i++)
    {
        if (a[i] - 1 == lastSmaller)
        {
            // a[i] is the next element of the
            // current sequence.
            cnt += 1;
            lastSmaller = a[i];
        }
        else if (a[i] != lastSmaller)
        {
            cnt = 1;
            lastSmaller = a[i];
        }
        longest = max(longest, cnt);
    }
    return longest;
}

int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}
// T.C-> O(NLOGN) + O(N) AND S.C->O(1)

// Another soln for T.C->O(N) AND S.C-O(N)

/*Algorithm:
We will declare 2 variables,

‘cnt’ → (to store the length of the current sequence),
‘longest’ → (to store the maximum length).

1. First, we will put all the array elements into the set data structure.
2. For every element, x, that can be a starting number(i.e. x-1 does not exist in the set) we will do the following:
a) We will set the length of the current sequence(cnt) to 1.
b) Then, again using the set, we will search for the consecutive elements such as x+1, x+2, and so on, and find the maximum possible length of the current sequence. This length will be stored in the variable ‘cnt’.
c) After that, we will compare ‘cnt’ and ‘longest’ and update the variable ‘longest’ with the maximum value (i.e. longest = max(longest, cnt)).
3.Finally, we will have the answer i.e. ‘longest’.
*/
#include <bits/stdc++.h>
using namespace std;

int longestSuccessiveElements(vector<int> &a)
{
    int n = a.size();
    if (n == 0)
        return 0;

    int longest = 1;
    unordered_set<int> st;
    // put all the array elements into set:
    for (int i = 0; i < n; i++)
    {
        st.insert(a[i]);
    }

    // Find the longest sequence:
    for (auto it : st)
    {
        // if 'it' is a starting number:
        if (st.find(it - 1) == st.end())
        {
            // find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}
