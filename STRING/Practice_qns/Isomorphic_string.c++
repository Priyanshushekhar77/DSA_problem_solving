// link->https://leetcode.com/problems/isomorphic-strings/description/?envType=list&envId=rgj5k9fi

// Input: s = "egg", t = "add"
// Output: true
// Example 2:

// Input: s = "foo", t = "bar"
// Output: false
// Example 3:

// Input: s = "paper", t = "title"
// Output: true

#include <bits/stdc++.h>
#include <string>
using namespace std;

bool isIsomorphic(string s, string t);

int main()
{
    string s1 = "egg";
    string t1 = "add";
    cout << (isIsomorphic(s1, t1) ? "True" : "False") << endl; // Expected: True

    string s2 = "foo";
    string t2 = "bar";
    cout << (isIsomorphic(s2, t2) ? "True" : "False") << endl; // Expected: False

    string s3 = "paper";
    string t3 = "title";
    cout << (isIsomorphic(s3, t3) ? "True" : "False") << endl; // Expected: True

    return 0;
}

bool isIsomorphic(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }

    unordered_map<char, char> mp, mp2;
    int n = s.length();

    for (int i = 0; i < n; ++i)
    {
        char c1 = s[i];
        char c2 = t[i];

        // Check mapping from s to t
        if (mp.find(c1) != mp.end())
        {
            if (mp[c1] != c2)
            {
                return false;
            }
        }
        else
        {
            mp[c1] = c2;
        }

        // Check mapping from t to s
        if (mp2.find(c2) != mp2.end())
        {
            if (mp2[c2] != c1)
            {
                return false;
            }
        }
        else
        {
            mp2[c2] = c1;
        }
    }

    return true;
}
