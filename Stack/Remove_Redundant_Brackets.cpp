// basic algo yeh hai ki ( operator ) hai to fir vo valid hai else redundant

// agar ( aaye to use stack me push kardo
// agar operator aaye to use bhi stack me push kardo
// agar ) aaye to stack me check karo uske corresponding koi ( hai ya nahi aur ek operator flag bhi bana lo jo bataega ki
// brackets ke beechme koi operator tha ya nahi agar operator tha to fir vo valid tha otherwise redundant 



#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
    stack<int>s;
    string str="(a+b)+((d*c)/e)";
    for(int i=0;i<str.length();i++)
    {   
        bool flag=0;
        if(str[i]=='('||str[i]=='+')            // ( aur operator ko stack me push kar dia
        {
            s.push(str[i]);
        }
        if(str[i]==')')                        // agar s[i]=) top stack ka top check karenge agar operator hua to flag ko 1 kar denge
        {
            if(s.top()=='+')
            {
                flag=1;
            }
        }
        if(flag==1)                             // agar flag 1 hua to hum stack ko tab tak pop karenge jab tak hume ( na mil jae
        {
            while(s.top()!='('&& s.top()!=-1)
            {
                s.pop();
            }
            s.pop();                            // jab ( mil jaega to use pop kar denge aur flag ko firse 0 initialize kardenge
            flag=0;
        }
    }
    while(s.top()!='('||s.top()!=')'&&!s.empty())       // agar stack me operator pada ho end me to use pop kar do
    {
        s.pop();
    }
    if(s.size()>0)                               // agar stack empty nahi hai to matlab redundant brackets present hai
    {
        cout<<"Redundant Brackets found";
    }
    else{
        cout<<"No redundant brackets found";
    }
    return 0;
}