// link->https://leetcode.com/problems/where-will-the-ball-fall/description/

#include <bits/stdc++.h>
using namespace std;
vector<int> findBall(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<int> ans;
    for (int ball = 0; ball < n; ball++)
    {
        int row = 0;
        int col = ball;
        bool collide = false;
        // each ball le liye loop me ghumenge
        while (row < m && col < n)
        {
            // agar dabba me 1 hai toh wo last index pe nahi hona chahiye aur uske aage wale col ind pe -1 nahi hona chahiye and phir aage jao col++;
            if (grid[row][col] == 1)
            {
                if (col == n - 1 || grid[row][col + 1] == -1)
                {
                    collide = true;
                    break;
                }
                col++;
            }
            else
            {
                // agar dabba me -1 hai toh wo first index pe nahi hona chahiye aur uske piche wale col ind pe 1 nahi hona chahiye and phir aage jao col++;
                if (col == 0 || grid[row][col - 1] == 1)
                {
                    collide = true;
                    break;
                }
                col--;
            }
            row++;
        }
        if (collide == true)
            ans.push_back(-1);
        else
            ans.push_back(col);
    }
    return ans;
}