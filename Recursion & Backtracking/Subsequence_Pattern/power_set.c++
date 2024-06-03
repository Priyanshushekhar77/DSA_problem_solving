#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> ans;

void solve(string &s, int ind, string curr)
{
    if (ind >= s.size())
    {
        if (curr != "")
        {
            ans.push_back(curr);
        }
        return;
    }
    curr += s[ind];
    solve(s, ind + 1, curr); // Include the current character
    curr.pop_back();
    solve(s, ind + 1, curr); // Exclude the current character
}

vector<string> AllPossibleStrings(string s)
{
    string curr = "";
    int ind = 0;
    solve(s, ind, curr);
    sort(ans.begin(), ans.end()); // Sort the result lexicographically
    return ans;
}

int main()
{
    string s = "abc";
    vector<string> result = AllPossibleStrings(s);

    cout << "All possible subsets of \"" << s << "\":" << endl;
    for (const string &subset : result)
    {
        cout << subset << " ";
    }
    cout << endl;

    return 0;
}
// The time complexity of this algorithm is O(2^n), where n is the length of the input string s.
// The space complexity is also O(2^n) due to the recursion stack, as there can be a maximum of 2^n subsets in the output.