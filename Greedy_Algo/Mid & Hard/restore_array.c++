/*
There is an integer array nums that consists of n unique elements, but you have forgotten it. However, you do remember every pair of adjacent elements in nums.

You are given a 2D integer array adjacentPairs of size n - 1 where each adjacentPairs[i] = [ui, vi] indicates that the elements ui and vi are adjacent in nums.

It is guaranteed that every adjacent pair of elements nums[i] and nums[i+1] will exist in adjacentPairs, either as [nums[i], nums[i+1]] or [nums[i+1], nums[i]]. The pairs can appear in any order.

Return the original array nums. If there are multiple solutions, return any of them.



Example 1:

Input: adjacentPairs = [[2,1],[3,4],[3,2]]
Output: [1,2,3,4]
Explanation: This array has all its adjacent pairs in adjacentPairs.
Notice that adjacentPairs[i] may not be in left-to-right order.
Example 2:

Input: adjacentPairs = [[4,-2],[1,4],[-3,1]]
Output: [-2,4,1,-3]
Explanation: There can be negative numbers.
Another solution is [-3,1,4,-2], which would also be accepted.
*/

void dfs(map<int, vector<int>> &adj, set<int> &st, int start, vector<int> &ans)
{
    if (st.find(start) != st.end())
        return; // all ele founded
    // else
    ans.push_back(start);
    st.insert(start);
    for (auto it : adj[start])
        dfs(adj, st, it, ans);
}
vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
{
    map<int, vector<int>> adj;
    for (auto &i : adjacentPairs)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    int start;
    for (auto it : adj)
    {
        if (it.second.size() == 1)
            start = it.first;
    }
    set<int> st;
    vector<int> ans;
    dfs(adj, st, start, ans);
    return ans;
}