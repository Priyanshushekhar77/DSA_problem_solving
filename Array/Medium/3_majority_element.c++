⊛ The most easiest Approach is sort the Array and return nums[nums.length / 2] as given that majority element frequency more than N / 2.
      ⊛ The most Optimized Solution is to use MOORE VOTING ALGORITHM.
      ⊛ Time Complexity : O(N) & Space Complexity : O(1).

/*
 * Find the Majority Element that occurs more than N/2 times
   Problem Statement: Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. You may consider that such an element always exists in the array.

   Example 1:

   Input Format: N = 3, nums[] = {3,2,3}

   Result: 3

   Explanation: When we just count the occurrences of each number and compare with half of the size of the array, you will get 3 for the above solution.

 */
// Approach 1 -> hashing

#include <bits/stdc++.h>
                                                     using namespace std;

int majorityElement(vector<int> v)
{

  // size of the given array:
  int n = v.size();

  // declaring a map:
  map<int, int> mpp;

  // storing the elements with its occurnce:
  for (int i = 0; i < n; i++)
  {
    mpp[v[i]]++;
  }

  // searching for the majority element:
  for (auto it : mpp)
  {
    if (it.second > (n / 2))
    {
      return it.first;
    }
  }

  return -1;
}

int main()
{
  vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
  int ans = majorityElement(arr);
  cout << "The majority element is: " << ans << endl;
  return 0;
}
/*Time Complexity: O(N*logN) + O(N), where N = size of the given array.
Reason: We are using a map data structure. Insertion in the map takes logN time. And we are doing it for N elements. So, it results in the first term O(N*logN). The second O(N) is for checking which element occurs more than floor(N/2) times. If we use unordered_map instead, the first term will be O(N) for the best and average case and for the worst case, it will be O(N2).

Space Complexity: O(N) as we are using a map data structure.
*/

/*Approach 2 -> moore voting algo
Approach:
Initialize 2 variables:
Count –  for tracking the count of element
Element – for which element we are counting
Traverse through the given array.
If Count is 0 then store the current element of the array as Element.
If the current element and Element are the same increase the Count by 1.
If they are different decrease the Count by 1.
The integer present in Element should be the result we are expecting
*/

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v)
{

  // size of the given array:
  int n = v.size();
  int cnt = 0; // count
  int el;      // Element

  // applying the algorithm:
  for (int i = 0; i < n; i++)
  {
    if (cnt == 0)
    {
      cnt = 1;
      el = v[i];
    }
    else if (el == v[i])
      cnt++;
    else
      cnt--;
  }

  // checking if the stored element
  //  is the majority element:
  int cnt1 = 0;
  for (int i = 0; i < n; i++)
  {
    if (v[i] == el)
      cnt1++;
  }

  if (cnt1 > (n / 2))
    return el;
  return -1;
}

int main()
{
  vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
  int ans = majorityElement(arr);
  cout << "The majority element is: " << ans << endl;
  return 0;
}
