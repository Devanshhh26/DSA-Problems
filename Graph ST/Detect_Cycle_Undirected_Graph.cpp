/*
 private:
  bool detect(int src,vector<int>adj[],int vis[])
  {
      vis[src]=1;
      queue<pair<int,int>>q;                    // q me source aur uska parent daal denge, starting me source 1 aur parent -1 hai 
      q.push({src,-1});
      while(!q.empty())
      {
          int node=q.front().first;             // src element nikal lia
          int parent=q.front().second;          // parent nikal lia
          q.pop();
          for(auto adjacentNode: adj[node])     // ab src element ke saare neighbouring elements ko traverse kia
          {
              if(!vis[adjacentNode])            //agar vo unvisited hai to uske visited array me 1 kar do
              {
                  vis[adjacentNode]=1;
                  q.push({adjacentNode,node});  // aur fir use bhi q me push kardo 
              }
              else if(parent!=adjacentNode)        // agat neighbouring element visited hai aur vo parent element bhi nahi hai to iska matlab cycle hai
              {
                  return true;
              }
          }
      }
    return false;
      
  }
  public:
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        for(int i=0;i<V;i++)                    // to counter if the graph is divided into multiple components
        {
            if(!vis[i])
            {
                if(detect(i,adj,vis))
                {
                    return true;
                }
            }
        }
        return false;
    }
*/