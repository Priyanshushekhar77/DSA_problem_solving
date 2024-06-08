// algoritm for text pattern searching in string
// T.C=>O(M+N) and S.C=>O(M)
//  txt = "geeksforgeeks"
//  pat = "geek"
//  Output:
//  1 9
//  Explanation:
//  The string "geek" occurs twice in txt, one starts are index 1 and the other at index 9.

void findlps(string &pat, vector<int> &lps)
{
    int m = pat.size();
    int len = 0;
    int i = 1;
    lps[0] = 0;
    while (i < m)
    {
        if (pat[i] == pat[len])
        { // if matches inc the len, put the len on lps[i], and inc the i++
            len++;
            lps[i] = len;
            i++;
        }
        else
        { // if not matches than find len of lps[len-1] than match till len becomes 0;
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
vector<int> search(string pat, string txt)
{
    int n = txt.size();
    int m = pat.size();
    vector<int> lps(m);
    vector<int> ans;
    findlps(pat, lps);
    int i = 0, j = 0;
    while (i < n)
    {
        if (txt[i] == pat[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            ans.push_back(i - j + 1); // ind of pat in txt
            // search for next pat in text
            j = lps[j - 1];
            // lps[j-1] gives the ind thats prefix part is equal to suffix so that pat start from index j;
        }
        else if (i < n && txt[i] != pat[j])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
                i++;
        }
    }
    return ans;
}