// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
/*
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int visited[V]={0};
        visited[0]=1;
        queue<int>q;
        q.push(0);
        vector<int>res;
        while(!q.empty())
        {
            int frontNode=q.front();
            q.pop();
            res.push_back(frontNode);
            
            for(auto it:adj[frontNode])
            {
                if(!visited[it])
                {
                    visited[it]=1;
                    q.push(it);
                }
            }
            
        }
        return res;
    }
*/