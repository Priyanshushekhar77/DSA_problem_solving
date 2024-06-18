/* https://leetcode.com/problems/apply-operations-to-make-string-empty/description/

For every alphabet character from 'a' to 'z', remove the first occurrence of that character in s (if it exists).
For example, let initially s = "aabcbbca". We do the following operations:

Remove the underlined characters s = "aabcbbca". The resulting string is s = "abbca".
Remove the underlined characters s = "abbca". The resulting string is s = "ba".
Remove the underlined characters s = "ba". The resulting string is s = "".
Return the value of the string s right before applying the last operation. In the example above, answer is "ba".



Example 1:

Input: s = "aabcbbca"
Output: "ba"
Explanation: Explained in the statement.
Example 2:

Input: s = "abcd"
Output: "abcd"
Explanation: We do the following operation:
- Remove the underlined characters s = "abcd". The resulting string is s = "".
The string just before the last operation is "abcd".
*/

string lastNonEmptyString(string s)
{
    unordered_map<char, int> mp;
    int maxfreq = 0;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
        maxfreq = max(maxfreq, mp[s[i]]);
    }
    string ans = "";
    unordered_map<char, int> mp2;
    for (int i = 0; i < s.size(); i++)
    {
        mp2[s[i]]++;
        if (mp2[s[i]] == maxfreq)
            ans += s[i];
    }
    return ans;
}