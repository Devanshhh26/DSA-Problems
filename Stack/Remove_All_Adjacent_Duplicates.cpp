
//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/

#include <iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;
int main()
{
    string s="abbaca";
    stack<int>st;
    for(int i=0;i<s.length();i++)
    {
        if(!st.empty()&& st.top()==s[i])        // agar stack ka top string ke element ke equal hai to pop karenge varna push
        {
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }
    string ans="";
    int i=0;
    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
    return 0;

}