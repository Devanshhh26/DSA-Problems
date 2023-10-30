
// https://leetcode.com/problems/largest-number/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


static bool mycomp(string a, string b)
{
    string t1=a+b;
    string t2=b+a;

    return t1>t2;
}
int main()
{
    vector<int>nums{10,22,38,60,31,6};
    vector<string>s;
    string ans="";
    for(auto n:nums)
    {
        s.push_back(to_string(n));
    }
    sort(s.begin(),s.end(),mycomp);
    if(s[0]=="0")
    {
        cout<<"0";
        return 0;
    }
    for(auto str:s)
    {
        ans=ans+str;
    }
    cout<<ans;

    return 0;

}