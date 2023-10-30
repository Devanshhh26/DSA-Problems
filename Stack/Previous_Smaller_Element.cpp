#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

// same as next smaller element but loop start from 0 instead of n-1 and no need to reverse answer

int main()
{
    stack<int>st;
    vector<int>arr={2,1,4,3};
    vector<int>res;
    st.push(-1);
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>st.top())                             // agar top chota hai to res me add kardo aur arr[i] ko bhi stack me push kardo
        {
            res.push_back(st.top());
            st.push(arr[i]);
        }
        else{
            while(st.top()>arr[i])                      // agar top bada hai to tab tak stack ko pop karo jabtak koi smaller element nahi mil jata
            {                                           // aur jab smaller element mil jae to use res me add karo aur fir arr[i] ko stack me push kardo
                st.pop();
            }
            res.push_back(st.top());
            st.push(arr[i]);
        }
    }
    for(auto x:res)
    {
        cout<<x<<" ";
    }
    return 0;
}