// You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.
// While there is a '*', do the following operation:
// Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
// Return the
// lexicographically smallest
//  resulting string after removing all '*' characters.
// Example 1:
// Input: s = "aaba*"
// Output: "aab"
// link->https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/description/
class Solution
{
public:
    // ALGO-> smallest elemnt ko large index se remove karo
    string clearStars(string s)
    {
        int n = s.size();
        vector<int> deleted(n, 0);
        vector<vector<int>> mp(26); // char and their presence of index stored
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '*')
            {
                // star milne pe smallest ele ke rightmost ind se remove karo
                for (auto it = 'a'; it <= 'z'; it++)
                {
                    if (mp[it - 'a'].size() != 0)
                    {
                        // map se smallest ele ka rightmost ind ko delete karo aur us ind(map ke back me present hoga ye) ko deleted vector me dalo
                        deleted[mp[it - 'a'].back()] = 1;
                        mp[it - 'a'].pop_back();
                        break;
                    }
                }
            }
            else
            {
                mp[s[i] - 'a'].push_back(i); // index push kar rahe hai each char ka
            }
        }
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] != '*' && !deleted[i])
            {
                ans += s[i];
            }
        }
        return ans;
    }
};