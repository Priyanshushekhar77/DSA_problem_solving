//link->https://leetcode.com/problems/largest-substring-between-two-equal-characters/description/?envType=list&envId=rgj5k9fi
// Input: s = "abca"
// Output: 2
// Explanation: The optimal substring here is "bc".

#include <bits/stdc++.h>
#include <string>
using namespace std;
  int maxLengthBetweenEqualCharacters(string s) {
       unordered_map<char,int>mp;
        int ans=-1;
        for(int i=0;i<s.size();i++){
            //agar same ele dobara mila toh
           if(mp.find(s[i])!=mp.end()){
               ans=max(ans,i-mp[s[i]]-1);
           }
           else{
            //new ele ko ind ke sath store karo
               mp[s[i]]=i;
           }
        }
       return ans;

    }