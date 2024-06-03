
// LINK->https://leetcode.com/problems/non-decreasing-subsequences/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int n;
    void solve(vector<int> &nums, int ind, vector<int> &curr, vector<vector<int>> &ans)
    {
        if (curr.size() > 1)
        {
            ans.push_back(curr);
        }
        unordered_set<int> st; // forchecking ele in each rec call during returning
        for (int i = ind; i < n; i++)
        {
            if (curr.empty() || nums[i] >= curr.back() && st.find(nums[i]) == st.end())
            {
                curr.push_back(nums[i]);
                solve(nums, i + 1, curr, ans);
                curr.pop_back();//pop karne ke baad set me insert kardenge prev ele ka track rakhne ke liye
                st.insert(nums[i]);
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        n = nums.size();
        vector<vector<int>> ans;
        vector<int> curr;
        solve(nums, 0, curr, ans);
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {4, 6, 7, 7};
    vector<vector<int>> result = sol.findSubsequences(nums);

    cout << "Unique Increasing Subsequences: " << endl;
    for (const auto &subsequence : result)
    {
        for (int num : subsequence)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

// The time complexity of this approach is O(2^n)