// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

/*

basically hume 2 cheeze find karni hai 1. number of extra edges jisse hum connection bana sakte hai 2. number of connected components
agar number of extra edges zyada hui to matlab we have enough wire to connect all the components into 1 single component

number of extra edge hum kruskals algorithm se nikal sakte hai jab bhi 2 elements ke parent alag aate the kruskals me to hum unka rank ke basis pe union kar dete the
but agar uske parents same aa jae to iska matlab yeh hoga ki vo already connected hai aur yeh ek extra edge hai

number of connected components hum BFS ya DFS se bhi nikal sakte the but isme humne parent array se nikala hai
jo bhi element parent array me khudka hi parent hai vo ek seperate component hua that is if(parent[i]==i) num++;  

int findParent(vector<int>&parent,int node)
    {
        if(parent[node]==node)
        {
            return node;
        }
        return parent[node]=findParent(parent,parent[node]);
    }
    void unionSet(int u,int v,vector<int>&parent,vector<int>&rank)
    {
        u=findParent(parent,u);
        v=findParent(parent,v);
        if(rank[u]<rank[v])
        {
            parent[u]=v;
            rank[v]++;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
      vector<int>parent(n);
      vector<int>rank(n,0);
      for(int i=0;i<n;i++)
      {
        parent[i]=i;                        // har element ko khudka parent kar kar dia
      }
      int noOfExtraEdges=0;
      for(auto connection:connections)
      {
          int u=connection[0];
          int v=connection[1];
          u=findParent(parent,u);
          v=findParent(parent,v);
          if(u!=v)                          // agar 2 elements ke parents same nahi hue to
          {
              unionSet(u,v,parent,rank);
          }
          if(u==v)                          // agar unke parents same hue to matlab extra edge hai
          {
              noOfExtraEdges++;
          }
      }
      int noOfConnectedComp=0;              // parent array ke through number of connected components nikal lie
      for(int i=0;i<n;i++)
      {
          if(parent[i]==i)
          {
              noOfConnectedComp++;
          }
      }
      int ans=noOfConnectedComp-1;          // agar 2 connected components ko apas me connect karna ho to 1 wire lagegi similarly agar 3 ko karna ho to 2 lagegi therefore n-1 wire lagenge
      if(noOfExtraEdges>= ans)              // agar extra edge ka count zyada ho component ke count -1 se
      {
          return ans;                       
      }
      return -1;                            // agar extra edges kam ho to
    }

*/