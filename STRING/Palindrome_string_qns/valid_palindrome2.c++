// LINK->https://leetcode.com/problems/valid-palindrome-ii/description/?envType=list&envId=rgj5k9fi
//  Given a string s, return true if the s can be palindrome after deleting at most one character from it
//  Input: s = "aba"
//  Output: true
//  Example 2:

// Input: s = "abca"
// Output: true
// Explanation: You could delete the character 'c'.
// Example 3:

// Input: s = "abc"
// Output: false
// ALGO->if s and e index ele  is same than continue otherwise check (s,i+1,j) or (s,i,j-1) to make valid palindrome

#include <iostream>
#include <string>

using namespace std;

// Function to check if a substring is a palindrome
bool palindrome(const string &s, int i, int j)
{
    while (i <= j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

// Function to check if a string can be a palindrome by removing at most one character
bool validPalindrome(const string &s)
{
    int i = 0;
    int j = s.length() - 1;
    while (i <= j)
    {
        if (s[i] != s[j])
        {
            return palindrome(s, i + 1, j) || palindrome(s, i, j - 1); // either skip left part or either skip right part than check it is making palindrome or not
        }
        else
        {
            // s[i]==s[j]
            i++;
            j--;
        }
    }
    return true;
}

int main()
{
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    if (validPalindrome(s))
    {
        cout << "The string can be a palindrome by removing at most one character." << endl;
    }
    else
    {
        cout << "The string cannot be a palindrome by removing at most one character." << endl;
    }

    return 0;
}
// T.C->O(N) AND S.C->O(1)