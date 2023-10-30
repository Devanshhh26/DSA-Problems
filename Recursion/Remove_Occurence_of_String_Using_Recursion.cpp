#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void removeOcc(string &s, int n, string pat)
{
    int pos = s.find(pat);
    if (pos == string::npos)
    {
        return;
    }
    s.erase(pos, n);
    removeOcc(s, n, pat);
}
int main()
{
    string s = "asdbabcabcghkagabchabchkhabcabcabcabcabc";
    string pat = "abc";
    removeOcc(s, pat.length(), pat);
    cout << s;
    return 0;
}