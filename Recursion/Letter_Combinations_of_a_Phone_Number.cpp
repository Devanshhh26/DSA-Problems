
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void solve(vector<string>&ans,int index,string output,string digits,vector<string>&mapping)
{
    if(index>=digits.size())  
    {
        ans.push_back(output);
        return;
    }
    int digit=digits[index]-'0';        // Extract first digit from number eg-> extracting 2 from 234
    string value=mapping[digit];        //storing all the values corresponding to a number eg-> values corresponding to 2 = abc
    for(int i=0;i<value.size();i++)
    {
        char ch=value[i];               // Extracting first character from the values eg-> extracting a from abc
        output.push_back(ch);           // storing the character
        solve(ans,index+1,output,digits,mapping);   // solving one case using recursion
        output.pop_back();              // backtracking
    }
}

int main()
{   
    string digits="23";
    vector<string>ans;
    if(digits.length()==0)
    {
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i];
        }
        return 0;
     
    }
    int index=0;
    string output="";
    vector<string>mapping(10);
    mapping[2]="abc";
    mapping[3]="def";
    mapping[4]="ghi";
    mapping[5]="jkl";
    mapping[6]="mno";
    mapping[7]="pqrs";
    mapping[8]="tuv";
    mapping[9]="wxyz";
    solve(ans,index,output,digits,mapping);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}