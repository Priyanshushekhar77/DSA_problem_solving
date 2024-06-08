// S = i.like.this.program.very.much
// Output: much.very.program.this.like.i
// Explanation: After reversing the whole  string(not individual words), the input  string becomes much.very.program.this.like.i

#include <iostream>
#include <string>
#include <algorithm> // for std::reverse

using namespace std;

void reverseWords(string &str)
{
    int n = str.length();
    int i = 0;
    // Reverse each word in the string
    for (int j = 0; j < n; j++)
    {
        if (str[j] == ' ')
        {
            reverse(str.begin() + i, str.begin() + j);
            i = j + 1; // it will start from next word of string
        }
    }

    // Reverse the last word
    reverse(str.begin() + i, str.end());

    // Reverse the whole string
    reverse(str.begin(), str.end());
}

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    reverseWords(str);

    cout << "Reversed string: " << str << endl;

    return 0;
}
