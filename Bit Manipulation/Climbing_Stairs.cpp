// hume nth stair pe jana hai aur hum sirf 2^n me steps le sakte hai to hume yeh batana hai ki kitne steps me pahuch jaenge
// jitne set bits honge n me utne steps me pahuch janege

#include<iostream>
using namespace std;

int main()
{
    int n=5;
    int count=0;
    while(n!=0)
    {
        n=n&n-1;
        count++;
    }
    cout<<count;
    return 0;
}