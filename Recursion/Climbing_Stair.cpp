#include<iostream>
#include<limits.h>
using namespace std;

int climbingStairs(int n)
{
    if(n==1 ||n==0)
    {
        return 1;
    }
    int ans=climbingStairs(n-1)+climbingStairs(n-2);
    return ans;
}

int main()
{
    int n=5;
    int ans=climbingStairs(n);
    cout<<ans;
    return 0;
}