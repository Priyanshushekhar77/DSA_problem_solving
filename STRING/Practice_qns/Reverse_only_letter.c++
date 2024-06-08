// link->https://leetcode.com/problems/reverse-only-letters/description/?envType=list&envId=rgj5k9fi

string reverseOnlyLetters(string s)
{
    int l = 0, h = s.size() - 1;
    while (l < h)
    {
        if (isalpha(s[l]) && isalpha(s[h]))
        {
            swap(s[l], s[h]);
            l++;
            h--;
        }
        // starting part alphabet nhi hone pe usko waise hi rhne dena hai
        else if (!isalpha(s[l]))
        {
            l++;
        }
        // ending part alphabet nhi hone pe
        else
        {
            h--;
        }
    }
    return s;
}
