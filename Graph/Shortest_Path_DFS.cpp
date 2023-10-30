#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<unordered_map>
#include<algorithm>
#include<limits.h>
using namespace std;

class graph
{
    public:
    unordered_map<int,list<pair<int,int>>>adjlist;

    void addEdge(int u,int v,int wt,bool direction)
    {
        // if direction ==1 directed graph
        adjlist[u].push_back({v,wt});
        if(direction==1)
        {
            adjlist[v].push_back({u,wt});
        }
    }
    void printAdjList()
    {
        for(auto i:adjlist)
        {
            cout<<i.first<<"->";
            for(auto j:i.second)
            {
                cout<<"("<<j.first<<", "<<j.second<<"), ";
            }
            cout<<endl;
        }
    }
    void topoSortDFS(int src,int dest,unordered_map<int,bool>&visited,stack<int>&ans)
    {   
       visited[src]=true;
       for(auto nbr:adjlist[src])
       {
            if(!visited[nbr.first])
            {
                shortestPath(nbr.first,visited,ans);
            }
       }
       ans.push(src);
    }
    void shortestPath(int dest,stack<int>&topoOrder,int n)
    {
        vector<int>distance(n,INT_MAX);
        int src=topoOrder.top();
        topoOrder.pop();
        distance[src]=0;

        for(auto nbr:adjlist[0])
        {
            if(distance[0]+nbr.second<distance[nbr.first])
            {
                distance[nbr.first]=distance[0]+nbr.second;
            }
        }

        while(!topoOrder.empty())
        {
            int topElement=topoOrder.top();
            topoOrder.pop();
            if(distance[topElement]!=INT_MAX)
            {
                for(auto nbr:adjlist[topElement])
                {
                    if(distance[topElement]+nbr.second<distance[nbr.first])
                    {
                        distance[nbr.first]=distance[topElement]+nbr.second;
                    }
                }
            }
        }
        cout<<"Printing Ans : ";
        for(int i=0;i<n;i++)
        {
            cout<<i<<" -> "<<distance[i]<<endl;
        }
    }
};
int main()
{
    graph g;
    g.addEdge(0,1,5,1);
    g.addEdge(0,2,3,1);
    g.addEdge(2,1,2,1);
    g.addEdge(1,3,3,1);
    g.addEdge(2,3,5,1);
    g.addEdge(2,4,6,1);
    g.addEdge(4,3,1,1);
   
    g.printAdjList();

    int src=0;
    int dest=4;
    
    stack<int>topoOrder;
    unordered_map<int,bool>visited;
    g.topoSortDFS(0,visited,topoOrder);

    g.shortestPath(3,topoOrder,5);

}