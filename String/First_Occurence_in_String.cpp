
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string haystack = "butsadbutsad";
    string needle = "sad";
    if (needle.size() > haystack.size())
    {
        return -1;
    }
    for (int i = 0; i <= haystack.length() - needle.length(); i++)
    {
        for (int j = 0; j < needle.length(); j++)
        {
            if (haystack[i + j] != needle[j])               
            {
                break;
            }
            if (j == needle.size() - 1)
            {
                cout<<i;
                return 0;
            }
        }
    }
    return -1;
}