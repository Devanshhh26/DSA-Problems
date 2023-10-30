#include<iostream>
#include<limits.h>
using namespace std;
void printDigits(int n)
{
    if(n==0)
    {
        return;
    }
    printDigits(n/10);
    int digit=n%10;
    cout<<digit<<" "<<endl;
}
int main()
{
    int n=647;
    printDigits(n);
    return 0;
}