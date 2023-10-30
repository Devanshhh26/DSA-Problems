// https://leetcode.com/problems/beautiful-arrangement/

#include<iostream>
#include<vector>

using namespace std;

void countArrangement(vector<int>&v,int& ans,int& n,int currNum)
{
    if(currNum==n+1)                                            // agar currNum==n+1 ho jae matlab ki ans mil gaya hai to ans++ kar denge aur return kar denge
    {
        ++ans;
        return;
    }
    for(int i=1;i<=n;i++)                                       // loop chalanege 1 se n tak
    {
        if(v[i]==0 && (currNum%i==0 ||  i%currNum==0))          // agar v[i]==0 hua to matlab ki vo jagah abhi khaali hai aur vaha element daal sakte hai aur currNum%i==0 aur i%currNum==0 me se ek bhi condition true hui to matlab valid position hai
        {   
            v[i]=currNum;                                       // vaha element daal dia
            countArrangement(v,ans,n,currNum+1);                // recursion
            v[i]=0;                                             // backtrack karke vaha vapis 0 daal dia
        }
    }
}

int main()
{
    int n=10;
    vector<int>v(n+1);                          // vector bataega kis position me rakha hai aur jab hu m vector ki aese size define karte hai to har index pe automatically 0 assign ho jata hai
    int ans=0;
    countArrangement(v,ans,n,1);
    cout<<ans;
    return 0;
}