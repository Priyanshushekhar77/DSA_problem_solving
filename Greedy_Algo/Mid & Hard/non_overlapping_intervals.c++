// Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
// Example 2:

// Input: intervals = [[1,2],[1,2],[1,2]]
// Output: 2
// Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
#include <bits/stdc++.h>
using namespace std;
 static bool comp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //sorting a/c ending intervals
        int n=intervals.size();
          sort(intervals.begin(), intervals.end(), comp);
          int cnt=1;
          int lastendtime=intervals[0][1];
          for(int i=1;i<n;i++){
            //if starting time of next index is greater than or equal to ending time of prev index than inc the cnt becz it is non-overlapping case.
            if(intervals[i][0]>=lastendtime){
                cnt++;
                lastendtime=intervals[i][1];
            }
          }
          return (n-cnt);

    }
int main() {
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << "Number of intervals to remove: " << eraseOverlapIntervals(intervals) << endl;
    return 0;
}