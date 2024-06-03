// link->https://leetcode.com/problems/fair-distribution-of-cookies/description/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int result = INT_MAX;
    int n;

    void solve(int idx, vector<int> &cookies, vector<int> &children, int k)
    {
        if (idx == n)
        {
            int ans = *max_element(children.begin(), children.end());
            result = min(result, ans);
            return;
        }

        int candy = cookies[idx];
        for (int i = 0; i < k; i++)
        {
            children[i] += candy;                 // Give candy to child i
            solve(idx + 1, cookies, children, k); // Recurse for next index
            children[i] -= candy;                 // Backtrack (remove candy from child i)
        }
    }

    int distributeCookies(vector<int> &cookies, int k)
    {
        n = cookies.size();
        vector<int> children(k, 0); // Initialize children with 0 cookies
        solve(0, cookies, children, k);
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> cookies = {1, 3, 5, 7, 9};
    int k = 2;
    int result = sol.distributeCookies(cookies, k);

    cout << "Minimum maximum cookies a child can get: " << result << endl;

    return 0;
}

// The time complexity of this algorithm is O(k^n), where n is the number of cookies and k is the number of children.
// This is because for each cookie, we have k choices (distribute it to one of the k children), and we have n cookies to distribute.