
//https://leetcode.com/problems/gas-station/

#include<iostream>
#include<vector>
using namespace std;

int main()
{   
    vector<int>gas={1,2,3,4,5};
    vector<int>cost={3,4,5,1,2};
        int deficit=0;
        int balance=0;
        int start=0;
        for(int i=0;i<gas.size();i++)
        {
            balance=balance+gas[i]-cost[i];
            if(balance<0)
            {
                deficit+=balance;
                start=i+1;
                balance=0;
            }
        }
        if(deficit+balance>=0)
        {
            cout<< start;
            return 0;
        }
        cout<<"Not Possible";
        return 0;
}