#include<iostream>
#include<string>
using namespace std;

void solve(string ip,string op)
{
    if(ip.length()==0)                  // agar input ki length 0 ho jae to op print karwa do
    {
        cout<<op<<endl;
        return;
    }
    string op1=op;                      // op1 aur op2 ko op se initialise kardo
    string op2=op;
    op1.push_back(ip[0]);               // op1 me input ka first element daal do jo lowercase me hai
    op2.push_back(toupper(ip[0]));      // op2 me input ka first element daal do uppercase me convert karke
    ip.erase(ip.begin()+0);             // 0th index me jo element pada ho use delete kardo (hum jo jo element ko process karte jaenge use remove karte jaenge input se)
    solve(ip,op1);                      // op1 ke sath recursive call mardo
    solve(ip,op2);                      // op2 ke sath recursive call mardo
}

int main()
{
    string ip="ab";
    string op="";
    solve(ip,op);
    return 0;
}