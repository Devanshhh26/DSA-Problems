#include <iostream>
#include <vector>
using namespace std;

int main()
{   int target=10;
    double s = 0;
    double e = target-1;
    double mid = s + (e - s) / 2;
    double ans=0;
    while (s <= e)
    {
        if(mid*mid==target)
        {
            cout<<mid;
            return 0;
        }
        if(mid*mid<target)
        {
            s=mid+1;
            ans=mid;
        }
        if(mid*mid>target)
        {
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    cout<<ans;
    return 0;
}