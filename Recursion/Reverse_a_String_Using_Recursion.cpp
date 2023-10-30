#include <iostream>
#include <string>
using namespace std;

void reverseString(string &s, int i, int n)
{
    if (i > n)
    {
        return;
    }
    swap(s[i], s[n]);
    reverseString(s, i + 1, n - 1);
}

int main()
{
    string s = "raytheon";
    reverseString(s, 0, s.length() - 1);
    cout << s;
    return 0;
}