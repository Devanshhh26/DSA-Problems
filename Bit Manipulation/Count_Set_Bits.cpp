#include<iostream>
using namespace std;

void countSetBit(int n,int count)
{
    while(n!=0)
    {
        if(n&1==1)
        {
            count++;
        }
        n=n>>1;
    }
    cout<<count<<endl;
}

void fastCountSetBit(int n,int fastCount)
{
    while(n!=0)
    {
        n=(n&(n-1));            // removes last set bit
        fastCount++;
    }
    cout<<fastCount;
}

int main()
{
    int n=10;
    int count=0;
    countSetBit(n,count);
    int fastCount=0;
    fastCountSetBit(n,fastCount);
    return 0;   
}