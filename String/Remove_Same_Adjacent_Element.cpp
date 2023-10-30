
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s = "abbaca";
    string ans = "";
    ans.push_back(s[0]);
    for (int i = 1; i < s.length(); i++)
    {
        int n = ans.length() - 1;
        if ((n >= 0) && ans[n] == s[i])                     // compare the last character in ans with the current character of s, if same then pop from ans else push in ans
        {
            ans.pop_back();
        }
        else
        {
            ans.push_back(s[i]);
        }
    }
    cout << ans;
    return 0;
}