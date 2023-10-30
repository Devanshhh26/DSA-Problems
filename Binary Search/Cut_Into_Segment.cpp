#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int solve(int n,int x,int y,int z)
{
    if(n==0)
    {
        return 0;
    }
    if(n<0)
    {
        return INT16_MIN;
    }
    int ans1=solve(n-x,x,y,z);
    int ans2=solve(n-y,x,y,z);
    int ans3=solve(n-z,x,y,z);

    int ans=max(ans1,max(ans2,ans3));
    return ans;


}

int main()
{
    int n=7;
    int x=5;
    int y=2;
    int z=2;


    int ans=solve(n,x,y,z);
    if(ans<0)
    {
        cout<<0;
        return 0;
    }
    cout<<ans;

    return 0;
}