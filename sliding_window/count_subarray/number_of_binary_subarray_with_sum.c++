/* link-  https://leetcode.com/problems/binary-subarrays-with-sum/description/
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15
*/


// int numSubarraysWithSum(vector<int>& nums, int goal) {
    //     //prefix sum technique
    //     int n=nums.size();
    //     int i=0,j=0,sum=0,cnt=0;
    //     unordered_map<int,int>mp;
     //      mp[0]=1;
    //     while(j<n){
    //        sum+=nums[j];
    //        int rem=sum-goal;
    //        if(mp.find(rem)!=mp.end()) cnt+=mp[rem];
    //        mp[sum]++;
    //        j++;
    //     }
    //     return cnt;


//OPTIMAL
class Solution {
public:
int helper(vector<int>& nums, int goal){
    int n=nums.size();
    int i=0,j=0;
    int cnt=0;
    int sum=0;
    while(j<n){
      sum+=nums[j];
      if(sum>goal){
        while(i<=j && sum>goal){
            sum-=nums[i];
            i++;
        }
      }
      cnt+=(j-i+1);//counting subarray
      j++;
    }
    return cnt;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //as we solved in array playlist for case of [+] subarray use S.W technq and for [+,-,0] subarray use map technq any of them
        //algo=> No.of subarray with sum <= goal (atmost cond)
        return helper(nums,goal) - helper(nums,goal - 1);
    }
};