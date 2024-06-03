// link->https://leetcode.com/problems/path-with-maximum-gold/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int m, n;
    vector<vector<int>> dirn{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    int solve(vector<vector<int>> &grid, int i, int j)
    {
        if (i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == 0)
        {
            return 0; // Zero gold
        }

        int value = grid[i][j];
        grid[i][j] = 0; // Mark this cell as visited
        int maxgold = 0;

        for (auto &it : dirn)
        {
            int newi = i + it[0];
            int newj = j + it[1];
            maxgold = max(maxgold, solve(grid, newi, newj));
        }

        // Undo the path cover (backtracking)
        grid[i][j] = value;

        // Return the maximum gold value collected
        return maxgold + value;
    }

    int getMaximumGold(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        int maxgold = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != 0)
                {
                    maxgold = max(maxgold, solve(grid, i, j));
                }
            }
        }

        return maxgold;
    }
};

int main()
{
    Solution solution;

    vector<vector<int>> grid = {
        {0, 6, 0},
        {5, 8, 7},
        {0, 9, 0}};

    int result = solution.getMaximumGold(grid);
    cout << "Maximum Gold: " << result << endl;

    return 0;
}

// T.C->O(4(pow(m*n)))
// S.C->O(m*n)