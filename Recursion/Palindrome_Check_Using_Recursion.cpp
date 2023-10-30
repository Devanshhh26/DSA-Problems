#include<iostream>
#include<string>
using namespace std;

bool palindromeCheck(string s,int start,int end)
{
    if(start>=end)
    {
        return true;
    }
    if(s[start]!=s[end])
    {
        return false;
    }
    return palindromeCheck(s,start+1,end-1);
    
}

int main()
{
    string s="racecar";
    bool ans= palindromeCheck(s,0,s.length()-1);
    cout<<ans;
    return 0;
}