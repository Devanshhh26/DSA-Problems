//  https://www.spoj.com/problems/DEFKIN/

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

int main()
{
    int x,y,n;
    cin>>x>>y>>n;
    int t=n;
    vector<int>row;
    vector<int>col;
    row.push_back(0);
    col.push_back(0);
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        row.push_back(a);
        col.push_back(b);
    }
    row.push_back(x+1);
    col.push_back(y+1);

    sort(row.begin(),row.end());
    sort(col.begin(),col.end());

    int maxLen=INT_MIN;
    for(int i=0;i<row.size();i++)
    {
        int a=row[i-1];
        int b=row[i];
        maxLen=max(maxLen,b-a-1);
        
    }

    int maxWidth=INT_MIN;
    for(int i=0;i<col.size();i++)
    {
        int a=col[i-1];
        int b=col[i];
        maxWidth=max(maxWidth,b-a-1);
    }
    cout<<"Answer : "<<maxLen*maxWidth<<endl;
    return 0;
}