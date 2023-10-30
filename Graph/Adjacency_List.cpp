#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
using namespace std;

class Graph{
    public:
            unordered_map<int,list<pair<int,int>>>adjlist;

            void addEdge(int u,int v,int weight,bool direction )
            {
                //direction= 0 = undirected graph
                // direction = 1 = directed graph
                
                // creating an edge from u to v
                adjlist[u].push_back({v,weight});
                if(direction==0)
                {
                    // undirected edge
                    // creating an edge from v to u
                    adjlist[v].push_back({u,weight});
                }
                
            }
            void printAdjacencyList()
            {
                for(auto node:adjlist)
                {
                    cout<<node.first<<" -> ";
                    for(auto neighbours:node.second)
                    {
                        cout<<"("<<neighbours.first<<","<<neighbours.second<<")";
                    }
                    cout<<endl;
                }
            }
};

int main()
{   
    // undirected graph
    cout<<"Undirected Graph"<<endl;
    Graph g1;

    

    //g1.addEdge(sourceNode,destinationNode,weight,direction)
    g1.addEdge(0,1,5,0);
    g1.addEdge(1,2,8,0);
    g1.addEdge(0,2,6,0);

    g1.printAdjacencyList();

    // directed graph
    cout<<"Directed Graph"<<endl;

    Graph g2;

    //g2.addEdge(sourceNode,destinationNode,weight,direction)
    g2.addEdge(0,1,5,1);
    g2.addEdge(1,2,8,1);
    g2.addEdge(0,2,6,1);

    g2.printAdjacencyList();
}