/* You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

//link-> https://leetcode.com/problems/longest-repeating-character-replacement/description/

Return the length of the longest substring containing the same letter you can get after performing the above operations.


Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
*/

int characterReplacement(string s, int k)
{
    // variable window sliding
    int i = 0, j = 0;
    int maxi = INT_MIN;
    unordered_map<char, int> mp; // vector<int>mp(26,0);
    int ans = 0;
    int n = s.size();
    while (j < n)
    {
        mp[s[j]]++;                 // storing cnt; can be mp[s[j]-'a']++
        maxi = max(maxi, mp[s[j]]); // important
        if ((j - i + 1) - maxi <= k)
        {
            ans = max(ans, j - i + 1); // max len
            j++;
        }
        else if ((j - i + 1) - maxi > k)
        {
            while ((j - i + 1) - maxi > k)
            { // can be ignore while loop to reduce T.C 0(2N) to 0(N)
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    return ans;
}