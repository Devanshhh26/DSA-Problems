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

    // the code below this is to handle if the graph is disconnected otherwise line 81 would have been enough if the graph is not disconnected
    unordered_map<int, bool> visited;
    for(int i=0;i<=n;i++)
    {
        if(!visited[i])
        {
            g.bfs(i,visited);       // har node ko as a source maanke call kar rahe hai kyoki agar koi node disconnected hua to vo bhi cover ho jaega
                                    // aur jo node kisi already cover ho chuke hai kisi aur call me vo skip kar denge kyoki unka visited true hoga
        }
    }
}