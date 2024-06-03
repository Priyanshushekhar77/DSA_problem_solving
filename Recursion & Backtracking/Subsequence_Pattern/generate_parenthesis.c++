#include <iostream>
#include <vector>
using namespace std;

vector<string> ans;

void solve(string temp, int open, int close, int n)
{
    if (temp.size() == 2 * n)
    {
        ans.push_back(temp);
        return;
    }
    //     It uses two variables, open and close, to keep track of the number of open and closed parentheses.
    // If open is less than n, it adds an open parenthesis and calls solve recursively with open+1.
    // If close is less than open, it adds a closed parenthesis and calls solve recursively with close+1.
    if (open < n)
    {
        temp.push_back('(');
        solve(temp, open + 1, close, n);
        temp.pop_back();
    }
    if (close < open)
    {
        temp.push_back(')');
        solve(temp, open, close + 1, n);
        temp.pop_back();
    }
}
vector<string> generateParenthesis(int n)
{
    string temp = "";
    solve(temp, 0, 0, n); // initially open=0 close=0;
    return ans;
}

int main()
{
    int n = 3;
    vector<string> result = generateParenthesis(n);

    cout << "Generated Parentheses for n = " << n << ":" << endl;
    for (const string &str : result)
    {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}

// The time complexity of this algorithm is O(4^n / sqrt(n)), where n is the given input n.
// This complexity arises because for each valid sequence, there are 2n steps and each step can be chosen from 2 choices (open or close).
// The space complexity is O(4^n / sqrt(n)) as well, considering the recursive stack space and the space used by the ans vector to store the valid combinations.