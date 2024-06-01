// N = 6
// start[] = {1,3,0,5,8,5}
// end[] =  {2,4,6,7,9,9}
// Output:
// 4
// Explanation:
// Maximum four meetings can be held with
// given start and end timings.
// The meetings are - (1, 2),(3, 4), (5,7) and (8,9)
#include <bits/stdc++.h>
using namespace std;
int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int, int>> combined;
    for (int i = 0; i < n; i++)
    {
        combined.push_back({end[i], start[i]}); // second->end and first->start;
    }
    sort(combined.begin(), combined.end()); // sorted a/c ending of meeting
    int nextmeetendtime = combined[0].first;
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (nextmeetendtime < combined[i].second)
        {
            cnt++;
            nextmeetendtime = combined[i].first;
        }
    }
    return cnt;
}