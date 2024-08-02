// https://codeforces.com/problemset/problem/1195/A

#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, k, x;
    cin >> n >> k;
    vector<int> v(k + 1);
    long long cap = ceil(1.0 * n / 2);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v[x]++;
    }
    long long odd = 0, even = 0;
    for (int i = 0; i <= k; i++)
    {
        if (v[i] % 2 == 1)
        {
            even += (v[i] - 1);
            odd++;
        }
        else
            even += v[i];
    }
    long long ans = 0;
    ans += 2 * min(even / 2, cap);
    cap -= min(even / 2, cap);
    ans += cap;
    cout << ans;
    return 0;
}