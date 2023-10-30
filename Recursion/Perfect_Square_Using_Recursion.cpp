#include<iostream>
#include<cmath>
using namespace std;

int perfectSquareHelper(int n)
{
    if(n==0)
    {
        return 1;
    }
    if(n<0)
    {
        return 0;
    }
    int i=1;
    int ans=INT16_MAX;
    int end=sqrt(n);                // we will only run loop until i is less than or equal to the square root of n
    while(i<=end)
    {
        int perfectSquare=i*i;     
        int numberOfPerfectSquare=1+perfectSquareHelper(n-perfectSquare);
        ans=min(numberOfPerfectSquare,ans);
        i++;
    }
    return ans;
}

int main()
{
    int n=13;
    int ans=perfectSquareHelper(n)-1;
    cout<<ans;
    return 0;
}