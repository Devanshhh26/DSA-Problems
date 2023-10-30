#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    string s="thirivananthpuram";
    unordered_map<char,int>mp;
    for(int i=0;i<s.length();i++)
    {
        mp[s[i]]++;
    }
    for(auto i:mp)
    {
        cout<<i.first<<"-> "<<i.second<<endl;
    }
    return 0;
}