// https://leetcode.com/problems/letter-case-permutation/

#include<iostream>
#include<string>
#include<vector>

using namespace std;
void solve(string ip,string op,vector<string>&res)
{
    if(ip.length()==0)
    {
        res.push_back(op);
        return;
    }
    if(isalpha(ip[0]))                                      // agar alphabet ho to
    {
        string op1=op;                                      // op1 ko op se initialize kardo
        string op2=op;                                      // op2 ko op se initialize kar do
        op1.push_back(tolower(ip[0]));                      // op1 me ip[0] ko lowercase  me push kardo
        op2.push_back(toupper(ip[0]));                      // op 2 me ip[0] ko upper case  me push kar do
        ip.erase(ip.begin()+0);                            // string ke first element ko erase kardo
        solve(ip,op1,res);                                 //recursive call kardo op1 ke lie
        solve(ip,op2,res);                                  // revcursive call kardo op2 ke lie
    }
    else{                                                     // agar number ho to
        string op1=op;                                        // op1 ko op se initialize kardo
        op1.push_back(ip[0]);                                   // op1 me as it is ip[0] ko push kardo
        ip.erase(ip.begin()+0);                                 // remove kardo string ke first element ko 
        solve(ip,op1,res);                                      // recursive call kardo op1 ke lie
    }
}

int main()
{
    string ip="a1b2";
    string op="";

    vector<string>res;
    
    solve(ip,op,res);
    for(auto it:res)
    {
        cout<<it<<endl;
    }
    return 0;
}