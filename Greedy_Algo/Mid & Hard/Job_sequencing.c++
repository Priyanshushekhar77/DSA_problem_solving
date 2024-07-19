// link-https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
//  N = 5
//  Jobs = {(1,2,100),(2,1,19),(3,2,27),
//          (4,1,25),(5,1,15)}
//  Output:
//  2 127
//  Explanation:
//  2 jobs can be done with
//  maximum profit of 127 (100+27).
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Job
{
    int id;
    int dead;
    int profit;
};
static bool comp(Job a, Job b)
{
    return a.profit > b.profit; // jada profit wala uppar rahna chahiye(descending order)
}
vector<int> JobScheduling(Job arr[], int n)
{
    int profit = 0;
    int cnt = 0;
    // Step 1: Sort the jobs according to profit
    sort(arr, arr + n, comp);

    // Step 2: Find the maximum deadline
    int maxdeadline = 0;
    for (int i = 0; i < n; i++)
    {
        maxdeadline = max(maxdeadline, arr[i].dead);
    }
    // Step 3: Create an array to keep track of free time slots, initialized with -1
    vector<int> time(maxdeadline + 1, -1);
    // Step 4:Now, Try to schedule jobs as late as possible(at any time index) to maximize the number of jobs and profits done

    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j > 0; j--)
        {
            if (time[j] == -1)
            {
                cnt++; // storing maxjob dones
                profit += arr[i].profit;
                time[j] = i; // now your slot becomes filled
                break;
            }
        }
    }
    return {cnt, profit};
}
int main()
{
    int n = 4;
    Job arr[] = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    vector<int> result = JobScheduling(arr, n);
    cout << "Number of jobs done: " << result[0] << endl;
    cout << "Maximum profit: " << result[1] << endl;

    return 0;
}
// T.C->O(NLOGN)+O(N)+O(N*D) D=maxdeadline
// S.C->O(D)
