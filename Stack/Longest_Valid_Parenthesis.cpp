//  https://leetcode.com/problems/longest-valid-parentheses/description/

// phele stack me -1 daal do

// agar "(" aaye to uska index daal do

// uske baad agar ")" aaya to stack ko pop kardo aur check karo agar stack empty ho to currrent index push kardo aur agar empty na ho to length nikal do

// length= current index- s.top()

// end me maxlength return kar denege


#include<iostream>

// pehle stack me -1 push kardo 
// jab bhi ( aaye to stack me uska index push kardo 
// jab bhi ) aaye to stack se pop top element pop kardo aur check karo ki kya stack empty hai
// agar stack empty hai to matlab invalid paranthesis tha vo isliye uska index push kardo stack me
// agar stack empty nahi tha to length nikal lo i - st.top se
// aur fir max len se compare karke check karlo kaunsa max hai 

#include<stack>
#include<string>
using namespace std;

int main()
{   
    string s=")()())";
    stack<int>st;
        st.push(-1);        // -1 insert kar dia
        int maxlen=0;
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            if(ch=='(')         // agar ( hai to stack me uska index push kar dia
            {
                st.push(i);
            }
            else{
                st.pop();         // agar ) hai to pehle stack se pop kia top element ko 
                if(st.empty())      // fir check kia ki kya stack empty hai ya nahi
                {
                    st.push(i);     // agar haan to stack me ) ka index push kardo
                }
                else{
                    int len=i-st.top();         // agar nahi to fir len nikal lo i - st.top karke
                    maxlen=max(len,maxlen);     // aur fir maxlen nikal lenge
                }
            }
        }
        cout<<maxlen;
        return 0;
}