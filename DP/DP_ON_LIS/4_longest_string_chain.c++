/*  Q. Longest String Chain | (DP- 45)

    Practice : https://leetcode.com/problems/longest-string-chain/

    You are given an array of words where each word consists of lowercase English letters.

    wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

    For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
    A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

    Return the length of the longest possible word chain with words chosen from the given list of words.

    Example 1:

    Input: words = ["a","b","ba","bca","bda","bdca"]
    Output: 4
    Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
    Example 2:

    Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
    Output: 5
    Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
    Example 3:

    approach-> only minor change, insted if arr[i] > arr[prev] use compare(s1,s2)  here s1 is curr string and s2 is prev string
    compare( S1, S2)

 1. It returns true if the first string S1 is just a single character addition with S2 else it returns false. The way we have called the code, we expect S1 to be the larger string of the two. Therefore the length of S1 should be greater than the length of S2 by 1.

 2. After checking for the length we can do a character matching using a two-pointer approach.

3. We will declare two pointers first and second, initially set to the first index of S1 and S2 respectively.
Then we set a while loop which will run till the first is less than the length of S1.
In every iteration, if both the characters match, i.e S1[first] == S2[second], we increment both first and second by 1.
Else, we will increment only first by 1.
4. As S1’s length(say m) is just greater than S2’s length(say n) by 1 using the above pointer approach both the pointers should point to m and n simultaneously. If it happens we return true, else we return false.
*/

#include <bits/stdc++.h>
using namespace std;
bool compare(string &s1, string &s2)
{
    if (s1.size() != s2.size() + 1)
        return false;
    int first = 0;
    int second = 0;
    while (first < s1.size())
    {
        if (second < s2.size() && s1[first] == s2[second])
        {
            first++;
            second++;
        }
        else
            first++;
    }
    if (first == s1.size() && second == s2.size())
        return true;
    else
        return false;
}
// for sorting
bool comp(string &s1, string &s2)
{
    return s1.size() < s2.size();
}

int longestStrChain(vector<string> &arr)
{
    int n = arr.size();
    // sort the array
    sort(arr.begin(), arr.end(), comp);
    vector<int> dp(n, 1);
    int maxi = 1;
    for (int i = 0; i <= n - 1; i++)
    {
        for (int prev_index = 0; prev_index < i; prev_index++)
        {
            if (compare(arr[i], arr[prev_index]) && 1 + dp[prev_index] > dp[i])
            {
                dp[i] = 1 + dp[prev_index];
            }
        }
        if (dp[i] > maxi)
            maxi = dp[i];
    }
    return maxi;
}

int main()
{
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    cout << " The length of the longest string chain is : " << longestStrChain(words);
}
// output is 4

// T.C -: We are setting up two nested loops and the compare function can be estimated to l, where l is the length of the longest string in the words [ ] array. Also, we are sorting so the time complexity will be (N^2 * l + NlogN)