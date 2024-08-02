/*Input: arr1 = [2, 3, 7, 10, 12] , arr2 = [1, 5, 7, 8]
Output: 35
Explanation: The path will be 1+5+7+10+12 = 35, where 1 and 5 come from arr2 and then 7 is common so we switch to arr1 and add 10 and 12.
Input: arr1 = [1, 2, 3] , arr2[] = [3, 4, 5]
Output: 15
Explanation: The path will be 1+2+3+4+5=15.
*/

int max_path_sum(int A[], int B[], int l1, int l2)
{

    // Your code here
    int ans = 0;
    int sum1 = 0, sum2 = 0;
    int i = 0, j = 0;
    while (i < l1 && j < l2)
    {
        if (A[i] < B[j])
        {
            sum1 += A[i];
            i++;
        }
        else if (A[i] > B[j])
        {
            sum2 += B[j];
            j++;
        }
        // (A[i]==B[j])
        else
        {
            ans += max(sum1, sum2) + A[i];
            i++;
            j++;
            sum1 = 0;
            sum2 = 0;
        }
    }
    while (i < l1)
    {
        sum1 += A[i];
        i++;
    }
    while (j < l2)
    {
        sum2 += B[j];
        j++;
    }
    ans = max(sum1, sum2) + ans;
    return ans;
}