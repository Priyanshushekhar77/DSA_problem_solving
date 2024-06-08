// link->https://leetcode.com/problems/group-anagrams/description/?envType=list&envId=rgj5k9fi

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        for (auto it : strs)
        {
            string temp = it;
            // sort
            sort(temp.begin(), temp.end());
            // sort value me current string map karo
            mp[temp].push_back(it);
        }
        vector<vector<string>> ans;
        for (auto it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};