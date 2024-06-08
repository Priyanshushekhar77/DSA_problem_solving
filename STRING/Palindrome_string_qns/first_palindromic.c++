// 2. FIRST PALINDROMIC Input: words = ["abc","car","ada","racecar","cool"]
// Output: "ada"
// Explanation: The first string that is palindromic is "ada".
// Note that "racecar" is also palindromic, but it is not the first.


// bool palindrome(string &st){
//     int s=0,e=st.size()-1;
//     while(s<e){
//         if(st[s]!=st[e]) return false;
//         s++,e--;
//     }
//     return true;

// }
//     string firstPalindrome(vector<string>& words) {
//         for(auto it:words){
//          if(palindrome(it)) return it;
//         }
//         return "";