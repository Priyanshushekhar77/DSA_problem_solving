// link->https://leetcode.com/problems/string-compression/description/?envType=list&envId=rgj5k9fi
//  Input: chars = ["a","a","b","b","c","c","c"]
//  Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
//  Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".

class Solution
{
public:
    int compress(vector<char> &str)
    {
        int i = 0;
        int index = 0;
        int n = str.size();
        while (i < n)
        {
            int charcnt = 0;
            char currchar = str[i];
            // jab tak same character aate rahe
            while (i < n && str[i] == currchar)
            {
                charcnt++;
                i++;
            }
            // ya toh string pura propagate ho jayega ya new character ayega toh ye loop se bahar aa jayega
            // purane char ko index pe lgao
            str[index] = currchar;
            index++;
            if (charcnt > 1)
            {
                // count converted into string
                string cnt = to_string(charcnt);
                // becauuse string cnt has length more than 9 than storing it
                for (auto it : cnt)
                {
                    str[index] = it;
                    index++;
                }
            }
        }
        // returning new size
        return index;
    }
};