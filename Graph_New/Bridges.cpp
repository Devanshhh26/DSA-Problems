/*

Bridges in graph can be defined as edges that if removed increase the number of components or make the graph disconnected


    1              5
    | \          / |
    |  \        /  |
    |   3------4   |                    the edge 3 to 4 is a bridge
    |  /        \  |
    | /          \ |
    2             6
            

void dfs(int node,int parent,int &timer,vector<int>&disc,vector<int>&low,vector<vector<int>>&result,unordered_map<int,list<int>>&adjList,unordered_map<int,bool>&vis)
{
    vis[node]=true;
    disc[node]=timer;
    low[node]=timer;
    timer++;
    for(auto neighbour:adjList[node])
    {
        if(neighbour==parent)
        {
            continue;
        }
        if(!vis[neighbour])
        {
            dfs(neighbour,node,timer,disc,low,result,adjList,vis);
            low[node]=min(low[node],low[neighbour]);

            // check for bridge
            if(low[neighbour]>disc[node])
            {
                vector<int>ans;
                ans.push_back(node);
                ans.push_back(neighbour);
                result.push_back(ans);
            }
            else{   
                // node already visited and not the parent
                // backedge
                low[node]=min(low[neighbour],disc[neighbour]);
            }
        }
    }   
}

vector<vector<int>>findBridges(vector<vector<int>>&edges,int v,int e)
{
    unordered_map<int,list<int>>adjList;
    for(int i=0;i<e;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int timer=0;
    int parent=-1;
    vector<int>disc(v);
    vector<int>low(v);
    unordered_map<int,bool>vis;
    vector<vector<int>>result;
    
    for(int i=0;i<v;i++)
    {
        disc[i]=-1;
        low[i]=-1;
    }

    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        {
            dfs(i,parent,timer,disc,low,result,adjList,vis);
        }
    }
    return result;

}


*/