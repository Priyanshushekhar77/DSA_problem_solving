/*  link- https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.



Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again).
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb".
*/

/*bruteforce-
for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
        hash[s[j]-'a']=1;
        if(hash[0]+hash[1]+hash[2] == 3) cnt+=(n-j);//j ind ke baad jitne bhi char honge sabhi me all 3 char present honge
        else break;
    }
}
return cnt;
*/

// optimal
class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.size();
        // algo=> by using S.W when we get the 1st window containg all chars a,b,c than the number of valid substring will be 1+ remaining chars outside the window or simply say (n-j)
        unordered_map<char, int> mp;
        ;
        int cnt = 0;
        int i = 0, j = 0;
        while (j < n)
        {
            mp[s[j]]++;
            while (mp['a'] >= 1 && mp['b'] >= 1 && mp['c'] >= 1)//jabtak tino char included rhega map me
            {
                cnt += n - j; // all remaining chars outside the window is valid
                // uske baad shrink the winow
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return cnt;
    }
};