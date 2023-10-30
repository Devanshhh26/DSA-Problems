#include<iostream>
#include<queue>
using namespace std;

void print(queue<int>q)
{
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}

void reverseFirstK(queue<int>&q,int k)
{
    if(k==0)
    {
        return;
    }
    int temp=q.front();
    q.pop();
    reverseFirstK(q,k-1);
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
    int k=2;
    reverseFirstK(q,k);
    print(q);
}