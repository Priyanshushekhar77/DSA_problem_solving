// link-https://leetcode.com/problems/integer-to-roman/description/?envType=list&envId=rgj5k9fi
//  Input: num = 3749

// Output: "MMMDCCXLIX"

// Explanation:

// 3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
//  700 = DCC as 500 (D) + 100 (C) + 100 (C)
//   40 = XL as 10 (X) less of 50 (L)
//    9 = IX as 1 (I) less of 10 (X)
// Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places

class Solution
{
public:
    string intToRoman(int num)
    {
        // pair bnaye
        vector<pair<int, string>> mp = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

        string ans = "";
        for (int i = 0; i < mp.size(); i++)
        {
            // agar nums it.first se jada ya equal hua toh ans me it.second dalo aur nums ko it.first se minus karo
            while (num >= mp[i].first)
            {
                ans += mp[i].second;
                num -= mp[i].first;
            }
        }
        return ans;
    }
};