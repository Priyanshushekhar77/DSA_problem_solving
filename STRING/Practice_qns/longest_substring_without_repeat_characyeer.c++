// link-https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
//  Input: s = "abcabcbb"
//  Output: 3
//  Explanation: The answer is "abc", with the length of 3.
//  Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

int lengthOfLongestSubstring(string s)
{
    int i = 0, j = 0;
    int n = s.size();
    if (n == 0)
        return 0;
    int maxlen = -1;
    unordered_map<char, int> mp;
    while (j < n)
    {
        mp[s[j]]++;
        if (mp.size() == j - i + 1)
        {
            maxlen = max(maxlen, j - i + 1);
        }
        else if (mp.size() < j - i + 1)
        {
            while (mp.size() < j - i + 1)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }
        }
        j++;
    }
    return maxlen;
}