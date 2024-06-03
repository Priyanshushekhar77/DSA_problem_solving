// Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

// You may return the answer in any order.Input: n = 4, k = 2
// Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;

    void solve(int start, int n, int k, vector<int> &temp)
    {
        if (k == 0)
        {
            ans.push_back(temp);
            return;
        }
        if (start > n)
            return;

        temp.push_back(start);
        solve(start + 1, n, k - 1, temp); // take
        temp.pop_back();
        solve(start + 1, n, k, temp); // nottake
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<int> temp;
        solve(1, n, k, temp);//start=1 ; end=4; noformeddigit=2
        return ans;
    }
};

int main()
{
    Solution sol;
    int n = 4, k = 2;
    vector<vector<int>> result = sol.combine(n, k);

    cout << "Combinations of " << k << " numbers chosen from 1 to " << n << ":" << endl;
    for (const auto &combination : result)
    {
        cout << "[";
        for (int num : combination)
        {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
// the time complexity is O(2^n), and the space complexity is O(n choose k)