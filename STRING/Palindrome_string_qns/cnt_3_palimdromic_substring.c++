// link->https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/
//  Input: s = "aabca"
//  Output: 3
//  Explanation: The 3 palindromic subsequences of length 3 are:
//  - "aba" (subsequence of "aabca")
//  - "aaa" (subsequence of "aabca")
//  - "aca" (subsequence of "aabca")



// ALGO=> set me string ke unique ele ko store kar do;
// phir jitne unique ele set me store hai sabkke first aur last ind ke becch ke ele ko new set me insert karo aur new set ke size ko add karte jao ;


int countPalindromicSubsequence(string s)
{
    unordered_set<char> st;
    int ans = 0;
    for (auto it : s)
    {
        st.insert(it); // for storing unique letter
    }
    for (auto it2 : st)
    {
        // search in unique letter stored in set in string s
        int first = -1;
        int last = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (it2 == s[i])
            {
                if (first == -1)
                    first = i;
                last = i;
            }
        }
        unordered_set<char> st2; // for storing unique letter between first and last pos of  same ele
        for (int i = first + 1; i <= last - 1; i++)
        {
            st2.insert(s[i]);
        }
        ans += st2.size();
    }
    return ans;


//     // T.C=>O(26 * (N+N))   S.C=>O(N)
// }