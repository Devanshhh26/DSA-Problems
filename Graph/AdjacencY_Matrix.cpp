#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cout<<"Enter number of node : "<<endl;
    cin>>n;

    vector<vector<int>>adj(n,(vector<int>(n,0)));
    int e;
    cout<<"Enter the number of edges : "<<endl;
    cin>>e;


    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        // edge represent karne ke lie 1 mark kardo
        adj[u][v]=1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}