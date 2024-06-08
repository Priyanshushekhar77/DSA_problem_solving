// link->https://leetcode.com/problems/rotate-string/description/?envType=list&envId=rgj5k9fi
//  Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

// A shift on s consists of moving the leftmost character of s to the rightmost position.

// For example, if s = "abcde", then it will be "bcdea" after one shift.

// Example 1:

// Input: s = "abcde", goal = "cdeab"
// Output: true

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.length() != goal.length())
            return false;
        string ans = s + s;
        if (ans.find(goal) != string::npos)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
