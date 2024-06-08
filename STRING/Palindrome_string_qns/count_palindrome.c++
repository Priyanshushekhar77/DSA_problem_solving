// link-//link-->https://leetcode.com/problems/palindromic-substrings/solutions/4703811/interview-approach-3-approach-brute-force-expand-middle-dp

// Example 1:

// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
// Example 2:

// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

// Interviewer: What would be my time and space complexity here ?
// You: Time Complexity would be O(n3)O(n^3)O(n
// 3
// bool ispalindrome(string s,int low,int high){
//     while(low<=high){
//         if(s[low]!=s[high]) return false;
//         else {
//             low++;
//             high--;
//         }
//     }
//     return true;

// }
//     int countSubstrings(string s) {
//         //bruteforce
//         int cnt=0;
//         int n=s.size();
//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 if(ispalindrome(s,i,j)) cnt++;
//             }
//         }
//         return cnt;
//  ). Because we have two for loops to iterate all possible substring and one loop to check if it is palindrome or not.
// Space Complexity would be O(1)O(1)O(1).

// Interviewer: Cany you optimise it further ?
// You: Sure ( MF ).

// So Basically If I know a string is palindrome and I divide it in two parts ( if length is even->(s,i,i+1) ) that would have same characters.
// and for odd length->(s,i,i) except the middle element, all other characters would be same.

// =>OPTIMAL
#include <iostream>
#include <string>

using namespace std;

int palindrome(const string &s, int low, int high)
{
    int count = 0;
    while (low >= 0 && high < s.size() && s[low] == s[high])
    {
        count++;
        low--;
        high++;
    }
    return count;
}

int countSubstrings(const string &s)
{
    int cnt = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        int even = palindrome(s, i, i + 1);
        int odd = palindrome(s, i, i);
        cnt += even + odd;
    }
    return cnt;
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int result = countSubstrings(s);
    cout << "The number of palindromic substrings is: " << result << endl;

    return 0;
}
// Summary
// Time Complexity: O(N(pow(2)))
