// agar koi number 2 ki power hai to usme sirf 1 set bit hogi aur saare 0 honge 
// method 1: set bits count kar sakte hai


// method 2: 
#include<iostream>
using namespace std;

int main()
{
    int n=10;
    int ans=n&(n-1);                                  // n & n-1 humesha zero ke equal hota hai to agar hum 8 & 7 karenge to 0 aaega
    if(ans==0)
    {
        cout<<"It is power of 2";
        return 0;
    }
    else{
        cout<<"It is not power if 2";
    }
    return 0;
}