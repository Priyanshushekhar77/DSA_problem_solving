// Given a NxM binary matrix consisting of 0s and 1s. Find if there exists a rectangle/ square within the matrix whose all four corners are 1.
// Input:
// N = 4, M = 5
// matrix[][] =
// {
// {1 0 0 1 0},
// {0 0 1 0 1},
// {0 0 0 1 0},
// {1 0 1 0 1}
// } output->true

// link->https://www.geeksforgeeks.org/problems/find-rectangle-with-corners-as-1--141631/1

// Time Complexity->O(M*N*N)
// SPACE COMPLEXITY->O(N*N)

#include <bits/stdc++.h>
using namespace std;

bool hasRectangle(vector<vector<int>> &matrix)
{
    unordered_map<int, unordered_set<int>> mp;
    int m = matrix.size();
    int n = matrix[0].size();

    // Iterate through each row of the matrix
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int j2 = j + 1; j2 < n; j2++)
            {
                // If a pair of 1s is found in the same row
                if (matrix[i][j] == 1 && matrix[i][j2] == 1)
                {
                    // Check if there is any previous row with the same column indices
                    if (mp.find(j) != mp.end() && mp[j].find(j2) != mp[j].end())
                    {
                        return true;
                    }
                    else
                    {
                        // Store the pair of column indices
                        mp[j].insert(j2);
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 0, 0, 1},
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {0, 1, 1, 0}};

    if (hasRectangle(matrix))
    {
        cout << "Rectangle found!" << endl;
    }
    else
    {
        cout << "No rectangle found." << endl;
    }

    return 0;
}
