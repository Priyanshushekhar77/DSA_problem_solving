// link->https://www.geeksforgeeks.org/problems/pattern-searching4145/1
//also qns can be ask to return the first occurence of a letter in a string
// Input: text = "geeksforgeeks"
//        pat = "geek"
// Output: 1
// Explanation: "geek" exists in
// "geeksforgeeks"

#include <iostream>
#include <string>

using namespace std;

int isSubstring(const string &text, const string &pat)
{
    int n = text.length();
    int m = pat.length();

    for (int i = 0; i <= n - m;)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (pat[j] != text[i + j])
            {
                break;
            }
        }

        if (j == m)
        {
            return 1; // pat is a substring of text or either return ind
        }

        if (j == 0)
        {
            i++; // Increment i by 1 if there was no match at all
        }
        else
        {
            i = i + j; // Skip the mismatched characters
        }
    }
    return 0; // pat is not a substring of text
}

int main()
{
    string text = "geeksforgeeks";
    string pat = "geek";

    int result = isSubstring(text, pat);
    cout << result << endl;

    return 0;
}
//T.C=> O(N*M)