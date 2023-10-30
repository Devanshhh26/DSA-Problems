
#include<iostream>
#include<stack>
#include<string>
using namespace std;

int countRev (string s)
{
    if(s.length()%2!=0)                 // odd length answer not possible
    {
        return -1;
    }
    int count=0;
    stack<int>st;
    for(int i=0;i<s.length();i++)
    {
        if(!st.empty()&& s[i]=='}'&& st.top()=='{')         // agar s[i]=="}" aur stack ke top pe "{" pada hai to fir pop kardo isse saare valid brackets nikal jaenge aur sif voh pairs rahenge jinhe change karna hai
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    while(!st.empty())                      // ab sirf vahi brackets bache hai jinhe change karna hai
    {
        char ch=st.top();
        st.pop();
        char ch2=st.top();
        st.pop();
        if(ch==ch2)                        // agar {{ aese brackets hue to matlab sirf ek bracket ko change karna hai so count++;
        {
            count++;
        }
        else{                               // agar }{ aese barckets hue to fir dono ko change karna hai so count+2
            count=count+2;
        }
    }
    return count;
    
}

int main()
{
    string s="}{{}}{{{";
    int count=countRev(s);
    cout<<count;
    return 0;
}