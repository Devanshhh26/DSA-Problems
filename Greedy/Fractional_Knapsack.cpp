// value/weight ka ratio nikalo au fir use descending order me sort kardo
// one by one item nikalo aur check karo ki kya use pura daal sakte hai (weight<capacity) ya fir fraction me daalna padega(weight>capacity)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool mycomp(pair<int,int>a,pair<int,int>b)              // sort kar dia ratio ke basis pe (descending order)
{
    double ratio1=((1.0)*a.first)/a.second;
    double ratio2=((1.0)*b.first)/b.second;
    return ratio1>ratio2;
}

int main()
{
    int val[]={60,100,120};
    int wt[]={10,20,30};
    int capacity=50;
    int n=3;

    vector<pair<int,int>>data;
    for(int i=0;i<n;i++)
    {
        data.push_back({val[i],wt[i]});                 // value aur weight ka pair bana ke add kar dia vector me
    }
    sort(data.begin(),data.end(),mycomp);

    int totalValue=0;
    for(int i=0;i<n;i++)
    {
        pair<int,int>item=data[i];                      // data vector ka element pick karo aur uski value ek variable me store karo aur uska weight dusre variable me
        int itemValue=item.first;               
        int itemWeight=item.second;
        if(itemWeight<capacity)                         // agar item ka weight capacity se kam ho to total me uski value add kar do aur capacity se uska weight minus kar do
        {
            totalValue+=itemValue;
            capacity=capacity-itemWeight;
        }
        else{                                           // agar item ka weight capacity se zyada ho to hume use fraction me add karna hoga 
            int ratio=((1.0)*itemValue)/itemWeight;
            int fractionValue=ratio*capacity;
            totalValue+=fractionValue;
            capacity=0;
        }
    }
    cout<<totalValue;
    return 0;
}
