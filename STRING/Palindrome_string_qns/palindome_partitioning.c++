// Given a string s, partition s such that every
// substring
//  of the partition is a
// palindrome
// . Return all possible palindrome partitioning of s.
// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]

// link->https://leetcode.com/problems/palindrome-partitioning/description/

// class Solution {
// public:
// int n;

// bool valid(string&s,int st,int end){
//     while(st<end){
//         if(s[st]!=s[end]) return false;
//         st++;
//         end--;
//     }
//     return true;
// }
//     void solve(string &s, int ind, vector<string> temp, vector<vector<string>> &ans){
//         if(ind==n){
//             ans.push_back(temp);
//         }
//         for(int i=ind;i<n;i++){
//             if(valid(s,ind,i)){
//                 //if it is valid palindrome  than include substr in temp than further explore  again after returning start from next ind validation
//                 string curr=s.substr(ind,i-ind+1);//currind,len
//                 temp.push_back(curr);
//                 //explore
//                 solve(s,i+1,temp,ans);
//                 //undo
//                 temp.pop_back();
//             }
//         }
//     }
//     vector<vector<string>> partition(string s) {
//         n=s.size();
//         vector<vector<string>>ans;
//         vector<string>temp;
//         solve(s,0,temp,ans);
//         return ans;
//     }
// };