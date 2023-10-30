//  https://leetcode.com/problems/simplify-path/

// if we get /.. then go to previous directory

// if we get /. then do nothing

// if we get /a or /b push it into stack

// if we get / then ignore it

// hum ek slash se shuru karenge aur next slash aane se ek pehle ko ek path manenge

#include<iostream>
#include<stack>
#include<string>
using namespace std;

void reverseStack(stack<string>&st,string& ans)
{
    if(st.empty())
    {
        return ;
    }
    string ch=st.top();
    st.pop();
    reverseStack(st,ans);
    ans=ans+ch;
}

int main()
{   
    string path="/home//foo/";
    stack<string>st;
    int i=0;
    while(i<path.size())
    {
        int start=i;
        int end=i+1;
        while(end<path.size() && path[end]!='/')        // start ko first slash pe aur end ko next slash me put kar rahe hai
        {
            ++end;
        }
        string minPath=path.substr(start,end-start);    // start se leke end ke beech ki substring nikal rahe hai
        i=end;
        if(minPath=="/"||minPath=="/.")                 // ab uss substring ko check kar rahe hai
        {
            continue;
        }
        if(minPath!="/..")                              // it means it can be /a or /b or /c or any directory   so we push it into stack
        {
            st.push(minPath);
        }
        else if(!st.empty())                            // it means it is /.. so we pop from stack
        {
            st.pop();
        }
    }
    string ans=st.empty()?"/":"";                       // agar input me sirf /.. dia hoga to jab hum pop karenge to stack empty ho jaega isle hum sirf / return kar denege
    reverseStack(st,ans);                               // stack se pop karne pe ans uslta aaega isle use reverse kar denge
    cout<<ans;
    return 0;
}