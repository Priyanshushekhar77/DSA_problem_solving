// link- https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1?page=1&sprint=44972f990628eb44845eea51450b96ed&sortBy=submissions

/* S = "aabacbebebe", K = 3
Output:
7
Explanation:
"cbebebe" is the longest substring with 3 distinct characters.
Example 2:

Input:
S = "aaaa", K = 2
Output: -1
Explanation:
There's no substring with 2 distinct characters.
*/

class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        unordered_map<char, int> mp;
        int i = 0, j = 0;
        int n = s.size();
        int maxlen = -1; // if(k unique character is not possible in string return -1 )
        while (j < n)
        {
            mp[s[j]]++;
            if (mp.size() == k)
            {
                maxlen = max(maxlen, j - i + 1);
            }
            else if (mp.size() > k)
            {
                while (mp.size() > k)
                {
                    mp[s[i]]--;
                    // reinitialsie
                    if (mp[s[i]] == 0)
                        mp.erase(s[i]);
                    i++;
                }
            }
            j++;
        }
        return maxlen;
    }
};