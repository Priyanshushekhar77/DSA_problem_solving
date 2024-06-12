/*
link->https://leetcode.com/problems/remove-duplicate-letters/description/

Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is 
the smallest in lexicographical order
 among all possible results.

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans;
        vector<bool>taken(26,false);
        vector<int>lastind(26);
        //storing lasting of each char
        for(int i=0;i<s.size();i++){
            lastind[s[i]-'a'] = i;
        }
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            int ind=ch-'a';
            if(taken[ind]==true) continue;//already taken
            while(ans.size()>0 && ans.back()>ch && lastind[ans.back()-'a'] > i){
                // ans ka size empty na ho , aane wala char jo hai uske bda char ans.back()ho and ans.back() future me kisi ind pe present ho than;
                taken[ans.back()-'a'] = false;
                ans.pop_back();
            }
            // inc order wale char kp store karte jao
            ans.push_back(ch);
            taken[ind]=true;
        }
        return ans;
    }
};