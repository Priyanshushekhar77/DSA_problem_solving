// link->https://leetcode.com/problems/palindrome-partitioning/description/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int n;

    bool valid(string &s, int st, int end)
    {
        while (st < end)
        {
            if (s[st] != s[end])
                return false;
            st++;
            end--;
        }
        return true;
    }

    void solve(string &s, int ind, vector<string> temp, vector<vector<string>> &ans)
    {
        if (ind == n)
        {
            ans.push_back(temp);
            return;
        }
        for (int i = ind; i < n; i++)
        {
            if (valid(s, ind, i))
            {
                // If it is a valid palindrome, include substring in temp, then further explore
                string curr = s.substr(ind, i - ind + 1); // currind, len
                temp.push_back(curr);
                // Explore
                solve(s, i + 1, temp, ans);
                // Undo
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        n = s.size();
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s, 0, temp, ans);
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "aab";
    vector<vector<string>> result = sol.partition(s);
    for (const auto &vec : result)
    {
        for (const auto &str : vec)
        {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}

// T.C-->>O(n*2(pow(n)))This is because for each character in the string, the algorithm can choose to either include it in the current substring or start a new substring. Validating a substring as a palindrome takes 𝑂(𝑛)
// O(n) time in the worst case.
// S.C->O(N) FOR RECURSIVE AND O(N(pow(2))) for storing palindrome