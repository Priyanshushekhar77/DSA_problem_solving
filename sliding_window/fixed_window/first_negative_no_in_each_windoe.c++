/* //link-> https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1?page=1&sprint=44972f990628eb44845eea51450b96ed&sortBy=submissions

N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : {-8 0 -6 -6}
*/

// brute force--2 for loop (i=0 to n,j=i to k)

vector<long long> printFirstNegativeInteger(long long int arr[],
                                            long long int n, long long int k)
{
    vector<long long> ans;
    // only list has pop_front()
    list<long long> temp;
    // i = startWindowIndex
    // j = endWindowIndex
    int i = 0, j = 0;
    while (j < n)
    {
        // adding element only to list if it is negative
        if (arr[j] < 0)
        {
            temp.push_back(arr[j]);
        }
        if (j - i + 1 < k)
        { // adding elements to make window size k
            j++;
        }
        else if (j - i + 1 == k)
        {
            // if list is empty
            if (temp.size() == 0)
                ans.push_back(0);
            // if list is not empty, we have some negative number
            else
            {
                ans.push_back(temp.front());
                if (arr[i] == temp.front())
                    temp.pop_front();
            }
            i++;
            j++;
        }
    }
    return ans;
}