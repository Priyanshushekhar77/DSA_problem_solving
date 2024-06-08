
#include <bits/stdc++.h>

using namespace std;

vector<int> FindUnion(int arr1[], int arr2[], int n, int m)
{
    map<int, int> freq; // because it stored in sorted order
    vector<int> Union;
    for (int i = 0; i < n; i++)
        freq[arr1[i]]++;
    for (int i = 0; i < m; i++)
        freq[arr2[i]]++;
    for (auto &it : freq)
        Union.push_back(it.first);
    return Union;
}

int main()
{
    int n = 10, m = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};
    vector<int> Union = FindUnion(arr1, arr2, n, m);
    cout << "Union of arr1 and arr2 is " << endl;
    for (auto &val : Union)
        cout << val << " ";
    return 0;
}
// Time Compleixty : O( (m+n)log(m+n) ) . Inserting a key in map takes logN times, where N is no of elements in map. At max map can store m+n elements {when there are no common elements and elements in arr,arr2 are distntict}. So Inserting m+n th element takes log(m+n) time. Upon approximation across insertion of all elements in worst it would take O((m+n)log(m+n) time.

// Using HashMap also takes the same time, On average insertion in unordered_map takes O(1) time but sorting the union vector takes O((m+n)log(m+n))  time. Because at max union vector can have m+n elements.

// Space Complexity : O(m+n) {If Space of Union ArrayList is considered}

// OPTIMAL SOLN->
= > UNION
        i = 0,
        j = 0;
vector<int> ans while (i < m && j < n)
{
    if (a[i] <= b[j])
    {
        if (ans.size() == 0 || ans.back() != a[i])
        {
            ans.push_back(a[i]);
        }
        i++;
    }
    else
    { // a[i]>b[j]
        if (ans.size() == 0 || ans.back() != b[j])
        {
            ans.push_back(b[j]);
        }
        j++;
    }
    while (i < m)
    {
        if (ans.size() == 0 || ans.back() != a[i])
        {
            ans.push_back(a[i]);
        }
        i++;
    }
    while (j < n)
    {
        if (ans.size() == 0 || ans.back() != b[j])
        {
            ans.push_back(b[j]);
        }
        j++;
    }
}

// INTERSECTION-->
arr[] and arr2[] Given int i = 0, j = 0;
while (i < n && j < m)
{
    if (a[i] < b[j])
        i++;
    else if (b[j] < a[i])
        j++;
    else
    {
        ans.push_back(a[i]);
        i++, j++;
    }
