// we have to find the max number of train that can pass in a day
// similar to https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1

// ek pair bana lenge arrival aur departure time ka aur fir use sort kar denge according to departure time
// agar next train ka arrival time current train ke departure se zyada hua it means vo baad me aaegi to it is possible isliye count++ kar denge
// agar kam hua to it means yeh possible nahi hai 


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool mycomp(pair<int,int>a,pair<int,int>b)
{
    return a.second<b.second;
}

int solve(int n,int arr[],int dept[])
{
    vector<pair<int,int>>data;                  // pair bana lia arrival aur departure ka
    for(int i=0;i<n;i++)
    {
        data.push_back({arr[i],dept[i]});
    }
    sort(data.begin(),data.end(),mycomp);       // sort kar lia according to departure time

    int count=1;                                // 1 train to aaegi hi isliye count 1 kar lia
    int lastDept=data[0].second;                //  1st train ka departure time store kara lia
    for(int i=1;i<n;i++)                        // loop 1 se shuru karenge kyoki count 1 se hai
    {
        if(data[i].first>=lastDept)             // curr ka arrival time check karenge agar previous train ke departure se bada hai to count++
        {
            count++;
            lastDept=data[i].second;            // curr train ka departure time store ka lenge lastDept me 
        }
    }
    return count;
}

int main()
{
    int n=4;
    int arr[]={5,8,2,4};
    int dept[]={7,11,6,5};

    int ans=solve(n,arr,dept);
    cout<<"Ans is : "<<ans;
    return 0;
}