//  https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1

// ek map banaenge int,int ka fir usme int aur count daal denge a1 ke elements ka
// fir a2 ke elements ko one by one check karenge map me agar milega to uska count decrease kar denge by 1
// aur yeh bhi check karenge ki agar mila to uska count > 0 ho agar aesa nahi hai to iska matlab a2 me vo element zyada baar hai 
// agar nahi milta hai to return NO


#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main()
{   
   int a1[] = {11, 7, 1, 13, 21, 3, 7, 3};
   int a2[] = {11, 3, 7, 1, 7};
   int n=8;
   int m=5;
    unordered_map<int,int>mp;
    string ans="Yes";
    for(int i=0;i<n;i++)
    {
        mp[a1[i]]++;                            // a1 ke elements map karwa die
    }
    for(int i=0;i<m;i++)
    {   
        if(mp.find(a2[i])==mp.end())            // agar a2 ka element present na ho to
        {    
            ans="No";
            break;
        }    
        else{                                   // agar present hai to
            if(mp[a2[i]]>0)                     // check karo ki uska count 0 se bada ho if yes then -1 kar do
            {
                mp[a2[i]]--;
            }
            else{                               // else return NO
                ans="No";
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}