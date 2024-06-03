#include <iostream>
#include <vector>

using namespace std;

vector<string> ans;

void solve(int i, int j, vector<vector<int>> &mat, int n, string &temp)
{
    if (i < 0 || j < 0 || i >= n || j >= n || mat[i][j] == 0)
        return;
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(temp);
        return;
    }
    mat[i][j] = 0;
    temp.push_back('D');
    solve(i + 1, j, mat, n, temp);
    temp.pop_back();
    temp.push_back('R');
    solve(i, j + 1, mat, n, temp);
    temp.pop_back();
    temp.push_back('U');
    solve(i - 1, j, mat, n, temp);
    temp.pop_back();
    temp.push_back('L');
    solve(i, j - 1, mat, n, temp);
    temp.pop_back();
    mat[i][j] = 1;
}

vector<string> findPath(vector<vector<int>> &mat, int n)
{
    string temp = "";
    solve(0, 0, mat, n, temp);
    return ans;
}

int main()
{
    vector<vector<int>> mat = {{1, 0, 0, 0},
                               {1, 1, 0, 1},
                               {0, 1, 0, 0},
                               {1, 1, 1, 1}};
    int n = 4;
    vector<string> result = findPath(mat, n);
    for (string s : result)
    {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}
//  time complexity of the findPath function is𝑂(4pow(n))