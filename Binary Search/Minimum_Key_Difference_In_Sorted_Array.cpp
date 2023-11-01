//hume array di hogi aur key di hogi aur hume vo element nikalna hai jisse key ko minus karenge to minimum difference aaega
// agar key jaisa element hi present hua to vo ans hoga kyoki unka difference 0 hoga
// agar nahi hua to to usse just chota ya just bada element hi answer de sakta hai 


#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int>res{2,3,8,10,15};
    int key=12;

    int justBefore=0;
    int justAfter=0;
    int start=0;
    int end=res.size()-1;
    while(start<=end)                           // agar key present nahi hai array me to at the end start aur end key ke sabse closest 2 elements ko point karenge (that is key ke aage peeche vale element)
    {
        int mid=start+(end-start)/2;
        if(res[mid]==key)
        {
            cout<<0;
            return 0;
        }
        if(res[mid]<key)
        {
           // justBefore=mid;                   // isse bhi kar sakte hai but start end  bhai hume vo hi bata rahe hai
            start=mid+1;
        }
        if(res[mid]>key)
        {
          // justAfter=mid;                     // isse bhi kar sakte hai but start end  bhai hume vo hi bata rahe hai
            end=mid-1;
        }
    }
    int ans=min(abs(key-res[start]),abs(key-res[end]));
    cout<<ans;
    return 0;
}