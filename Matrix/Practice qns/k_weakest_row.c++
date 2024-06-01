// link->https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
int binarysearch(vector<int> &arr, int s, int e)
{
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == 1)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans + 1;
}

vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
    int m = mat.size();
    int n = mat[0].size();
    vector<p> cntone; // {onekacnt, row}
    for (int row = 0; row < m; row++)
    {
        // binary search
        int noofones = binarysearch(mat[row], 0, n - 1);
        cntone.push_back({noofones, row});
    }
    sort(cntone.begin(), cntone.end()); // sort a/c noofones
    vector<int> ans(k);
    for (int i = 0; i < k; i++)
    {
        ans[i] = cntone[i].second;
    }
    return ans;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1}};
    int k = 3;
    vector<int> result = kWeakestRows(mat, k);
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
