/*
 * Majority Elements(>N/3 times) | Find the elements that appears more than N/3 times in the array
   Problem Statement: Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.

   Example 1:
   Input: N = 5, array[] = {1,2,2,3,2}
   Ouput: 2
   Explanation: Here we can see that the Count(1) = 1, Count(2) = 3 and Count(3) = 1.Therefore, the count of 2 is greater than N/3 times. Hence, 2 is the answer.

   Example 2:
   Input:  N = 6, array[] = {11,33,33,11,33,11}
   Output: 11 33
   Explanation: Here we can see that the Count(11) = 3 and Count(33) = 3. Therefore, the count of both 11 and 33 is greater than N/3 times. Hence, 11 and 33 is the answer.
 */

// Method1) HASHING
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {

        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        vector<int> ans;
        for (auto it : mp)
        {
            if (it.second > nums.size() / 3)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};

// OPTIMAL
/*
Optimal Approach (Extended Boyer Moore’s Voting Algorithm):
Approach:
1.Initialize 4 variables:
cnt1 & cnt2 –  for tracking the counts of elements
el1 & el2 – for storing the majority of elements.

2.Traverse through the given array.
a) If cnt1 is 0 and the current element is not el2 then store the current element of the array as el1 along with increasing the cnt1 value by 1.
b) If cnt2 is 0 and the current element is not el1 then store the current element of the array as el2 along with increasing the cnt2 value by 1.
c) If the current element and el1 are the same increase the cnt1 by 1.
d) If the current element and el2 are the same increase the cnt2 by 1.
e)Other than all the above cases: decrease cnt1 and cnt2 by 1.

3.The integers present in el1 & el2 should be the result we are expecting. So, using another loop, we will manually check their counts if they are greater than the floor(N/3).
*/

int #include<bits / stdc++.h> using namespace std;

vector<int> majorityElement(vector<int> v)
{
    int n = v.size(); // size of the array

    int cnt1 = 0, cnt2 = 0; // counts
    int el1 = INT_MIN;      // element 1
    int el2 = INT_MIN;      // element 2

    // applying the Extended Boyer Moore's Voting Algorithm:
    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0 && el2 != v[i])
        {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && el1 != v[i])
        {
            cnt2 = 1;
            el2 = v[i];
        }
        else if (v[i] == el1)
            cnt1++;
        else if (v[i] == el2)
            cnt2++;
        else
        {
            cnt1--, cnt2--;
        }
    }

    vector<int> ls; // list of answers

    // Manually check if the stored elements in
    // el1 and el2 are the majority elements:
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == el1)
            cnt1++;
        if (v[i] == el2)
            cnt2++;
    }

    int mini = int(n / 3) + 1;
    if (cnt1 >= mini)
        ls.push_back(el1);
    if (cnt2 >= mini)
        ls.push_back(el2);

    // Uncomment the following line
    // if it is told to sort the answer array:
    // sort(ls.begin(), ls.end()); //TC --> O(2*log2) ~ O(1);

    return ls;
}

int main()
{
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityElement(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    return 0;
}
