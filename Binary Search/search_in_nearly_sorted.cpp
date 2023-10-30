#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> res{10,3,40,20,50,80,70};
    int s = 0;
    int e = res.size() - 1;
    int mid = s + (e - s) / 2;
    int target=7;
    while (s <=e)
    {
       if(res[mid]==target)
       {
        cout<<mid;
        return 0;
       }
       if(res[mid-1]==target && mid-1>0)
       {
        cout<<mid-1;
        return 0;
       }
       if(res[mid+1]==target && mid+1<res.size())
       {
        cout<<mid+1;
        return 0;
       }
       if(target>res[mid])
       {
        s=mid+2;
       }
       if(target<res[mid])
       {
        e=mid-2;
       }
       mid=s+(e-s)/2;
    }
    return 0;
}