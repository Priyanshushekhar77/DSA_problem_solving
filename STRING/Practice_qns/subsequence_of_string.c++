#include <iostream>
#include <string>

using namespace std;

bool isSubsequence(const string &s1, const string &s2)
{
    int n = s1.length();
    int m = s2.length();
    int j = 0; // Pointer for s2

    for (int i = 0; i < n && j < m; i++)
    {
        if (s1[i] == s2[j])
        {
            j++;
        }
    }

    return (j == m);
}

int main()
{
    string s1, s2;

    cout << "Enter the main string (s1): ";
    cin >> s1;

    cout << "Enter the subsequence string (s2): ";
    cin >> s2;

    if (isSubsequence(s1, s2))
    {
        cout << s2 << " is a subsequence of " << s1 << endl;
    }
    else
    {
        cout << s2 << " is not a subsequence of " << s1 << endl;
    }

    return 0;
}
