#include <iostream>
using namespace std;
int main()
{
    int arr[11] = {1,1,2,2,3,4,4,5,5,6,6};
    int ans=0;
    for(int i=0;i<11;i++)
    {
        ans=ans^arr[i];
    }
    cout<<ans;
}