// link-https://leetcode.com/problems/longest-common-prefix/description/?envType=list&envId=rgj5k9fi
//  Input: strs = ["flower","flow","flight"]
//  Output: "fl"

string longestCommonPrefix(vector<string> &strs)
{
    // first sort lexigraphically array of string
    sort(strs.begin(), strs.end());
    string ans = "";
    int n = strs.size();
    // only compare first and last word and we will get common
    string first = strs[0];
    string last = strs[n - 1];
    for (int i = 0; i < first.length(); i++)
    {
        if (first[i] == last[i])
        {
            ans.push_back(first[i]);
        }
        else
        {
            break;
        }
    }
    return ans;