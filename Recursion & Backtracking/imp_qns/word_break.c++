// link->https://leetcode.com/problems/word-break/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_set<string> st;
    int n;
    bool solve(int ind, string &s, vector<int> &dp)
    {
        if (ind >= n)
        {
            return true; // Reached the end of the string
        }
        if (dp[ind] != -1)
        {
            return dp[ind]; // Return the stored result
        }
        for (int i = 1; i <= n - ind; i++)
        {
            string temp = s.substr(ind, i); // Get substring from ind of length i
            // index and length
            // find that substr that present in the dict or not and if present than serach for next word of dict from next index (ind+1) of string.
            if (st.find(temp) != st.end() && solve(ind + i, s, dp))
            {
                return dp[ind] = true;
            }
        }
        return dp[ind] = false;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        n = s.size();
        vector<int> dp(n, -1);
        for (auto it : wordDict)
        {
            st.insert(it);
        }
        return solve(0, s, dp); // Start the recursion from index 0
    }
};

int main()
{
    Solution sol;
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    cout << (sol.wordBreak(s, wordDict) ? "True" : "False") << endl;

    return 0;
}

// The time complexity is O(N(pow(2)))  here n is the length of string This is because for each index, the algorithm can look at all possible substrings.
// The space complexity isO(n) for the memoization table and the recursion stack. set also uses
// O(m) space where m is the total number of characters in the dictionary.