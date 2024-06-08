// 7.anagram of s1 and s2
//  method1) sort s1 and s2; return s1==s2
// method2) unordered_map<char,int>mp;
// for(int i=0;i<n;i++){
//   mp[s1[i]]++;//add char of string1
//  mp[s2[i]]--;//remove char of string2
// }
// for(int i=0;i<n;i++){
// if(mp[i]]!=0)return false;
// }
// return true;
