// nearly sorted ka matlab jo element ith position me hona chahiye tha vo i me bhi ho sakta hai i+1 me bhi ho sakta hai aur 
// i-1 me bhi ho sakta hai 

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
       if(res[mid]==target)     // agar target mid ke equal hai to return kardo
       {
        cout<<mid;
        return 0;
       }
       if(res[mid-1]==target && mid-1>0)        // agar mid ke equal nahi hai to ek baar mid se ek pehle element ko bhi check karlo
       {
        cout<<mid-1;
        return 0;
       }
       if(res[mid+1]==target && mid+1<res.size())   // ek baar mid ke baad vale element ko bhi check karlo
       {
        cout<<mid+1;
        return 0;
       }
       if(target>res[mid])      // agar nahi mila aur target mid se bada hai to start ko mid+2 karo kyoki hum already mid+1 check kar chuke hai upar
       {
        s=mid+2;
       }
       if(target<res[mid])      // target mid se chota hua to end ko mid-2 karo kyoki mid-1 hum already check kar chuke hai
       {
        e=mid-2;
       }
       mid=s+(e-s)/2;
    }
    return 0;
}