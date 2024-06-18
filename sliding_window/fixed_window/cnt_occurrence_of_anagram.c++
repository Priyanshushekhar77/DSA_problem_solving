/* https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

Input:
txt = forxxorfxdofr
pat = for
Output: 3
Explanation: for, orf and ofr appears
in the txt, hence answer is 3.
Example 2:

Input:
txt = aabaabaa
pat = aaba
Output: 4
Explanation: aaba is present 4 times
in txt.
*/

int search(string pat, string txt)
{
    // code hereun
    unordered_map<char, int> mp;
    for (auto it : pat)
        mp[it]++;
    int i = 0, j = 0;
    int cnt = mp.size();
    int ans = 0;
    int n = txt.size(), k = pat.size();
    while (j < n)
    {
        mp[txt[j]]--;
        if (mp[txt[j]] == 0)
            cnt--;
        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            // counting ans
            if (cnt == 0)
                ans++;
            // adding prev window and moving window
            mp[txt[i]]++;
            if (mp[txt[i]] == 1)
                cnt++;
            i++;
            j++;
        }
    }
    return ans;
}