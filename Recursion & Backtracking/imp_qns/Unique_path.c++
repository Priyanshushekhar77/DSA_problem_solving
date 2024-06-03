
// link->https://leetcode.com/problems/unique-paths-iii/

#include <iostream>
#include <vector>

using namespace std;

int m, n;
int emptycell = 0;
int ans = 0;
vector<vector<int>> dirn{{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

void dfs(vector<vector<int>> &grid, int currcnt, int i, int j)
{
    if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == -1)
        return;
    if (grid[i][j] == 2)
    {
        if (currcnt == emptycell)
            ans++;
        return;
    }
    // Path taken
    grid[i][j] = -1;
    // Exploring
    for (auto it : dirn)
    {
        int deli = i + it[0];
        int delj = j + it[1];
        dfs(grid, currcnt + 1, deli, delj);
    }
    // Undo
    grid[i][j] = 0;
}

int uniquePathsIII(vector<vector<int>> &grid)
{
    m = grid.size();
    n = grid[0].size();
    int st_x = 0, st_y = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Counting non-obstacle cells so that if total paths covered == non-obstacle count, we include it in the ans
            if (grid[i][j] == 0)
                emptycell++;
            // Finding starting pos
            if (grid[i][j] == 1)
            {
                st_x = i;
                st_y = j;
            }
        }
    }
    emptycell += 1; // for current position
    int currcnt = 0;
    dfs(grid, currcnt, st_x, st_y);
    return ans;
}

int main()
{
    vector<vector<int>> grid = {
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 2, -1}};
    cout << "Number of unique paths: " << uniquePathsIII(grid) << endl;
    return 0;
}

// T.C-->>O(4(pow(m*n)))because the DFS explores each cell and has four possible directions to move in at each step. This is an upper bound as not all paths are explored due to obstacles and the endpoint conditions.
// S.C->O(M*N)
