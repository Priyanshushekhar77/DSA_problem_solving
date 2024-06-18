// link->https://leetcode.com/problems/permutation-in-string/description/?envType=list&envId=rgj5k9fi

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:

// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false
// sliding window approach

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
    bool checkit(unordered_map<char, int> &s1map, unordered_map<char, int> &s2map)
    {
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            if (s1map[ch] != s2map[ch])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2)
    {
        // Sliding window method
        unordered_map<char, int> s1map, s2map;
        int k = s1.size();
        int n = s2.size();
        // Frequency map for s1(sample)
        for (char ch : s1)
        {
            s1map[ch]++;
        }
        int i = 0, j = 0;
        // Initialize the window with the first 'k' characters of s2
        while (j < n)
        {
            s2map[s2[j]]++;
            // If window size is equal to 'k', check for the permutation
            if (j - i + 1 == k)
            {
                if (checkit(s1map, s2map))
                    return true;
                // Slide the window
                s2map[s2[i]]--;
                if (s2map[s2[i]] == 0)
                {
                    s2map.erase(s2[i]); // Clean up zero count to match `checkit` logic
                }
                // increment the prev ind
                i++;
            }
            // inc to next window
            j++;
        }

        return false;
    }
};

// sliding window optimal method

bool checkInclusion(string s1, string s2)
{
    // Sliding window method
    unordered_map<char, int> s1map;
    int k = s1.size(); // pattern
    int n = s2.size(); // text
    // Frequency map for s1(sample)
    for (char c : s1)
    {
        s1map[c]++;
    }
    int i = 0, j = 0;
    int cnt = s1map.size();
    // Initialize the window with the first 'k' characters of s2
    while (j < n)
    {
        s1map[s2[j]]--;
        if (s1map[s2[j]] == 0)
            cnt--;
        if (j - i + 1 < k)
            j++;
        // If window size is equal to 'k', check for the permutation
        else if (j - i + 1 == k)
        {
            if (cnt == 0)
                return true;
            // add the prev portion in the window
            s1map[s2[i]]++; // Slide the window

            if (s1map[s2[i]] == 1)
            {
                cnt++;
            }
            i++;
            j++;
        }
    }

    return false;
}
