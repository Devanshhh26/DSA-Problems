#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjlist;

    void addEdge(int u, int v, bool direction)
    {
        // direction= 0 = undirected graph
        //  direction = 1 = directed graph

        // creating an edge from u to v
        adjlist[u].push_back(v);
        if (direction == 0)
        {
            // undirected edge
            // creating an edge from v to u
            adjlist[v].push_back(u);
        }
    }
    void printAdjacencyList()
    {
        for (auto node : adjlist)
        {
            cout << node.first << " -> ";
            for (auto neighbours : node.second)
            {
                cout << neighbours << " , ";
            }
            cout << endl;
        }
    }

    void bfs(int src, unordered_map<int, bool>&visited)
    {
        queue<int> q;
        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {   
            // printing front of queue 
            int frontNode = q.front();
            q.pop();
            cout << frontNode << " , ";

            // insert nodes connected to it

            for (auto neighbour : adjlist[frontNode])
            {   
                // agar vo element already visited hai to use firse add nahi karenge
                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }
    bool cycleCheckbfs(int src,unordered_map<int,bool>&visited)
    {   
        // agar koi node already visited hai aur vo parent node nahi hai to cycle present hai
        queue<int>q;
        q.push(src);
        unordered_map<int,int>parent;
        visited[src]=true;
        parent[src]=-1;
        while(!q.empty())
        {
            int frontNode=q.front();
            q.pop();

            for(auto neighbour:adjlist[frontNode])
            {
                if(!visited[neighbour])
                {   
                    // agar node visited nahi hai to use pusha krdo queue me aur uska visited bhi true mark kar do aur neighbour ke parent me frontnode daal do
                    q.push(neighbour);
                    visited[neighbour]=true;
                    parent[neighbour]=frontNode;
                }
                else{
                    if(visited[neighbour]   &&  neighbour!=parent[frontNode])    // neighbour already visited hai aur frontnode parent node nahi hai neoighbour ka to cycle present hai
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool checkCycleDfs(int src,unordered_map<int,bool>&visitedDfs,int parent)
    {
        visitedDfs[src]=true;
        for(auto neighbour:adjlist[src])
        {
            if(!visitedDfs[neighbour])
            {
                bool checkNextAns=checkCycleDfs(neighbour,visitedDfs,src);
                if(checkNextAns==true)
                {
                    return true;
                }
            }
            if(visitedDfs[neighbour]    && neighbour!=parent)
            {
                return true;
            }
        }
        return false;
    }

};

int main()
{
    Graph g;
    int n=4;    // number of nodes
    g.addEdge(0, 1, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(2, 4, 0);

    g.printAdjacencyList();
    cout << endl;

  //  g.bfs(0);

    //BFS Cycle Check
    // the code below this is to handle if the graph is disconnected otherwise line 81 would have been enough if the graph is not disconnected
    int ans=false;
    unordered_map<int, bool> visited;
    for(int i=0;i<=n;i++)
    {
        if(!visited[i])
        {
           ans=g.cycleCheckbfs(i,visited);
           if(ans==true)
           {
            break;
           }
        }
    }
    if(ans)
    {
        cout<<"Cycle is present"<<endl;
    }
    else{
        cout<<"No Cycle"<<endl;
    }


    //DFS Cycle Check
    int ansDfs=false;
    unordered_map<int, bool> visitedDfs;
    for(int i=0;i<=n;i++)
    {
        if(!visitedDfs[i])
        {
           ansDfs=g.checkCycleDfs(i,visitedDfs,-1);
           if(ansDfs==true)
           {
            break;
           }
        }
    }
    if(ansDfs)
    {
        cout<<"Cycle is present"<<endl;
    }
    else{
        cout<<"No Cycle"<<endl;
    }
}