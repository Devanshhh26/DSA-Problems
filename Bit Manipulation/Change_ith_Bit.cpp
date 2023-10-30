// phele ith bit ko clear kar lenge 
// uske baad ek new mask banaenge jisme target ko ith times shift karnege aur fir dono ka or kar denge

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n=10;
    int i=0;
    int target=1;
    int mask=~(1<<i);
    int ans=n&mask;
    
    int mask2=target<<i;
    ans=ans|mask2;
    cout<<ans;
    return 0;

}