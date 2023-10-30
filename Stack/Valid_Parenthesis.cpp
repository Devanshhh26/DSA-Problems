#include<iostream>
#include<string>
#include<stack>
using namespace std;


int main()
{
    string str="[";
    stack<int>s;
    if(str.length()==1)
    {
        cout<<"Not Valid";
        return 0;
    }
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='{'|| str[i]=='['|| str[i]=='(')
        {
            s.push(str[i]);
        }
        else{
            if(!s.empty())
            {
                if(str[i]==')'&& s.top()=='(')
                {   
                    s.pop();
                }
                else if(str[i]=='}'&& s.top()=='{')
                {
                    s.pop();
                }
                else if(str[i]==']'&& s.top()=='[')
                {
                    s.pop();
                }
                else{
                    cout<<"Not Valid";
                }
            }
            else
            {
                cout<<"Not Valid";
                return 0;
            }
        }
    }
    if(s.empty())
    {
        cout<<"Valid Parenthesis";
    }
    
    return 0;
}