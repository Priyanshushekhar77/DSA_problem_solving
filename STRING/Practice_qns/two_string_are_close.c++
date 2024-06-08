// link->https://leetcode.com/problems/determine-if-two-strings-are-close/description/
//  Two strings are considered close if you can attain one from the other using the following operations:

// Operation 1: Swap any two existing characters.
// For example, abcde -> aecdb
// Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
// For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
// You can use the operations on either string as many times as necessary.

// Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

// Example 1:

// Input: word1 = "abc", word2 = "bca"
// Output: true
// Explanation: You can attain word2 from word1 in 2 operations.
// Apply Operation 1: "abc" -> "acb"
// Apply Operation 1: "acb" -> "bca"

#include <bits/stdc++.h>
#include <string>

using namespace std;
bool closeStrings(string word1, string word2)
{
    int m = word1.size();
    int n = word2.size();
    if (m != n)
        return 0;
    vector<int> freq1(26, 0);
    vector<int> freq2(26, 0);
    for (int i = 0; i < n; i++)
    {
        int ind1 = word1[i] - 'a';
        int ind2 = word2[i] - 'a';
        freq1[ind1]++;
        freq2[ind2]++;
    }
    // cond(1)--jo char word1 me hai kisi bhi freq ke sath wo word2 me bhi hona chahiye ;nahi toh dono me nahi hona chahoiye
    for (int i = 0; i < 26; i++)
    {
        if (freq1[i] == 0 && freq2[i] == 0)
            continue;
        if (freq1[i] != 0 && freq2[i] != 0)
            continue;
        return false;
    }
    // dono ke freq ko sort karo aur match karo
    sort(freq1.begin(), freq1.end());
    sort(freq2.begin(), freq2.end());
    return freq1 == freq2; // 123==123
}