// link->https://leetcode.com/problems/valid-palindrome/description/?envType=list&envId=rgj5k9fi

#include <iostream>
#include <string>

using namespace std;

// Function to check if a character is valid (alphanumeric)
bool valid(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return true;
    }
    return false;
}

// Function to convert a character to lowercase
char lowercase(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
    {
        return ch;
    }
    else
    {
        return ch - 'A' + 'a';
    }
}

// Function to check if a string is a palindrome
bool checkpalindrome(const string &a)
{
    int s = 0;
    int end = a.length() - 1;
    while (s <= end)
    {
        if (a[s] != a[end])
        {
            return false;
        }
        s++;
        end--;
    }
    return true;
}

// Function to check if a string is a palindrome after removing non-alphanumeric characters and converting to lowercase
bool isPalindrome(string s)
{
    // Remove non-alphanumeric characters
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (valid(s[i]))
        {
            ans.push_back(s[i]);
        }
    }

    // Convert to lowercase
    for (int i = 0; i < ans.length(); i++)
    {
        ans[i] = lowercase(ans[i]);
    }

    // Check if the cleaned string is a palindrome
    return checkpalindrome(ans);
}

int main()
{
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    if (isPalindrome(s))
    {
        cout << "The string is a palindrome." << endl;
    }
    else
    {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
