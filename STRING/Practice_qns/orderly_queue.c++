// You are given a string s and an integer k. You can choose one of the first k letters of s and append it at the end of the string.

// Return the lexicographically smallest string you could have after applying the mentioned step any number of moves.

 

// Example 1:

// Input: s = "cba", k = 1
// Output: "acb"
// Explanation: 
// In the first move, we move the 1st character 'c' to the end, obtaining the string "bac".
// In the second move, we move the 1st character 'b' to the end, obtaining the final result "acb".
// Example 2:

// Input: s = "baaca", k = 3
// Output: "aaabc"
// Explanation: 
// In the first move, we move the 1st character 'b' to the end, obtaining the string "aacab".
// In the second move, we move the 3rd character 'c' to the end, obtaining the final result "aaabc".

 string orderlyQueue(string s, int k) {
        if(k>1) {
            sort(s.begin(),s.end());
            return s;
        }
        //if(k==1) than find min of all rotations
        string ans=s;
        int n=s.size();
        for(int i=1;i<n;i++){
           //rotate kar rahe hai first wale ko last me last wale ko first me
           string temp=s.substr(i) + s.substr(0,i);//ind and length
           ans=min(ans,temp);
        }
        return ans;

    }