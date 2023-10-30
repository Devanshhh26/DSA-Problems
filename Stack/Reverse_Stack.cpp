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
        s.push(num);
        return;
    }
    int temp=s.top();
    s.pop();
    insertAtBottom(s,num);
    s.push(temp);
}

void reverseStack(stack<int>&s)
{
    // base case
    if(s.empty())
    {
        return ;
    }

    int target=s.top();
    s.pop();


    // reverse stack
    reverseStack(s);

    // insert at bottom
    insertAtBottom(s,target);
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
    cout<<"before reversing"<<endl;
    print(s);
    cout<<endl;
    reverseStack(s);
    cout<<"after ireversing"<<endl;
    print(s);
    return 0;
}