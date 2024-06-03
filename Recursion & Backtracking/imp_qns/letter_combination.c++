#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<string> ans;

    void solve(int ind, string &digits, string &temp, unordered_map<char, string> &mp)
    {
        if (ind == digits.size())
        {
            ans.push_back(temp);
            return;
        }
        char curr = digits[ind];
        string str = mp[curr];
        for (int i = 0; i < str.size(); i++)
        {
            temp.push_back(str[i]);
            solve(ind + 1, digits, temp, mp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.length() == 0)
            return {};

        unordered_map<char, string> mp;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        string temp = "";

        solve(0, digits, temp, mp);

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<string> result = sol.letterCombinations("23");
    for (string s : result)
    {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}
// the time complexity of the letterCombinations function is
// 𝑂(m(pow(n)))
//  ), and the space complexity is
// 𝑂
// (
// 𝑛
// )
// O(n), where
// 𝑛
// n is the number of digits in the input string and
// 𝑚
// m is the average number of characters mapped to each digit.