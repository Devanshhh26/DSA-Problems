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
    void dfs(int src,unordered_map<int,bool>&visited)
    {   
        visited[src]=true;
        cout<<src<<" , ";
        for(auto neighbour:adjlist[src])
        {
            if(!visited[neighbour])
            {
                dfs(neighbour,visited);
            }
        }
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

    unordered_map<int,bool>visited;
    for(int i=0;i<=n;i++)
    {
        if(!visited[i])
        {
            g.dfs(i,visited);
        }
    }
}