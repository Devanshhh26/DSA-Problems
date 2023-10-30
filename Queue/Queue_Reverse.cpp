#include<iostream>
#include<stack>
#include<queue>
using namespace std;

// Method 1 : Using Stack

// Method 2: USing Recursion

void print(queue<int>q)
{
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}

void reverseQ(queue<int>&q)
{
    if(q.empty())
    {   
        return;
    }
    int temp=q.front();
    q.pop();
    reverseQ(q);
    q.push(temp);
}

int main()
{
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    reverseQ(q);
    print(q);
}