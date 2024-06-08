// LINK->https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/?envType=list&envId=rgj5k9fi
//  Input: s = "abbaca"
//  Output: "ca"
//  Explanation:
//  For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

class Solution
{
public:
    // method 2-> STACK IMPLEMENTATION
    string removeDuplicates(string s)
    {
        string ans = "";
        for (int i = 0; i < s.length(); i++)
        {
            // agar adjacent element equal ho toh
            if (ans.length() > 0 && ans.back() == s[i])
            {
                ans.pop_back();
            }
            else
            {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};