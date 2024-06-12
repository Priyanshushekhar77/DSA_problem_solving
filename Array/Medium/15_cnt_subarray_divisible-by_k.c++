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
//link->https://leetcode.com/problems/subarray-sums-divisible-by-k/description/


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int cnt=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
          sum+=nums[i];
          int rem=((sum%k)+k)%k;//handling -ve cases
          if(mp.find(rem)!=mp.end()){
            cnt+=mp[rem];
          }
          mp[rem]++;
        }
        return cnt;
    }
};