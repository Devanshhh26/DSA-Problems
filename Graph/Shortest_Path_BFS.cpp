#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<unordered_map>
#include<algorithm>
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
    void shortestPath(int src,int dest)
    {   
        // normal bfs tarversal
        queue<int>q;
        unordered_map<int,bool>visited;
        unordered_map<int,int>parent;
        q.push(src);                            // src ko queue me add kar dia aur uska visited true mark kar dia aur parent me -1 daal dia
        visited[src]=true;
        parent[src]=-1;                         
        while(!q.empty())
        {   
            int frontNode=q.front();            //q ka first element nikala aur frontnode me store kar lia
            q.pop();
            for(auto nbr:adjlist[frontNode])       // front node ke saare neighbouring nodes ko tarverse kia
            {
               if(!visited[nbr.first])              // agar vo already visited hai to skip kar do
                {
                    q.push(nbr.first);              // else unhe q me push kardo
                    visited[nbr.first]=true;        // uska visited true mark kar do
                    parent[nbr.first]=frontNode;    // aur front node ko unka parent set kardo
                }

            }
        }
        // node jab tak -1 nahi ho jaata tab tak hum uske parent me jaate rahenege aur use ans me store karte rahenge
        vector<int>ans;
        int node=dest;
        while(node!=-1)
        {
            ans.push_back(node);
            node=parent[node];
        }
        
        // ans ulta aaega islie use reverse kare denge
        reverse(ans.begin(),ans.end());
              
        cout<<"Printing Node : ";
        for(auto i:ans)
        {
            cout<<i<<",";
        }
        cout<<endl;


    }
};
int main()
{
    graph g;
    g.addEdge(0,1,1,0);
    g.addEdge(1,2,1,0);
    g.addEdge(2,3,1,0);
    g.addEdge(3,4,1,0);
    g.addEdge(0,5,1,0);
    g.addEdge(5,4,1,0);
    g.addEdge(0,6,1,0);
    g.addEdge(6,7,1,0);
    g.addEdge(7,8,1,0);
    g.addEdge(8,4,1,0);
    g.printAdjList();

    int src=0;
    int dest=4;

    g.shortestPath(src,dest);
}