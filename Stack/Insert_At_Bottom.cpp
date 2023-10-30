#include<iostream>
#include<stack>
using namespace std;

void print(stack<int>s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}

void insertAtBottom(stack<int>&s,int num)
{
    if(s.empty())
    {
        s.push(num);        // agar stack empty hai to push kardo element
        return;
    }
    int temp=s.top();   
    s.pop();
    insertAtBottom(s,num);
    s.push(temp);           // backtracking
}

int main()
{
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    int num=60;
    cout<<"before inserting"<<endl;
    print(s);
    cout<<endl;
    insertAtBottom(s,num);
    cout<<"after inserting"<<endl;
    print(s);
    return 0;
}