
// https://leetcode.com/problems/palindromic-substrings/description/


#include <iostream>
#include <string>
#include <vector>
using namespace std;

int expand(string s, int i, int j)
{
    int count = 0;
    while (i >= 0 && j < s.length() && s[i] == s[j])
    {
        count++;
        i--;
        j++;
    }
    return count;
}

int main()
{
    string s = "noon";
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int oddAns = expand(s, i, i);                                       // odd string
        count = count + oddAns;

        int evenAns = expand(s, i, i + 1);                                // even string
        count = count + evenAns;
    }
    cout << count;
    return 0;
}