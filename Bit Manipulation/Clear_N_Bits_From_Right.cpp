#include<iostream>
using namespace std;

int main()
{
    int n=7;
    int i=2;
    int mask=(-1<<i);          // -1 = 11111111...11111 to hum jub use 2 baar right shift karenge 1111111....111100 fir 7 se & kar denge to end ke bits clear ho jaenge 
    int ans=n&mask;
    cout<<ans;
    return 0;
}