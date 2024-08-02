/*Input: arr[] = [34, 8, 10, 3, 2, 80, 30, 33, 1]
Output: 6
Explanation: In the given array arr[1] < arr[7] satisfying the required condition(arr[i] < arr[j]) thus giving the maximum difference of j - i which is 6(7-1).*/

int maxIndexDiff(vector<int> &arr)
{
    int n = arr.size();
    // Your code here
    stack<pair<int, int>> st;
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty() || st.top().first < arr[i])
        {
            st.push({arr[i], i});
        }
    }
    int i = 0, ans = 0;
    while (i < n && !st.empty())
    {
        if (arr[i] > st.top().first)
        {
            i++;
        }
        else
        {
            ans = max(ans, st.top().second - i);
            st.pop();
        }
    }
    return ans;
}