// https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/description/

// string a se shuru hogi to hi chance hai ki vo shayd valid ho

//  agar a aae to directly stack me push akrdo

// agar b aae to stack me tabhi push karo agar stack ke top me a rakha ho varna flase return kardo

// agar c aae aur stack ke top me b pada ho to b ko pop kardo aur varna return false
// agar top me b pada tha aur vo pop kardia fir check karo ki ab kya pada hai top me agar a pada hai to use bhi pop kardo aur agar kuch aur pada hai to return false

//agar end me stack empty ho to then it is valid varna invalid

#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
    string s="abcabcababcc";
    stack<int>st;
    if(s[0]!='a')
    {
        cout<<"Invalid";
        return 0;
    }
    for(char ch:s)
    {
        if(ch=='a')
        {
            st.push(ch);
        }
        else if(ch=='b')
        {
            if(!st.empty()&& st.top()=='a')
            {
                st.push(ch);
            }
            else{
                cout<<"Invlaid";
                return 0;
            }
        }
        else{
            if(!st.empty()&&st.top()=='b')
            {
                st.pop();

                if(!st.empty()&&st.top()=='a')
                {
                    st.pop();
                }
                else{
                    cout<<"Invalid";
                }
            }
            else{
                cout<<"Invalid";
            }
        }
    }
    if(st.empty())
    {
        cout<<"Valid";
    }
    else{
        cout<<"Invalid";
    }
    return 0;
}