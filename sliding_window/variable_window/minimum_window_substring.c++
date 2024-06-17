/* link-> https://leetcode.com/problems/minimum-window-substring/description/
Given two strings s and t of lengths m and n respectively, return the minimum window
substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
*/

string minWindow(string s, string t)
{
    int n = s.size();
    int m = t.size();
    // prestoring chars of string t in map
    unordered_map<char, int> mp;
    for (auto it : t)
        mp[it]++;
    int i = 0, j = 0, st_ind = -1, cnt = 0;
    int minlen = INT_MAX;
    while (j < n)
    {
        if (mp[s[j]] > 0)
            cnt++; // chars of string t finded in s
        mp[s[j]]--;
        while (cnt == m)
        { // when cnt becomes equal to size of string t
            // if it is equal than try to shrink the window as mauch as possible to get minlength
            if (j - i + 1 < minlen)
            {
                minlen = j - i + 1;
                st_ind = i;
            }
            // now shrink the window
            mp[s[i]]++;
            if (mp[s[i]] > 0)
                cnt--;
            i++;
        }
        j++;
    }
    return st_ind == -1 ? "" : s.substr(st_ind, minlen);
}
};
