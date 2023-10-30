#include<iostream>
#include<string>
using namespace std;

void addString(string& s1,string s2,int i,int n)
{
    if(i>n)
    {
        return;
    }
    s1=s1+s2[i];
    addString(s1,s2,i+1,n);
}

int main()
{
    string s1="raytheon";
    string s2="hammer";
    addString(s1,s2,0,s2.length()-1);
    cout<<s1;
    return 0;
}