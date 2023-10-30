/*

1.topological sort nikal lo
2.ek distance vector bana lo aur weigh ke basis me use update karte raho
3. end me distance vector mil jaega from source

class Graph{
    public:
    unordered_map<int,list<pair<int,int>>>adjList;

    void addEdge(int u,int v,int weight)
    {
        pair<int,int>p=make_pair(v,weight);
        adj[u].push_back)(p);
    }
    void printAdj()
    {
        for(auto i:adj)
        {
            cout<<i.first<<" -> ";
            for(auto j:i.second)
            {
                cout<<"("j.first<<","<<j.second<<"),";
            }cout<<endl;
        }
    }
    void topoSort(int node,vector<bool>&visited,stack<int>&st)
    {
        visited[node]=true;
        for(auto neighbour:adjList[node])
        {
            if(!visited[neighbour.first])
            {
                topoSort(neightbour.first,visited,stack);
            }
        }
        st.push(node);
    }

    void getShortestPath(int src,vector<int>&dist,stack<int> &st)
    {
        dist[src]=0;              // source ke distance ko 0 kardo
        while(!st.empty)            
        {
            int top=st.top();
            st.pop();
            if(dist[top]!=INT_MAX)          // agar current element ki value distance vector me infinity nahi hai to uske neigbours ko update karo
            {
                for(auto i:adjList[top])
                {
                    if(dist[top]+i.second<dist[i.first])            // agar distance array me neighbour ka jo distance hai vo bada hai current element ke weight aur neighbour ke weight ke sum se to hum update kar denge use sum se 
                    {
                        dist[i.first]=dist[top]+i.second;
                    }
                }
            }
        }
    }

}


int main()
{
    Graph g;
    g.add(0,1,5);
    g.add(0,2,3);
    g.add(1,2,2);
    g.add(1,3,6);
    g.add(2,3,7);
    g.add(2,4,4);
    g.add(2,5,2);
    g.add(3,4,-1);
    g.add(4,5,-2);

    g.printAdj();

    int n=6;
    
    // topological sort
   
    vector<bool>visited;
    stack<int>st;
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            g.topoSort(i,visited,st);
        }
    }
    int src=1;

    // distance vector ke har index me infinity daal do
    vector<int>dist(n);
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
    }


    g.getShortestPath(src,dist,st);


    cout<<"Answer is"<<endl;

    for(int i=0;i<dist.size();i++)
    {
        cout<<dist[i]<<endl;
    }
    return 0;

*/