/*
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.



Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
Example 2:

Input: nums = [5], k = 9
Output: 0
*/
// link->https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

//1. count subarray which is divisible by k
class Solution
{
public:
  int subarraysDivByK(vector<int> &nums, int k)
  {
    unordered_map<int, int> mp;
    mp[0] = 1; // initilaise to handle cases like [3,3]
    int cnt = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      sum += nums[i];
      int rem = ((sum % k) + k) % k; // handling -ve cases
      if (mp.find(rem) != mp.end())
      {
        cnt += mp[rem];
      }
      mp[rem]++;
    }
    return cnt;
  }
};

//2. count pairs which is divisible by k

A[] = {2, 2, 1, 7, 5, 3}, K = 4
Output : 5
Explanation : 
There are five pairs possible whose sum
is divisible by '4' i.e., (2, 2), 
(1, 7), (7, 5), (1, 3) and (5, 3)

 unordered_map<long,long>mp;
 mp[0]=1;
        long long cnt=0;
        for(int i=0;i<n;i++){
            int rem=((arr[i]%k)+k)%k;
            
                if(rem!=0)cnt+=mp[k-rem];
            
            mp[rem]++;
        }
        return cnt;


//3. is all possible pair of divisibility sum

3.Array pair sum divisibility
/link->https://www.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1?page=1&sprint=93bae517656b109148ce7a63a6175891&sortBy=submissions
// nums = [9, 5, 7, 3]
// k = 6
// Output: 
// True
// Explanation: 
// {(9, 3), (5, 7)} is a 
// possible solution. 9 + 3 = 12 is divisible

// nums = [4, 4, 4]
// k = 4
// Output: 
// False
// Explanation: 
// You can make 1 pair at max, leaving a single 4 unpaired.

 bool canPair(vector<int> arr, int k) {
        // Code here.
        unordered_map<int,int>mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            //for handling negative element
            int rem=((arr[i]%k)+k)%k;
            mp[rem]++;
        }
//traversing mp
        for(auto it =mp.begin();it!=mp.end();it++){
            if(it->first==0){
                //checking for even pair for 0 remainder
                if(mp[it->first]%2!=0) return false;
            }
            //checking for pair (rem,k-rem); i.e k-rem must be present
            else if(mp.find(k-it->first)==mp.end()) return false;
            //checking for count of pair (rem,k-rem);
            else if(mp[it->first]!=mp[k-it->first]) return false;
            
        }
        return true;