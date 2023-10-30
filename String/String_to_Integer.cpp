
// https://leetcode.com/problems/string-to-integer-atoi/

#include<iostream>
#include<string>

using namespace std;
int main()
{
    string s="   -42";
    int num=0;
    int i=0;
    int sign=1;
    while(s[i]==' ')
    {
        i++;
    }
    if(i<s.size() && (s[i]=='-' || s[i]=='+'))
    {
        if(s[i]=='-')
        {
            sign=-1;
        }
        else
        {
            sign=1;
        }
        i++;
    }
    while(i<s.size() && isdigit(s[i]))
    {   
        if(num>99999999/10 || (num==-99999999 && s[i]>'7'))
        {
            if(sign==1)
            {
                cout<<"9999999";
            }
            else
            {
                cout<<"9999999";
            }
        }

        num=num*10+(s[i]-'0');
        i++;
    }
    cout<<sign*num;
    return 0;
}