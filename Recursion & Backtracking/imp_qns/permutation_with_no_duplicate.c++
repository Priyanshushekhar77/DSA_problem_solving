
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    int n;
    unordered_set<int> st;

    void solve1(vector<int> temp, vector<int>& nums) {
        //base case
        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }
        //since here we have to deal with all the ele of nums array so in each recursive call we have to start a loop from first index and ignore the ele which is already present
        for (int i = 0; i < n; i++) {
            if (st.find(nums[i]) == st.end()) {
                // do
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                // explore
                solve1(temp, nums);
                // undo
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }

    void solve2(int ind, vector<int>& nums) {
        if (ind == n) {
            ans.push_back(nums);
            return;
        }
        for (int i = ind; i < n; i++) {
            // do
            swap(nums[i], nums[ind]);
            // explore
            solve2(ind + 1, nums);
            // undo
            swap(nums[i], nums[ind]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        // Method 1: Using set and temporary vector
        // vector<int> temp;
        // solve1(temp, nums);

        // Method 2: Using in-place swapping
        solve2(0, nums);

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.permute(nums);

    cout << "Permutations: " << endl;
    for (const auto& permutation : result) {
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

// Both methods have the same time and space complexity:

// Time Complexity: O(n * n!)
// Space Complexity: O(n)