#include<iostream>
#include<vector>
using namespace std;

int main()
{   
    string str="abc";
    vector<string>ans;
    int n=str.length();
    for(int num=0;num<(1<<n);num++)
    {
        string temp="";
        // we will create subsequence string in temp string
        for(int i=0;i<n;i++)
        {
            char ch=str[i];
            if(num && (1<<i))
            {
                // non zero value ke lie current character ko include karlo
                temp.push_back(ch);
            }
        }
        if(temp.length()>0)
        {
            ans.push_back(temp);
        }
    }
    for(auto it:ans)
    {
        cout<<it<<endl;
    }
    return 0;   
}