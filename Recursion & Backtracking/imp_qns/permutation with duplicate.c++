#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int n;
    vector<vector<int>> ans;

    void solve(int ind, vector<int> &nums)
    {
        if (ind == n)
        {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> uniqueSet;
        for (int i = ind; i < n; i++)
        {
            if (uniqueSet.count(nums[i]) > 0)
            { // if cnt of ele is greater than 1 than it led to be duplicate permutation formes so skip it
                continue;
            }
            // insert the ele into set
            uniqueSet.insert(nums[i]);
            // DO
            swap(nums[i], nums[ind]);
            // Explore
            solve(ind + 1, nums);
            // Undo
            swap(nums[i], nums[ind]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        n = nums.size();
        solve(0, nums);
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = sol.permuteUnique(nums);

    cout << "Unique Permutations: " << endl;
    for (const auto &permutation : result)
    {
        for (int num : permutation)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
