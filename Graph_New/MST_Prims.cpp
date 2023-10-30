/*
harr node dursi node se reachable ho aur jo tree form ho vo minimum quantity ka ho that is uska weight ka sum minimum ho

isme 3 vectors lagenge 1. key 2. MST 3.Parent

key vale me value update karenge

mst vale me check karenge ki vo node already visited hai ya nahi

parent vale me parent store karenge

vector<pair<pair<int,int>,int>>calculateMST(int n,int m,vector<pair<pair<int,int>,int>>&g)
{
    unordered_map<int,list<pair<int,int>>>adjList;

    for(int i=0;i<g.size();i++)
    {
        int u=g[i].first.first;
        int v=g[i].first.second;
        int  w=g[i].second;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    vector<int>key(n+1);
    vector<bool>mst(n+1);
    vector<int>parent(n+1);
    for(int i=0;i<=n;i++)
    {
        key[i]=INT_MAX;
        mst[i]=-1;
        parent[i]=-1;
    }

    // source node ke key ko 0 mark kardo aur uske parent ko -1
    key[1]=0;
    parent[key]=-1;

    for(int i=1;i<n;i++)
    {
        int mini=INT_MIN;
        int u;
        
        // we can improve time complexity by    using min priority queue to find minimum node
        // finding the minimum node from key vector whose mst is false that is it is not yeh visited
        for(int v=1;v<=n;v++)                                   
        {
            if([mst[v]]==false && key[v]<mini)
            {
                u=v;                                    // minimum value vala node nikal lia
                mini=key[v];                            // minimum value nikal li
            }   
        }
        // mark minimum node in mst as true
        mst[v]=true;

        // check adjacent nodes

        for(auto it: adj[u])
        {
            int v=it.first;                         // adjacent node nikal lia
            int w=it.second;                        // adjacent node ka weight nikal lia
            if(mst[v]==false    &&  w<key[v])        // agar adjacent node ka mst false ho aur uska weight less ho jo key[v] me hai
            {
                parent[v]=u;                           // node ka parent update kar denge
                key[v]=w;                               // node ki weight ki value update kar denge key vector me
            }
        }
    }
    vector<pair<pair<int,int>,int>>result;
    for(int i=2;i<=n;i++)
    {
        result.push_back({{parent[i],i},key[i]});
    }
    return result;

}

*/