//https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

/*
    void dfs(int node,vector<int>adj[],int vis[],vector<int>&ls)
    {
        vis[node]=1;
        ls.push_back(node);
        for(auto it:adj[node])
        {   if(!vis[it])
                dfs(it,adj,vis,ls);
        }
    }
    
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int visited[V]={0};
        int start=0;
        vector<int>ls;
        dfs(start,adj,visited,ls);
        return ls;
    }
*/