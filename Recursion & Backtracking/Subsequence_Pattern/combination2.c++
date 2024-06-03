#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int n;

    void solve(int ind, vector<int> &arr, int target, vector<vector<int>> &ans, vector<int> &temp)
    {
        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if (ind >= n || target < 0)
            return;

        temp.push_back(arr[ind]);
        solve(ind, arr, target - arr[ind], ans, temp); // Take and explore further with the same element
        temp.pop_back();
        solve(ind + 1, arr, target, ans, temp); // Skip to the next element
    }

    vector<vector<int>> combinationSum(vector<int> &arr, int target)
    {
        n = arr.size();
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, arr, target, ans, temp);
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = sol.combinationSum(arr, target);

    cout << "Combinations that sum up to " << target << ":" << endl;
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
// the time complexity is O(2^n), and the space complexity is O(n * k + 2^n).