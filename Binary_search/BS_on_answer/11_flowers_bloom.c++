/*  https://leetcode.com/problems/number-of-flowers-in-full-bloom/description/

You are given a 0-indexed 2D integer array flowers, where flowers[i] = [starti, endi] means the ith flower will be in full bloom from starti to endi (inclusive). You are also given a 0-indexed integer array people of size n, where people[i] is the time that the ith person will arrive to see the flowers.

Return an integer array answer of size n, where answer[i] is the number of flowers that are in full bloom when the ith person arrives.

Input: flowers = [[1,6],[3,7],[9,12],[4,13]], people = [2,3,7,11]
Output: [1,2,2,2]
Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
For each person, we return the number of flowers in full bloom during their arrival.
*/

vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people)
{
    int m = flowers.size();
    int n = people.size();
    vector<int> start(m);
    vector<int> ends(m);
    for (int i = 0; i < m; i++)
    {
        start[i] = flowers[i][0];
        ends[i] = flowers[i][1];
    }
    sort(start.begin(), start.end());
    sort(ends.begin(), ends.end());
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        int time = people[i];
        int rise = upper_bound(start.begin(), start.end(), time) - start.begin();
        int died = lower_bound(ends.begin(), ends.end(), time) - ends.begin();
        ans[i] = rise - died;
    }
    return ans;
}