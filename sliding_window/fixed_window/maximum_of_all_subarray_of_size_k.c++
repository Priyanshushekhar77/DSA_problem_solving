// https://leetcode.com/problems/maximum-average-subarray-i/description/?envType=list&envId=p0uny51g

/* Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
*/

double findMaxAverage(vector<int> &nums, int k)
{
    int i = 0, j = 0;
    double sum = 0;
    double maxi = INT_MIN;
    int n = arr.size();
    double avg = 0;
    while (j < n)
    {
        sum += arr[j];
        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            maxi = max(maxi, sum);
            avg = maxi / k;
            sum -= arr[i];
            i++;
            j++;
        }
    }
    return avg;
}