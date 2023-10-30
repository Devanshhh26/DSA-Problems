#include<iostream>
#include<string>
using namespace std;

void lastChar(string s,int i,int x,int& idx)
{
    if(i<0)
    {
        return;
    }  
    if(s[i]==x)
    {
        idx=i;
        return;
    }
    lastChar(s,i-1,x,idx);
}

int main()
{
    string s="asjgfasdkl";
    char x='s';
    int idx=0;
    lastChar(s,s.length()-1,x,idx);
    cout<<idx;
    return 0;
}