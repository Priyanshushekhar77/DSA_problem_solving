11.Longest subarray with sum divisible by K
    // link->https://www.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

    int len = 0,
        sum = 0;
unordered_map<int, int> mp;
mp[0] = -1;
for (int i = 0; i < n; i++)
{

    sum += arr[i];
    int finds = ((sum % k) + k) % k; // handle negative cases

    if (mp.find(finds) != mp.end())
    {
        len = max(len, i - mp[finds]);
    }
    else
    {
        mp[finds] = i;
    }
}
return len;


12.Sub - Array sum divisible by K
    // link-> https://www.geeksforgeeks.org/problems/sub-array-sum-divisible-by-k2617/1

    int cnt = 0,
        sum = 0;
unordered_map<int, int> mp;
mp[0] = 1;
for (int i = 0; i < n; i++)
{

    sum += arr[i];
    int finds = ((sum % k) + k) % k; // handle negative cases

    if (mp.find(finds) != mp.end())
    {
        cnt += mp[finds];
    }

    mp[finds]++;
    ;
}
return cnt;
}
