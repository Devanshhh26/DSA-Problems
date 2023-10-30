
// https://leetcode.com/problems/generate-parentheses/description/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

void solve(vector<string>&ans,int n,int open,int close,string& output)
{
    if(open==0 && close==0)
    {
        ans.push_back(output);
        return ;
    }
    if(open>=0)                             // if open paranthesis is left to be assigned
    {
        output.push_back('(');              // add '('
        solve(ans,n,open-1,close,output);   // decrease the count of open and call recursion
        output.pop_back();                  // backtracking
    }
    if(close>open)                          // if close > open then it means there is still some closing parenthesis to assigned for it to be a valid paranthesis
    {
        output.push_back(')');              // add ')'
        solve(ans,n,open,close-1,output);   //decrease the count of close and call recursion
        output.pop_back();                  // backtracking
    }
}

int main()
{
    int n=3;
    vector<string>ans;
    string output="";
    int open=n;
    int close=n;
    solve(ans,n,open,close,output);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    return 0;
}