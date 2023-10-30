// agar edge u->v hai to result me bhi u pehle aaega v se
// Topological sort laganeke lie DAG -> Directed Acyclic Graph hona compulsory hai

#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <queue>
#include<stack>
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
    void topologicalSortDfs(int src,unordered_map<int,bool>&visited,stack<int>&ans)
    {
        visited[src]=true;
        for(auto neighbour:adjlist[src])
        {
            if(!visited[neighbour])
            {
                topologicalSortDfs(neighbour,visited,ans);
            }
        }
        // while returning store the node in stack
        ans.push(src);
    }

    void topologicalSortBfs(int n, vector<int>&bfsAns)
    {
        queue<int>q;
        unordered_map<int,int>indegree;

        for(auto i:adjlist)
        {
            int src=i.first;
            for(auto nbr:i.second)
            {
                indegree[nbr]++;
            }
        }

        // put all nodes in queue which have indegree 0
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int frontNode=q.front();
            q.pop();
            bfsAns.push_back(frontNode);
            for(auto nbr:adjlist[frontNode])
            {
                indegree[nbr]--;
                if(indegree[nbr]==0)
                {
                    q.push(nbr);
                }
            }
        }
    }
};

int main()
{
    Graph g;
    int n=8;    // number of nodes
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 6, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 7, 1);

    g.printAdjacencyList();
    cout << endl;

    unordered_map<int,bool>visited;
    stack<int>ans;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            g.topologicalSortDfs(i,visited,ans);
        }
    }
    cout<<"Topological Sort Dfs : "<<endl;
    while(!ans.empty())
    {
        cout<<ans.top()<<" ";
        ans.pop();
    }

    // using bfs
    vector<int>bfsAns;
    g.topologicalSortBfs(n,bfsAns);
    cout<<"Bfs Ans : ";
    for(int i=0;i<n;i++)
    {
        cout<<bfsAns[i]<<" , ";
    }

    return 0;
}