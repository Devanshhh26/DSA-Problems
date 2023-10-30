#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int dividend=22;
    int divisor=0;
    int s = 1;
    int e = dividend;
    int mid = s + (e - s) / 2;
    int ans=0;
    while (s <=e)
    {
       if(abs(mid*divisor)==dividend)
       {
        cout<<mid;
        return 0;
       }
       if(abs(mid*divisor)<dividend)
       {
        ans=mid;
        s=mid+1;
       }
       if(abs(mid*divisor)>dividend)
       {
        e=mid-1;
       }
       mid=s+(e-s)/2;
    }
    
   if((dividend>0 && divisor>0)||(dividend<0 && divisor<0))
   {
    cout<<ans;
   }
   else{
    cout<<-ans;
   }
    return 0;
}