1.EQUAL ROW AND COLUMN PAIRS
        [[ 3, 1, 2, 2 ], [ 1, 4, 4, 5 ], [ 2, 4, 2, 2 ], [ 2, 4, 2, 2 ]] Output : 3 Explanation : There are 3 equal row and column pairs : -(Row 0, Column 0) : [ 3, 1, 2, 2 ] - (Row 2, Column 2) : [ 2, 4, 2, 2 ] - (Row 3, Column 2) : [ 2, 4, 2, 2 ] int equalPairs(vector<vector<int>> & grid)
{
    map<vector<int>, int> mp; // stores row array and cnt
    int cnt = 0;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++)
    {
        // each row get stored in map with count;
        mp[grid[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < m; j++)
        {
            temp.push_back(grid[j][i]);
        }
        cnt += mp[temp];
    }
    return cnt;


    
B) PRINT UNIQUE ROW IN A MATRIX

   map<vector<int>,int>mp;//stores row array and cnt
vector<vector<int>> ans;
for (int i = 0; i < m; i++)
{
    // vector<int>row;
    for (int j = 0; j < n; j++)
    {
        row.push_back(m[i][j]);
    }
    if(mp.find(row)!=mp.end(){
            mp[row]++;
            ans.push_back(row);
}
else continue;
}
return ans;
