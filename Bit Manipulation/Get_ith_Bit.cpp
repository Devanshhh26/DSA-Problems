#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n=10;
    int i=3;
    int mask=1<<i;              // 1 ->   0000....00001  ise ith times left shift kar dia i.e. 0000....01000 is uska 1010 (10 in binary) se & kar dia 
    int ans=n&mask;
    if(ans==0)
    {
        cout<<0;
    }
    else{
        cout<<1;
    }
    return 0;
}