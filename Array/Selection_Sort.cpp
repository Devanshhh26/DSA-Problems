#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int>res{45,2,89,21,56,35,98};
    for(int i=0;i<res.size();i++)
    {
        int min_index=i;
        for(int j=i+1;j<res.size()-1;j++)
        {
            if(res[j]<res[min_index])
            {
                min_index=j;
            }
        }
        swap(res[i],res[min_index]);
    }
    for(auto it:res)
    {
        cout<<it<<endl;
    }
    return 0;
}