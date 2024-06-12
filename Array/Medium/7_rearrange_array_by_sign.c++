// Input:
// arr[] = {1,2,-4,-5,3,4}, N = 6
// Output:
// 1 -4 2 -5 3 4

// bruteforce

#include <bits/stdc++.h>
using namespace std;

vector<int> RearrangebySign(vector<int> A, int n)
{

    // Define 2 vectors, one for storing positive
    // and other for negative elements of the array.
    vector<int> pos;
    vector<int> neg;

    // Segregate the array into positives and negatives.
    for (int i = 0; i < n; i++)
    {

        if (A[i] > 0)
            pos.push_back(A[i]);
        else
            neg.push_back(A[i]);
    }

    // Positives on even indices, negatives on odd.
    for (int i = 0; i < n / 2; i++)
    {

        A[2 * i] = pos[i];
        A[2 * i + 1] = neg[i];
    }

    return A;
}

int main()
{

    // Array Initialisation.
    int n = 4;
    vector<int> A{1, 2, -4, -5};

    vector<int> ans = RearrangebySign(A, n);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}

/*OPTIMAL
Approach:

In this optimal approach, we will try to solve the problem in a single pass and try to arrange the array elements in the correct order in that pass only.

We know that the resultant array must start from a positive element so we initialize the positive index as 0 and negative index as 1 and start traversing the array such that whenever we see the first positive element, it occupies the space at 0 and then posIndex increases by 2 (alternate places).

Similarly, when we encounter the first negative element, it occupies the position at index 1, and then each time we find a negative number, we put it on the negIndex and it increments by 2.

When both the negIndex and posIndex exceed the size of the array, we see that the whole array is now rearranged alternatively according to the sign.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> RearrangebySign(vector<int> A)
{

    int n = A.size();

    // Define array for storing the ans separately.
    vector<int> ans(n, 0);

    // positive elements start from 0 and negative from 1.
    int posIndex = 0, negIndex = 1;
    for (int i = 0; i < n; i++)
    {

        // Fill negative elements in odd indices and inc by 2.
        if (A[i] < 0)
        {
            ans[negIndex] = A[i];
            negIndex += 2;
        }

        // Fill positive elements in even indices and inc by 2.
        else
        {
            ans[posIndex] = A[i];
            posIndex += 2;
        }
    }

    return ans;
}

int main()
{

    // Array Initialisation.

    vector<int> A = {1, 2, -4, -5};

    vector<int> ans = RearrangebySign(A);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}