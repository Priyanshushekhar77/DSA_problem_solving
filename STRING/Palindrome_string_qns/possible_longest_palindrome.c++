// link->https:leetcode.com/problems/longest-palindrome/description/
// Input: s = "abccccdd"
// Output: 7
// Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int longestPalindrome(string s)
{
    int n = s.size();
    int single = 0;
    unordered_map<char, int> mp;
    for (auto it : s)
    {
        mp[it]++;
    }
    int dual = 0;

    for (auto it : mp)
    {
        dual += it.second / 2;
        if (it.second % 2 == 1)
            single = 1;
    }
    int ans = dual * 2;
    if (single > 0)
        ans += 1;

    return ans;
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int result = longestPalindrome(s);
    cout << "The length of the longest palindrome that can be built is: " << result << endl;

    return 0;
}
