// link->https://leetcode.com/problems/image-overlap/description/

#include <bits/stdc++.h>
using namespace std;
int countoverlaps(vector<vector<int>> &img1, vector<vector<int>> &img2, int row, int col)
{
    int n = img1.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // find ind of img2 from img1 ke ind se
            int img2_i = i + row;
            int img2_j = j + col;
            if (img2_i < 0 || img2_i >= n || img2_j < 0 || img2_j >= n)
            {
                //..out of bound
                continue;
            }
            if (img1[i][j] == 1 && img2[img2_i][img2_j] == 1)
                cnt++;
        }
    }
    return cnt;
}
int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
{
    int n = img1.size();
    // image overlap me row ka range hoga=> [-n+1,n-1];
    // aur har row ke col ka image overlap ka range hoga => [-n+1,n-1];
    int maxoverlap = 0; // 1-1 overlap cnt
    for (int row = -n + 1; row < n; row++)
    {
        for (int col = -n + 1; col < n; col++)
        {
            int cnt = countoverlaps(img1, img2, row, col);
            maxoverlap = max(maxoverlap, cnt);
        }
    }
    return maxoverlap;
}

// T.C=>O(N*N*N*N);
// S.C=>O(1);