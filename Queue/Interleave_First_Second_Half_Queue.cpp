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

void interleaveQueue(queue<int>&q)
{

    int n=q.size();
    if(n==0)
        return;
    int k=n/2;
    int count=0;

    // Step 1: push the first half of q in the q2

    queue<int>q2;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        q2.push(temp);
        count++;

        if(count==k)
        {
            break;
        }
    }

    // Step 2: interleaving start
    while(!q.empty()&& !q2.empty())
    {
        // q2 se ek element nikal ke q me push kardia
        int first=q2.front();
        q2.pop();
        q.push(first);

        // q se ek element nikal ke firse q me push kardia
        int second=q.front();
        q.pop();
        q.push(second);
    }
    // to check if size of q is odd
    if(n&1)
    {
        int element=q.front();
        q.pop();
        q.push(element);
    }

}

int main()
{
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    interleaveQueue(q);
    print(q);
    return 0;
}