#include <bits/stdc++.h>
using namespace std;
// link--https://leetcode.com/problems/valid-parenthesis-string/description/
class Solution
{
public:
    bool checkValidString(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n * 2, -1)); // Memoization table
        bool ans = solve(s, 0, 0, dp);                     // ind=0 cnt=0
        return ans;
    }

private:
    bool solve(const string &s, int ind, int cnt, vector<vector<int>> &dp)
    {
        if (cnt < 0)
            return false; // More ')' than '('
        if (ind == s.size())
            return cnt == 0; // All characters processed, valid if count is zero

        if (dp[ind][cnt + s.size()] != -1)
            return dp[ind][cnt + s.size()]; // Check memo table

        if (s[ind] == '(')
        {
            dp[ind][cnt + s.size()] = solve(s, ind + 1, cnt + 1, dp);
        }
        else if (s[ind] == ')')
        {
            dp[ind][cnt + s.size()] = solve(s, ind + 1, cnt - 1, dp);
        }
        else
        {                                                               // s[ind] == '*'
            dp[ind][cnt + s.size()] = solve(s, ind + 1, cnt + 1, dp) || // Treat '*' as '('
                                      solve(s, ind + 1, cnt - 1, dp) || // Treat '*' as ')'
                                      solve(s, ind + 1, cnt, dp);       // Treat '*' as nottake
        }

        return dp[ind][cnt + s.size()];
    }
};

int main()
{
    Solution sol;
    string s = "(*))"; // Example input
    bool result = sol.checkValidString(s);
    cout << (result ? "true" : "false") << endl;

    return 0;
}
