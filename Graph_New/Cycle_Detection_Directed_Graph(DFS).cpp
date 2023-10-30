// basic idea yeh hai ki agar hum jis element ko check kar rahe hai to uske visited aur dfsvisited ko true mark kar denge aur neighbours ko visit karenge agar aesa karte 
// vakt hume koiu aesa neighbour milta hai jo already visited ho aur jiska dfsvisited bhi true ho to iska matlab cycle present hai but agar aesa nahi hota to vapis aate vakt 
// hum uss element ke dfvisited ko firse false mark kar denge

#include<iostream>
#include<unordered_map>
#include<list>

bool checkCycle(int node,unordered_map<int,bool>&visited,unordered_map<int,bool>dfsVisited,unordered_map<int,list<int>>&adj)
{   
  visited[node]=true;                                                         // element ka visited true kar denge
  dfsVisited[node]=true;                                                        // element ka dfs visited bhi tru ekar denge

  for(auto neighbour:adj[node])                                                 // ab element ke neighbouring connected elements ke lie call karenge agar vo visited nahi hue to
  {
    if(!visited[neighbour])
    {
      bool cycleDetected=checkCycle(neighbour,visited,dfsVisited,adj);
      if(cycleDetected)
      {
        return true;
      }
    }
    else if(dfsVisited[neighbour]==true)                                         // agar unka visited bhi tru hua aur dfsvisite bhi true hua to matlab cycle present hai
    {
      return true;
    }
  }
  dfsVisited[node]=false;                                                       // agar koi aesa element nahi milta jinke dono visited aur dfsvisited true ho to vapis aate vakt element ke dfsvisited ko vapis se false mark kar denge
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++)                                 // ek adjacency list bana lenge
    {
      int u=edges[i].first;
      int v=edges[i].second;
      adj[u].push_back(v);
    }
    unordered_map<int,bool>visited;
    unordered_map<int,bool>dfsVisited;

    for(int i=0;i<=n;i++)
    {
      if(!visited[i])                                               // agar uss element ka visited true nahi hoga to uske lie call kar denge
      {
        bool cycleFound=checkCycle(i,visited,dfsVisited,adj);
        if(cycleFound)
        {
          return true;
        }
      }
    }
    return false;
}