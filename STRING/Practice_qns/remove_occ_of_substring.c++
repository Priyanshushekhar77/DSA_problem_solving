// LINK->https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/?envType=list&envId=rgj5k9fi

// Input: s = "daabcbaabcbc", part = "abc"
// Output: "dab"
// Explanation: The following operations are done:
// - s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
// - s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
// - s = "dababc", remove "abc" starting at index 3, so s = "dab".
// Now s has no occurrences of "abc".

#include <iostream>
#include <string>

using namespace std;

string removePart(string s, string part)
{
    int index = s.find(part);
    while (index != string::npos)
    {
        s.erase(index, part.length());
        index = s.find(part);
    }
    return s;
}

int main()
{
    string s, part;
    cout << "Enter the main string: ";
    getline(cin, s);
    cout << "Enter the part to remove: ";
    getline(cin, part);

    string result = removePart(s, part);
    cout << "Resulting string: " << result << endl;

    return 0;
}

// The loop continues until there are no more occurrences of part in s. In the worst case, the loop can run
// O(m) times, where
// m is the number of occurrences of part in s.
// Since each iteration of the loop involves an
// O(n) operation (finding and erasing), the overall time complexity is
// O(m⋅n).