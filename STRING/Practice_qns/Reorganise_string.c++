// link-https://leetcode.com/problems/reorganize-string/description/
//  Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

// Return any possible rearrangement of s or return "" if not possible.
// Input: s = "aab"
// Output: "aba"

string reorganizeString(string s)
{
    string ans = s;
    vector<int> cnt(26, 0);
    int n = s.size();
    int maxfreq = 0;
    int maxfreqchar;
    // counting occurrence of character
    for (auto it : s)
    {
        cnt[it - 'a']++;
        // finding most occurence character
        if (cnt[it - 'a'] > maxfreq)
        {
            maxfreq = cnt[it - 'a'];
            maxfreqchar = it;
        }
        // edge case if any char is greater than half size of string than it unable to places at adjecent pos
        if (cnt[it - 'a'] > (n + 1) / 2)
            return "";
    }
    // placing most frequient character firstly
    int ind = 0;
    while (cnt[maxfreqchar - 'a'] > 0)
    {
        ans[ind] = maxfreqchar;
        ind += 2;
        cnt[maxfreqchar - 'a']--;
    }
    // lets place the remaining character
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        while (cnt[ch - 'a'] > 0)
        {
            if (ind >= n)
                ind = 1; // restart the index
            ans[ind] = ch;
            cnt[ch - 'a']--;
            ind += 2;
        }
    }

    return ans;
}