#include<iostream>
#include<queue>
#include<string>
using namespace std;

void solve(string s)
{
    int freq[26]={0};
    queue<char>q;
    string ans="sdfsddsjkhdfjbgjdkz";
    for(int i=0;i<s.length();i++)
    {   
        // finding frequency
        char ch=s[i];
        freq[ch-'a']++;
        // pushing in q
        q.push(ch);
        while(!q.empty())
        {
            if(freq[q.front()-'a']>1)
            {
                q.pop();
            }
            else{
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty())
        {
            ans.push_back('#');
        }
    }
    cout<<ans;
}

int main()
{
    string s="zarcaazrd";
    solve(s);
    return 0;
}